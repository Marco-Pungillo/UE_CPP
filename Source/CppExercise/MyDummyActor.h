// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DummyInterface.h"
#include "TriggerInterface.h"
#include "MyDummyActor.generated.h"


DECLARE_DYNAMIC_DELEGATE(FDummyDelegate);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDummyDelegateOneParam,int32,testparam);
DECLARE_DYNAMIC_DELEGATE_RetVal_OneParam(bool, FDummyDelegateOneParamRetVal,int32,testParam);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMulticastTest);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMulticastOneParamTest, int32, testparam);
UCLASS(Blueprintable)
class CPPEXERCISE_API AMyDummyActor : public AActor, public IDummyInterface, public ITriggerInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyDummyActor();

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="TestEvent")
	FDummyDelegate OnTestDummyEvent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestEvent")
	FDummyDelegateOneParam OnTestDummyEventOneParam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestEvent")
	FDummyDelegateOneParamRetVal OnTestDummyEventOneParamRetVal;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FMulticastTest OnMulticastTestEvent;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FMulticastOneParamTest OnMulticastOneParamTestEvent;


	UFUNCTION(BlueprintCallable)
	void TestFunction();

	UFUNCTION(BlueprintCallable)
	void TestFunctionOnePar(int32 testparam);

	UFUNCTION(BlueprintImplementableEvent)
	void BlueprintImplementableFunctionOneParam(int32 testparam);

	UFUNCTION(BlueprintImplementableEvent)
	void BlueprintImplementableFunction();

	UFUNCTION(BlueprintCallable)
	bool TestFunctionOneParRetVal(int32 testparam);

	UFUNCTION(BlueprintCallable)
	void TriggerEvents();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual bool DummyInterfaceFunction() override;

	bool DummyBlueprintNative_Implementation() override;

	virtual bool ReactToTrigger() override;
};
