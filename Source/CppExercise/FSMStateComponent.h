// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FSMStateComponent.generated.h"

UENUM(BlueprintType)
enum class EFSMState {
	Patrol,
	Chase,
	Attack
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Abstract)
class CPPEXERCISE_API UFSMStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFSMStateComponent();
	EFSMState StateType;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	virtual void EnterState();

	UFUNCTION(BlueprintCallable)
	virtual void ExitState();

	UFUNCTION(BlueprintCallable)
	virtual void RegisterState();

	UFUNCTION(BlueprintCallable)
	virtual void PlayState();
};
