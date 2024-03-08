// Fill out your copyright notice in the Description page of Project Settings.


#include "AivDummyPlayerController.h"

void AAivDummyPlayerController::OnPossess(APawn* InPawn)
{
	if (InPawn)
	{
		Super::OnPossess(InPawn);
		bool bResult = InPawn->Implements<UDummyInterface>();
		if (bResult)
		{
			IDummyInterface* Interface = Cast<IDummyInterface>(InPawn);
			if (Interface)
			{
				DummyInterfaceInstance.SetInterface(Interface);
				DummyInterfaceInstance.SetObject(InPawn);
			}
			else
			{
				DummyInterfaceInstance = nullptr;
			}
		}
		else
		{
			DummyInterfaceInstance = nullptr;
		}
	}
}