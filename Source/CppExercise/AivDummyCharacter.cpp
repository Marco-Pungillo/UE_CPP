// Fill out your copyright notice in the Description page of Project Settings.


#include "AivDummyCharacter.h"

// Sets default values
AAivDummyCharacter::AAivDummyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAivDummyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAivDummyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult Result;

	UWorld* World = GetWorld();
	FVector StartPoint = GetActorLocation();
	FVector EndPoint = GetActorForwardVector() * 1000;

	DrawDebugLine(GetWorld(), StartPoint, EndPoint, FColor::Green);

	bool bHasHit = World->LineTraceSingleByChannel(Result, StartPoint, EndPoint, ECollisionChannel::ECC_Visibility);

	if (bHasHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *Result.GetActor()->GetName());
		IDummyInterface* InterfaceCast = Cast<IDummyInterface>(Result.GetActor());
		if (InterfaceCast)
		{
			InterfaceCast->DummyInterfaceFunction();
		}
	}
}

// Called to bind functionality to input
void AAivDummyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool AAivDummyCharacter::DummyInterfaceFunction()
{
	Jump();
	UE_LOG(LogTemp, Warning, TEXT("DummyInterfaceFunction called from character"));
	return true;
}

