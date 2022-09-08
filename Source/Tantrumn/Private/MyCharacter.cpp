// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HealthComponent = CreateDefaultSubobject<UHealthComponent>("HealthComponent");

	HealthComponent->OnDamaged.AddDynamic(this, &AMyCharacter::OnDamageTaken);
	HealthComponent->OnDead.AddDynamic(this, &AMyCharacter::OnDead);
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

const bool AMyCharacter::IsAlive() const
{
	if (HealthComponent) {
		return !HealthComponent->IsDead();
	}
	return false;
}

const float AMyCharacter::GetCurrentHealth() const
{
	if (HealthComponent) {
		return HealthComponent->GetCurrentHealth();
	}
	return 0.f;
}

