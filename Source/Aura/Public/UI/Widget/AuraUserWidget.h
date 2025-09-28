// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AuraUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraUserWidget : public UUserWidget
{
	GENERATED_BODY()
	// When the widget controller broadcasts data, our widgets will receive thath data and response to it
	// dependencies: from AuraUserWidget -> WidgetController

public: 
	// function for setting the controller from BP
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	// This is generic, so the controller could be any object
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:
	// When ever se set the widget controller for a given widget, well also call this function
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
