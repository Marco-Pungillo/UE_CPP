// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSMStateComponent.h"
#include "Engine/TargetPoint.h"
#include "PatrolStateComponent.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class CPPEXERCISE_API UPatrolStateComponent : public UFSMStateComponent
{
	GENERATED_BODY()
	
public:
	UPatrolStateComponent();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<class ATargetPoint*> TargetPoints;

	void EnterState() override;
	void ExitState() override;
	void PlayState() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PatrolRange = 1000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MinimumPatrolTargets = 3;

	void GenerateTargetPoints(float Range);
	AActor* GetNextActorToPatrol();
};
