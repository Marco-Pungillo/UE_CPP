// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TriggerInterface.h"
#include "MyDummyPawn.generated.h"

UCLASS()
class CPPEXERCISE_API AMyDummyPawn : public APawn, public ITriggerInterface
{
	GENERATED_BODY()


public:

	// Sets default values for this pawn's properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> Targets;

	UFUNCTION(BlueprintCallable)
	void GenerateTargets(float radius,int32 numTarget);
	AMyDummyPawn();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 TriggerIndex;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual bool ReactToTrigger() override;
};
