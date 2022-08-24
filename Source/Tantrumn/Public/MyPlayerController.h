// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

class AMyCharacter;
/**
 * 
 */
UCLASS()
class TANTRUMN_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
public:
	// Constructor
	AMyPlayerController();

	// Input Component Setup
	virtual void SetupInputComponent() override;

	UPROPERTY()
		class AMyCharacter* OwnerPlayer;

	void InputJump();
	void InputMoveForward(float amount);
	void InputMoveRight(float amount);
	void InputLookUp(float amount);
	void InputTurn(float amount);
};
