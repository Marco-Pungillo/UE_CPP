// Fill out your copyright notice in the Description page of Project Settings.

#include "AIFSMComponent.h"

// Sets default values for this component's properties
UAIFSMComponent::UAIFSMComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAIFSMComponent::BeginPlay()
{
	Super::BeginPlay();

	TSet<UActorComponent*> OwnerComponents;
	OwnerComponents = GetOwner()->GetComponents();
	for (UActorComponent* component : OwnerComponents) 
	{
		UFSMStateComponent* StateComponent = Cast<UFSMStateComponent>(component);
		if (StateComponent) 
		{
			RegisterState(StateComponent->StateType, StateComponent);
		}
	}
	
}


void UAIFSMComponent::RegisterState(EFSMState StateType, UFSMStateComponent* State)
{
	StateComponents.Add(StateType, State);
}

// Called every frame
void UAIFSMComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	switch (CurrentState) {
		case EFSMState::Patrol:
			break;
		case EFSMState::Chase:
			break;
		case EFSMState::Attack:
			break;
		default:
			break;
	}
}

void UAIFSMComponent::ChangeState(EFSMState NextState)
{
	UFSMStateComponent* CurrentStateComponent = StateComponents[CurrentState];
	CurrentStateComponent->ExitState();
	CurrentState = NextState;
	CurrentStateComponent = StateComponents[CurrentState];
	CurrentStateComponent->EnterState();
}

void UAIFSMComponent::OnRegister()
{
	Super::OnRegister();
	APawn* PawnOwner = Cast<APawn>(GetOwner());
	if (!PawnOwner)
	{
		UE_LOG(LogTemp, Warning, TEXT("State Machines ca only be attached to a PawnActor"));
		UnregisterComponent();
	}
}

