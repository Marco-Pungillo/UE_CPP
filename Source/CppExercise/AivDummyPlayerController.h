// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DummyInterface.h"
#include "AivDummyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CPPEXERCISE_API AAivDummyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite)
	TScriptInterface<IDummyInterface> DummyInterfaceInstance;
	 
	virtual void OnPossess(APawn* InPawn) override;
};
