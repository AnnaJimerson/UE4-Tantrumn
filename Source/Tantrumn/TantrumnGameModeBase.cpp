// Copyright Epic Games, Inc. All Rights Reserved.


#include "TantrumnGameModeBase.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Kismet/GameplayStatics.h"
#include "MyCharacter.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"

ATantrumnGameModeBase::ATantrumnGameModeBase()
{

}

void ATantrumnGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	// Create our HUD widget
	if (WidgetTemplate){
		if (!WidgetInstance){
			AMyCharacter* character = Cast<AMyCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

			if (character) {
				WidgetInstance = CreateWidget<UUserWidget>(GetWorld(), WidgetTemplate);
				WidgetInstance->AddToPlayerScreen(0);
				WidgetInstance->SetOwningPlayer(GetWorld()->GetFirstPlayerController());
			}
		}
	}
}

void ATantrumnGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
