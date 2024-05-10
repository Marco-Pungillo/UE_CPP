// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FSMStateComponent.h"
#include "AIFSMComponent.generated.h"




UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class CPPEXERCISE_API UAIFSMComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAIFSMComponent();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EFSMState InitialState = EFSMState::Patrol;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	EFSMState CurrentState;
	TMap < EFSMState, UFSMStateComponent*> StateComponents;
	void RegisterState(EFSMState StateType, UFSMStateComponent* State);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	virtual void ChangeState(EFSMState NextState);

	UFUNCTION()
	virtual void OnRegister() override;
};
