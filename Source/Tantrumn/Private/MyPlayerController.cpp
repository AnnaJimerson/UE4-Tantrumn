// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "MyCharacter.h"

AMyPlayerController::AMyPlayerController()
{

}

void AMyPlayerController::BeginPlay()
{
	// Get Controlled Pawn
	OwnerPlayer = (AMyCharacter*)GetPawn();
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Bind Input Actions here
	if (InputComponent) {
		InputComponent->BindAction("Jump", IE_Pressed, this, &AMyPlayerController::InputJump);
		InputComponent->BindAxis("MoveForward", this, &AMyPlayerController::InputMoveForward);
		InputComponent->BindAxis("MoveRight", this, &AMyPlayerController::InputMoveRight);
		InputComponent->BindAxis("LookUp", this, &AMyPlayerController::InputLookUp);
		InputComponent->BindAxis("Turn", this, &AMyPlayerController::InputTurn);
	}
}

void AMyPlayerController::InputJump()
{
	// Tell player to jump
	if (OwnerPlayer)
		OwnerPlayer->Jump();
}

void AMyPlayerController::InputMoveForward(float amount)
{
	// Move Forward Back
	if (OwnerPlayer)
		OwnerPlayer->AddMovementInput(OwnerPlayer->GetActorForwardVector(), amount, false);
}

void AMyPlayerController::InputMoveRight(float amount)
{
	// Move Right Left
	if (OwnerPlayer)
		OwnerPlayer->AddMovementInput(OwnerPlayer->GetActorRightVector(), amount, false);
}

void AMyPlayerController::InputLookUp(float amount)
{
	// Camera Y-axis
	AddPitchInput(amount);
}

void AMyPlayerController::InputTurn(float amount)
{
	// Camera X-axis
	AddYawInput(amount);
}
