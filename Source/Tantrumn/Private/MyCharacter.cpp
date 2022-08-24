// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyCharacter::Jump()
{
	// Jump action
	Super::Jump();
}

void AMyCharacter::MoveForward(float amount)
{
	// Move Forward Back
	AddMovementInput(GetActorForwardVector(), amount, false);
}

void AMyCharacter::MoveRight(float amount)
{
	// Move Right Left
	AddMovementInput(GetActorRightVector(), amount, false);
}


