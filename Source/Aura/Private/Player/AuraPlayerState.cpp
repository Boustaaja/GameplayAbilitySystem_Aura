// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/AuraPlayerState.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

AAuraPlayerState::AAuraPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	// Let's make sure this is replicated
	AbilitySystemComponent->SetIsReplicated(true);
	// This has to be Mixed for our character
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	// Also need to construct our Attribute set
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");	
	
	// This is how often the server tries to update clients. Normally it is lower, but because this is in a player state, it has to update faster
	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
