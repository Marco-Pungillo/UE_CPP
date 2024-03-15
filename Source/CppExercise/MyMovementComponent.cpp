// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMovementComponent.h"

void UMyMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* TickFunction) {
	Super::TickComponent(DeltaTime, TickType, TickFunction);

	const FVector Gravity = { 0,0,-9.81f };

	Velocity += Gravity;
	FHitResult Hit;

	bIsGrounded = false;

	//UE_LOG(LogTemp, Warning, TEXT("%s"), *Velocity.ToString());

	if (!SafeMoveUpdatedComponent(Velocity * DeltaTime, FRotator::ZeroRotator, true, Hit))
	{
		FVector CompenetrationCorrection = GetPenetrationAdjustment(Hit);
		UE_LOG(LogTemp, Warning, TEXT("Compenetration: %s"), *CompenetrationCorrection.ToString());
		ResolvePenetration(CompenetrationCorrection, Hit, UpdatedComponent->GetComponentQuat());
		Velocity.X = 0;		//only for gravity
		Velocity.Y = 0;
		if (Hit.Normal.Z > 0)
		{
			Velocity.Z = 0;
			this->bIsGrounded=true;
		}

	}
}

void UMyMovementComponent::MoveForwardRight(FVector2D InputAxis) {
	FVector MoveDirection = UpdatedComponent->GetForwardVector() * InputAxis.X * 500;
	MoveDirection += UpdatedComponent->GetRightVector()* InputAxis.Y * 500;
	MoveDirection.Z = Velocity.Z;
	Velocity = MoveDirection;

}






