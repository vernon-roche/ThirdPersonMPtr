// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "ThirdPersonMPGameMode.h"
#include "ThirdPersonMPCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"
#include "TimerManager.h"

AThirdPersonMPGameMode::AThirdPersonMPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AThirdPersonMPGameMode::SetPlayrToRespawn(AController * Pc)
{
	RespawningPlayer = Pc;

	GetWorld()->GetTimerManager().SetTimer(WaitToRespwanTimer, this, &AThirdPersonMPGameMode::Respawn, 3.0f, false);
}

void AThirdPersonMPGameMode::Respawn()
{

	FVector spawnLocation(0.0f, 0.0f, 500.0f);
	FRotator spawnRotation(0.0f);

	FActorSpawnParameters spawnParameters;
	spawnParameters.Instigator = Instigator;
	spawnParameters.Owner = this;

	AThirdPersonMPCharacter* NewCharacter = GetWorld()->SpawnActor<AThirdPersonMPCharacter>(CharacterClass, spawnLocation, spawnRotation, spawnParameters);

	RespawningPlayer->Possess(NewCharacter);
}
