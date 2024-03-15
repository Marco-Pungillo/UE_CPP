// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "DummySaveGame.generated.h"

USTRUCT(BlueprintType)
struct FPlayerSaveData {
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite)
	FVector PlayerLocation;
	UPROPERTY(BlueprintReadWrite)
	FVector PlayerScale;
	UPROPERTY(BlueprintReadWrite)
	FRotator PlayerRotator;
	UPROPERTY(BlueprintReadWrite)
	FColor PlayerColor;
};

USTRUCT(BlueprintType)
struct FActorSaveData {
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FVector ActorLocation;
	UPROPERTY(BlueprintReadWrite)
	FVector ActorScale;
	UPROPERTY(BlueprintReadWrite)
	FRotator ActorRotator;
	UPROPERTY(BlueprintReadWrite)
	float ActorSpeed;
};

USTRUCT(BlueprintType)
struct FPawnSaveData {
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FVector PawnLocation;
	UPROPERTY(BlueprintReadWrite)
	FVector PawnScale;
	UPROPERTY(BlueprintReadWrite)
	FRotator PawnRotator;
	UPROPERTY(BlueprintReadWrite)
	TArray<FVector> PawnTargets;
};

/**
 * 
 */
UCLASS()
class CPPEXERCISE_API UDummySaveGame : public USaveGame
{
	GENERATED_BODY()


	public:
		UPROPERTY(BlueprintReadWrite)
		FPlayerSaveData PlayerSaveData;
		UPROPERTY(BlueprintReadWrite)
		FActorSaveData ActorSaveData;
		UPROPERTY(BlueprintReadWrite)
		FPawnSaveData PawnSaveData;
		


		UDummySaveGame();

};
