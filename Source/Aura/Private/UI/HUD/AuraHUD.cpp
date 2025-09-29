// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/AuraHUD.h"
#include "UI/Widget/AuraUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	// This will construct the controller for the first time if it hasnt been done yet
	if (OverlayWidgetController == nullptr)
	{
		// NewObject is how we can create a new object
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);

		return OverlayWidgetController;
	}
	return OverlayWidgetController;
}

void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	// 1. Widget
	// 2. WidgetController
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class uninitialized, please fill out BP_AuraHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller class uninitialized, please fill out BP_AuraHUD"));
	// createWidget returns a user widget pointer
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UAuraUserWidget>(Widget);
	// creating the widgetController
	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	// now we can construct the widget controller, so lets call the function
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);
	// And then tie the widget and controller together
	OverlayWidget->SetWidgetController(WidgetController);
	// and finally we would like to add it into viewport
	Widget->AddToViewport();
}
