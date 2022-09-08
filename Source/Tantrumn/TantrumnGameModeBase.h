// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TantrumnGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TANTRUMN_API ATantrumnGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ATantrumnGameModeBase();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
		TSubclassOf<class UUserWidget> WidgetTemplate;

	UPROPERTY()
		UUserWidget* WidgetInstance;

		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;
};
