// Fill out your copyright notice in the Description page of Project Settings.


#include "FSMPawn.h"

// Sets default values
AFSMPawn::AFSMPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PatrolComponent = CreateDefaultSubObject<UPatrolStateComponent>(TEXT("PatrolStateComponent"));

}

// Called when the game starts or when spawned
void AFSMPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFSMPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFSMPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

