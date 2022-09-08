// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDamagedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDeadDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANTRUMN_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	FDamagedDelegate OnDamaged;
	FDeadDelegate OnDead;

	// Sets default values for this component's properties
	UHealthComponent();
	bool IsDead() { return CurrentHealth <= FLT_EPSILON; }

	void TakeDamage(float Damage) {
		CurrentHealth -= Damage;
		OnDamaged.Broadcast();

		if (IsDead()) {
			OnDead.Broadcast();
		}
	}

	const float GetCurrentHealth() const { return CurrentHealth; }

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		float MaxHealth = 100.f;

	float CurrentHealth = MaxHealth;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
