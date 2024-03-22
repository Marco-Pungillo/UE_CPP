// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformerGameModeBase.h"

void APlatformerGameModeBase::SpawnandPosses()
{
	FString PawnPath = TEXT("/Game/BP_PlatformerPawn.BP_PlatformerPawn_C");
	UClass* PawnClass = LoadClass<UClass>(nullptr, *PawnPath);
	if (PawnClass) 
	{
		APawn* NewPawn=GetWorld()->SpawnActor<APawn>(PawnClass);
		if (NewPawn) 
		{
			GetWorld()->GetFirstPlayerController()->Possess(NewPawn);
		}
	}
}
