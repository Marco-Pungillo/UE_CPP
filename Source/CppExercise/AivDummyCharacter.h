// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DummyInterface.h"
#include "AivDummyCharacter.generated.h"

UCLASS()
class CPPEXERCISE_API AAivDummyCharacter : public ACharacter, public IDummyInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAivDummyCharacter();
	UFUNCTION(BlueprintCallable)
	bool MultiRayCast(FVector StartPoint, FVector EndPoint, ECollisionChannel CollisionChannel);
	UFUNCTION(BlueprintCallable)
	bool OverlapSphere(FVector StartPoint, FVector EndPoint, ECollisionChannel CollisionChannel);
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float SweepDistance = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Radius = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AActor*> ActorsToIgnore;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual bool DummyInterfaceFunction() override;

};
