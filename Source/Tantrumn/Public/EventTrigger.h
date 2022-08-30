// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EventTrigger.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEventTrigger : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TANTRUMN_API IEventTrigger
{
	GENERATED_BODY()
public:
		// Add interface functions to this class. This is the class that will be inherited to implement this interface.
		UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "EventTrigger")
			void ReactToTrigger();

		UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "EventTrigger")
			void ReactToUndoTrigger();
};
