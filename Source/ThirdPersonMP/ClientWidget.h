// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ClientWidget.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONMP_API UClientWidget : public UUserWidget
{
	GENERATED_BODY()
	

public:

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	class UTextBlock* HealthText;

	void SetClientText(FString NewText);
};
