// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/MovementComponent.h"
#include "MyMovementComponent.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class CPPEXERCISE_API UMyMovementComponent : public UMovementComponent
{
	GENERATED_BODY()
	
public:
	void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* TickFunction) override;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	bool bIsGrounded;
	bool bCannotMoveForward = false;
	bool bCannotMoveBackward = false;

	UFUNCTION(BlueprintCallable)
	void MoveForwardRight(FVector2D InputAxis);

};
