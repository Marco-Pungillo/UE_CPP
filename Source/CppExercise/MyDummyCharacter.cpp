// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDummyCharacter.h"

// Sets default values
AMyDummyCharacter::AMyDummyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Colors.Add(FColor::Black);
	Colors.Add(FColor::Emerald);
	Colors.Add(FColor::Magenta);

}

void AMyDummyCharacter::FunctionNoPar()
{
	UE_LOG(LogTemp, Warning, TEXT("No Param Function"));
}

void AMyDummyCharacter::FunctionFloat(float param)
{
	UE_LOG(LogTemp, Warning, TEXT(" Function Param : %f"),param);
}

// Called when the game starts or when spawned
void AMyDummyCharacter::BeginPlay()
{
	Super::BeginPlay();
	UMaterial* Material = LoadObject<UMaterial>(nullptr, TEXT("/Game/Custom/M_CustomMaterial.M_CustomMaterial"));
	UCustomBlueprintFunctionLibrary::SetDynamicMaterial(this, Material, 0);

}

// Called every frame
void AMyDummyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyDummyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction(FName("Jump"), EInputEvent::IE_Pressed, this, &AMyDummyCharacter::FunctionNoPar);
	PlayerInputComponent->BindAxis(FName(""),this,&AMyDummyCharacter::FunctionFloat);
}

bool AMyDummyCharacter::ReactToTrigger()
{
	CurrentColorIndex++;
	if (CurrentColorIndex >= Colors.Num())
	{
		CurrentColorIndex = 0;
	}

	FColor CurrentColor = Colors[CurrentColorIndex];

	UCustomBlueprintFunctionLibrary::ChangeCharacterColor(this, FName("CustomColor"), FVector4(CurrentColor), 0);

	return true;
}