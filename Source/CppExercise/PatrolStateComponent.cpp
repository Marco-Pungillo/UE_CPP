// Fill out your copyright notice in the Description page of Project Settings.

#include "PatrolStateComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/TargetPoint.h"
#include "AIController.h"


UPatrolStateComponent::UPatrolStateComponent()
{
	StateType = EFSMState::Patrol;
}

void UPatrolStateComponent::EnterState()
{
	GenerateTargetPoints(PatrolRange);
}

void UPatrolStateComponent::ExitState()
{
	
}

void UPatrolStateComponent::PlayState()
{
	APawn* PawnOwner = Cast<APawn>(GetOwner());
	if (PawnOwner)
	{
		/*AIC = Cast<AAIController>(PawnOwner->GetController());

		if (AIController) 
		{
			AIController->MoveToActor();
		}*/
	}
}

void UPatrolStateComponent::GenerateTargetPoints(float Range)
{
	TargetPoints.Empty();

	TArray<AActor*> AllTargets;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), AllTargets);

	for (AActor* Target : AllTargets)
	{
		FVector OwnerLocation = GetOwner()->GetActorLocation();
		FVector TargetLocation = Target->GetActorLocation();
		if (FVector::Distance(OwnerLocation, TargetLocation) < PatrolRange)
		{
			TargetPoints.Add(Cast<ATargetPoint>(Target));
		}
	}

	if (TargetPoints.Num() < MinimumPatrolTargets) 
	{
		GenerateTargetPoints(Range * 2);
	}
}

AActor* UPatrolStateComponent::GetNextActorToPatrol()
{
	return nullptr;
}

