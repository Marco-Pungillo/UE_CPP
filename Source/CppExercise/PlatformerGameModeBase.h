// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PlatformerGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CPPEXERCISE_API APlatformerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	void SpawnandPosses();
	
};
