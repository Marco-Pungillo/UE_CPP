// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PatrolStateComponent.h"
#include "FSMPawn.generated.h"

UCLASS(Blueprintable)
class CPPEXERCISE_API AFSMPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AFSMPawn();

	UPROPERTY()
	EFSMState PatrolComponent;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
