// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EventTrigger.h"
#include "EventInstigatorActor.generated.h"

UCLASS()
class TANTRUMN_API AEventInstigatorActor : public AActor, public IEventTrigger
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEventInstigatorActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EventActor")
		TArray<AActor*> TriggerTargets;

	UFUNCTION(BlueprintCallable)
		void TriggerActorTargets();

	UFUNCTION(BlueprintCallable)
		void UndoTriggerTargets();

	UPROPERTY(BlueprintReadWrite)
		bool Triggered;

};
