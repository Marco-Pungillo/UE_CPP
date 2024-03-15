// Fill out your copyright notice in the Description page of Project Settings.

#include "MyDummyPawn.h"
#include "Kismet/KismetMathLibrary.h"
#include "Math/UnrealMathUtility.h"


void AMyDummyPawn::GenerateTargets(float radius, int32 numTarget)
{
	Targets.Empty();
	for (size_t i = 0; i < numTarget; i++)
	{
		float RandAngle = UKismetMathLibrary::RandomFloatInRange(0, 359);
		RandAngle *= PI;
		RandAngle /= 180;
		double x = FMath::Sin(RandAngle);
		double y = FMath::Cos(RandAngle);
		float Rand = UKismetMathLibrary::RandomFloatInRange(0, radius);
		x *= Rand;
		y *= Rand;

		FVector RelativeTarget(x,y,0);

		FVector AbsoluteTarget = RelativeTarget + GetActorLocation();

		Targets.Add(AbsoluteTarget);
	}
}

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
	GenerateTargets(1000, 10);
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
	GenerateTargets(1000, 10);
	return false;
}