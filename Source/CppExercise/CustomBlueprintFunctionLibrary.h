// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h" 
#include "DummyInterface.h"

#include "CustomBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class CPPEXERCISE_API UCustomBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	static FVector GetActorWorldLocationOld(AActor* Actor);

	UFUNCTION(BlueprintCallable)
	static bool GetActorWorldLocation(AActor* Actor, FVector& Location);

	UFUNCTION(BlueprintCallable)
	static bool GetActorWorldLocationAndName(AActor* Actor, FVector& Location,FString& Name);

	UFUNCTION(BlueprintCallable)
	static bool SetActorWorldLocation(AActor* Actor,FVector Location);

	UFUNCTION(BlueprintCallable)
	static FVector GetActorScale3D(AActor* Actor);

	UFUNCTION(BlueprintCallable)
	static bool SetActorScale3D(AActor* Actor, FVector Scale);

	UFUNCTION(BlueprintCallable)
	static FRotator GetActorWorldRotation(AActor* Actor);

	UFUNCTION(BlueprintCallable)
	static bool SetActorWorldRatation(AActor* Actor, FRotator Rotation);

	UFUNCTION(BlueprintCallable)
	static bool CharacterJump(ACharacter* Character);
	
	UFUNCTION(BlueprintCallable)
	static bool CharacterDubleJump(ACharacter* Character,bool bCanDoubleJump, bool& bOutCanDoubleJump,float LaunchForce = 1000);

	UFUNCTION(BlueprintCallable)
	static bool SetDynamicMaterial(ACharacter* Character, UMaterial* Material,int32 MaterialIndex);

	UFUNCTION(BlueprintCallable)
	static bool ChangeCharacterColor(ACharacter* Character, FName ParameterName, FVector4 Color, int32 MaterialIndex);

	UFUNCTION(BlueprintCallable)
	static bool ChangeCharacterTexture(ACharacter* Character, FName ParameterName, UTexture* Texture, int32 MaterialIndex);

	UFUNCTION(BlueprintCallable)
	static void BindInput(ACharacter* Character);

	UFUNCTION(BlueprintCallable)
	static bool CallInterfaceFunction(UObject* Object);

	UFUNCTION(BlueprintCallable)
	static bool CallDummyInterface(TScriptInterface<IDummyInterface> Interface);

	UFUNCTION(BlueprintCallable)
	static bool LoadGame(UWorld* world, FString SlotName, int32 UserIndex);

	UFUNCTION(BlueprintCallable)
	static bool SaveGame(UWorld* world, FString SlotName, int32 UserIndex);

	UFUNCTION(BlueprintCallable)
	static bool SpawnandPosses(UWorld* InWorld, UClass* ClassToSpawn,APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable)
	static bool RayCastFromActor(AActor* InActor, FVector StartPoint, FVector EndPoint);

	UFUNCTION(BlueprintCallable)
	static bool RayCastFromPoint(ULevel* InLevel, FVector StartPoint, FVector EndPoint);
};
