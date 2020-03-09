// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ThirdPersonMPGameMode.generated.h"

UCLASS(minimalapi)
class AThirdPersonMPGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AThirdPersonMPGameMode();

	class AController* RespawningPlayer;

	FTimerHandle WaitToRespwanTimer;

	void SetPlayrToRespawn(AController* Pc);

	UFUNCTION()
		void Respawn();

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class AThirdPersonMPCharacter> CharacterClass;
};



