// Fill out your copyright notice in the Description page of Project Settings.


#include "ThirdPersonMPPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "ClientWidget.h"
#include "ThirdPersonMPCharacter.h"

void AThirdPersonMPPlayerController::CreateMyClientWidget()
{
	if (IsLocalPlayerController())
	{
		MyClientWidget = CreateWidget<UClientWidget>(this, ClientWidgetClass);
		MyClientWidget->AddToViewport();
	}

	//
}

void AThirdPersonMPPlayerController::BeginPlay()
{
	CreateMyClientWidget();
}

void AThirdPersonMPPlayerController::RefreshWidget()
{
	AThirdPersonMPCharacter* TPC = Cast<AThirdPersonMPCharacter>(GetPawn());
	if (TPC)
	{
		float health = TPC->GetCurrentHealth();
		MyClientWidget->SetClientText((FString::FromInt(health)));
	}
}
