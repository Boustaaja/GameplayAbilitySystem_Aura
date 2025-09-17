// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraCharacter.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/AuraPlayerState.h"

AAuraCharacter::AAuraCharacter()
{
	// These are typical parameters for a top down game
	// we want the character to turn into direction we are moving it.
	// for that we want to access some things
	GetCharacterMovement()->bOrientRotationToMovement = true;
	// character will orient towards movement with 400 speed
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	GetCharacterMovement()->bConstrainToPlane = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void AAuraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// init ability actor info for the server
	InitAbilityActorInfo();
}

void AAuraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	// Init ability actor info for the client
	InitAbilityActorInfo();
}

// We need this function multiple times, so that is why it is a function, no need to repeat us.
void AAuraCharacter::InitAbilityActorInfo()
{
	// We need to access to Player state
	AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
	check(AuraPlayerState);
	// Owner is PlayerState, avatar is this character
	AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState, this);
	// And now that we have the PlayerState for aura, we can set te pointers for Auras ASC
	AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
	AttributeSet = AuraPlayerState->GetAttributeSet();
}
