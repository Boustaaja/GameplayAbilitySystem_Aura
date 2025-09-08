// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

class UInputMappingContext; // forward declaration. Also need to add EnhancedInput in to Aura.Build.cs so we can access that module
/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()
	// We greated the input mapping context, and the place to add that in Player controller is in begin play, Begin play is a protected function
public:
	// constructor
	AAuraPlayerController();
protected:
	// We need to override Begin play
	virtual void BeginPlay() override;

private:
	// first we need a pointer to UIMC
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> AuraContext;
};
