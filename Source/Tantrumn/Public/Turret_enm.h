// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.h"
#include "Particles/ParticleSystem.h"
#include "Turret_enm.generated.h"

UCLASS()
class TANTRUMN_API ATurret_enm : public AMyCharacter
{
	GENERATED_BODY()

private:
	FTimerHandle shootTimer;

public:
	// Sets default values for this character's properties
	ATurret_enm();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Target")
		ACharacter* m_target;

	UPROPERTY(EditAnywhere)
		UParticleSystem* ParticleSystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float damageDealt = 10.f;

	UFUNCTION(BlueprintCallable)
		void shootTarget();

	UFUNCTION(BlueprintCallable)
		void beginShootTarget();
	UFUNCTION(BlueprintCallable)
		void endShootTarget();

};
