// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "DummySaveGame.generated.h"

/**
 * 
 */
UCLASS()
class CPPEXERCISE_API UDummySaveGame : public USaveGame
{
	GENERATED_BODY()
	public:
		UPROPERTY(BlueprintReadWrite)
		FVector PlayerLocation;
		UPROPERTY(BlueprintReadWrite)
		FVector PlayerScale;
		UPROPERTY(BlueprintReadWrite)
		FRotator PlayerRotator;
		UPROPERTY(BlueprintReadWrite)
		FColor PlayerColor;

		UDummySaveGame();

};
