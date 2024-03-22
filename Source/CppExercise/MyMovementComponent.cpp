// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMovementComponent.h"

void UMyMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* TickFunction) {
	Super::TickComponent(DeltaTime, TickType, TickFunction);

	const FVector Gravity = { 0,0,-9.81f };

	if (!this->bIsGrounded)
	{
		Velocity += Gravity;
	}
	
	FHitResult Hit;

	bIsGrounded = false;

	if (this->bCannotMoveForward && Velocity.X < 0)
	{
		this->bCannotMoveForward = false;
	}
	if (this->bCannotMoveBackward && Velocity.X > 0)
	{
		this->bCannotMoveBackward = false;
	}

	//bCannotMoveForward = false;
	//bCannotMoveBackward = false;

	//UE_LOG(LogTemp, Warning, TEXT("%s"), *Velocity.ToString());

	if (!SafeMoveUpdatedComponent(Velocity * DeltaTime, FRotator::ZeroRotator, true, Hit))
	{
		FVector CompenetrationCorrection = GetPenetrationAdjustment(Hit);
		UE_LOG(LogTemp, Warning, TEXT("Compenetration: %s"), *CompenetrationCorrection.ToString());
		ResolvePenetration(CompenetrationCorrection, Hit, UpdatedComponent->GetComponentQuat());
		//Velocity.X = 0;		//only for gravity
		//Velocity.Y = 0;
		if (Hit.Normal.Z > 0)
		{
			Velocity.Z = 0;
			this->bIsGrounded=true;
		}
		if (Hit.Normal.X < 0)
		{
			Velocity.X = 0;
			bCannotMoveForward = true;
		}
		if (Hit.Normal.X > 0)
		{
			Velocity.X = 0;
			bCannotMoveBackward = true;
		}
		if (Hit.Normal.Y < 0)
		{
			Velocity.Y = 0;
		}
	}

	this->Velocity.X = 0;
	this->Velocity.Y = 0;
}


void UMyMovementComponent::MoveForward(float Input) 
{
	FVector MoveDirection = UpdatedComponent->GetForwardVector() * Input * 500;
	
	MoveDirection.Z = Velocity.Z;
	if (this->bCannotMoveForward && MoveDirection.X > 0)
	{
		MoveDirection.X = 0;
	}
	if (this->bCannotMoveBackward && MoveDirection.X < 0)
	{
		MoveDirection.X = 0;
	}
	this->Velocity += MoveDirection;
}

void UMyMovementComponent::MoveRight(float Input)
{
	FVector MoveDirection = UpdatedComponent->GetRightVector() * Input * 500;

	MoveDirection.Z = Velocity.Z;
	if (this->bCannotMoveForward && MoveDirection.X > 0)
	{
		MoveDirection.X = 0;
	}
	if (this->bCannotMoveBackward && MoveDirection.X < 0)
	{
		MoveDirection.X = 0;
	}
	this->Velocity += MoveDirection;
}





