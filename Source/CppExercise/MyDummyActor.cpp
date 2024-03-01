// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDummyActor.h"

// Sets default values
AMyDummyActor::AMyDummyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	OnTestDummyEvent.BindUFunction(this, FName("TestFunction"));
	OnTestDummyEventOneParam.BindUFunction(this, FName("TestFunctionOnePar"));
	OnTestDummyEventOneParamRetVal.BindUFunction(this, FName("TestFunctionOneParRetVal"));
	OnMulticastTestEvent.AddDynamic(this, &AMyDummyActor::BlueprintImplementableFunction);
	OnMulticastOneParamTestEvent.AddDynamic(this, &AMyDummyActor::BlueprintImplementableFunctionOneParam);
}

void AMyDummyActor::TestFunction()
{
	UE_LOG(LogTemp,Warning,TEXT("Test event"))
}

void AMyDummyActor::TestFunctionOnePar(int32 testparam)
{
	UE_LOG(LogTemp, Warning, TEXT("Test event with value : %d"), testparam);
}

bool AMyDummyActor::TestFunctionOneParRetVal(int32 testparam)
{
	UE_LOG(LogTemp, Warning, TEXT("Test event with value : %d"), testparam);
	return true;
}

void AMyDummyActor::TriggerEvents()
{
	OnTestDummyEvent.Execute();
	OnTestDummyEventOneParam.Execute(10);
	OnTestDummyEventOneParamRetVal.Execute(100);
	OnMulticastTestEvent.Broadcast();
	OnMulticastOneParamTestEvent.Broadcast(25);
}

// Called when the game starts or when spawned
void AMyDummyActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyDummyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

