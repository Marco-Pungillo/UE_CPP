// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDummyPawn.h"

// Sets default values
AMyDummyPawn::AMyDummyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyDummyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyDummyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyDummyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool AMyDummyPawn::ReactToTrigger()
{


	return false;
}