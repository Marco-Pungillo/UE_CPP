// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformerPawn.h"

// Sets default values
APlatformerPawn::APlatformerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->MovementComponentInstance = CreateDefaultSubobject<UMyMovementComponent>(TEXT("PlatformerMovementComponent"));
	this->SkeletalMeshComponentInstance = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PlatformerSkeletalMeshComponent"));
	
}

// Called when the game starts or when spawned
void APlatformerPawn::BeginPlay()
{
	Super::BeginPlay();
	FString SkeletalMeshPath = "/Game/Meshes/SM_PlatformMesh.SM_PlatformMesh";
	USkeletalMesh* Mesh = LoadObject<USkeletalMesh>(nullptr, *SkeletalMeshPath);
	if (Mesh)
	{
		this->SkeletalMeshComponentInstance->SetSkeletalMesh(Mesh);
	}
}

// Called every frame
void APlatformerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlatformerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &APlatformerPawn::PlatformerPawnMoveForward);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &APlatformerPawn::PlatformerPawnMoveRight);
}

void APlatformerPawn::PlatformerPawnMoveForward(float Input)
{
	MovementComponentInstance->MoveForward(Input);
}

void APlatformerPawn::PlatformerPawnMoveRight(float Input)
{
	MovementComponentInstance->MoveRight(Input);
}