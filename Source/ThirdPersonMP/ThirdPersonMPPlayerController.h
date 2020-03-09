// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ThirdPersonMPPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONMP_API AThirdPersonMPPlayerController : public APlayerController
{
	GENERATED_BODY()
	

public:

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class UClientWidget> ClientWidgetClass;

	class UClientWidget* MyClientWidget;

	void CreateMyClientWidget();

	void BeginPlay() override;

	void RefreshWidget();
};
