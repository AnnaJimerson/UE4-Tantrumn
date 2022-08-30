// Fill out your copyright notice in the Description page of Project Settings.


#include "EventInstigatorActor.h"

// Sets default values
AEventInstigatorActor::AEventInstigatorActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEventInstigatorActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEventInstigatorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEventInstigatorActor::TriggerActorTargets()
{
	// If already triggered return
	if (Triggered) return;

	// Print that this triggered
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%s Triggered An Event!"), *GetName()));

	// Trigger all actor targets
	for (AActor* target : TriggerTargets) 
	{
		// Then trigger everything using an interface (For some reason we use 'U' for checking and 'I' for calling???)
		// why????
		if (target->Implements<UEventTrigger>()) {
			IEventTrigger::Execute_ReactToTrigger(target);
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("%s affected!"), *target->GetName()));
		}
	}

	// Set triggered once done
	Triggered = true;
}

void AEventInstigatorActor::UndoTriggerTargets()
{
	// If already triggered return
	if (!Triggered) return;

	// Print that this triggered
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%s Trigger was UNDONE!"), *GetName()));

	// Trigger all actor targets
	for (AActor* target : TriggerTargets)
	{
		// Then trigger everything using an interface (For some reason we use 'U' for checking and 'I' for calling???)
		// why????
		if (target->Implements<UEventTrigger>()) {
			IEventTrigger::Execute_ReactToUndoTrigger(target);
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("%s affected!"), *target->GetName()));
		}
	}

	// Set triggered once done
	Triggered = false;
}

