// Fill out your copyright notice in the Description page of Project Settings.
#include "EnhancedInputSubsystems.h"
#include "Player/AuraPlayerController.h"

AAuraPlayerController::AAuraPlayerController()
{
	// we have to make sure that the PlayerController replicates. For that it has a boolean
	bReplicates = true;

}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	// here we need to add the IMC, for that, we need a variable to store it
	check(AuraContext); // is AuraContext set or not
	// Subsystems are singletons, and exist only one at a duration of the program. With this we can add MC
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(AuraContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}