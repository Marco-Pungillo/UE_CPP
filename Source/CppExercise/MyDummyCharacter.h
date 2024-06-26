// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TriggerInterface.h"
#include "CustomBlueprintFunctionLibrary.h"
#include "MyDummyCharacter.generated.h"

UCLASS()
class CPPEXERCISE_API AMyDummyCharacter : public ACharacter, public ITriggerInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyDummyCharacter();

	UFUNCTION(BlueprintCallable)
	void FunctionNoPar();
	
	UFUNCTION(BlueprintCallable)
	void FunctionFloat(float param);

	UPROPERTY(BlueprintReadWrite)
	TArray<FColor> Colors;

	int32 CurrentColorIndex = 0;

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
