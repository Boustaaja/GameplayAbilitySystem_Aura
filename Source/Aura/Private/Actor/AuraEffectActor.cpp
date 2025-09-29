// Fill out your copyright notice in the Description page of Project Settings.
#include "Actor/AuraEffectActor.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"

// Sets default values
AAuraEffectActor::AAuraEffectActor()
{
	// We removed our tick, so this is false
	PrimaryActorTick.bCanEverTick = false;
	// This can be any SceneComponent. Flexibility
	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}

void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

// We are going to call this when overlapping, for that we need a GE
void AAuraEffectActor::ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
		// GAS has it's own Library. Needs target actor. Returns the ASC
		UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target);
		if (TargetASC == nullptr) return; // If actor has no ASC do nothing

		check(GameplayEffectClass) // If the effect is unset(nullptr), that is something to check
		FGameplayEffectContextHandle EffectContextHandle =  TargetASC->MakeEffectContext();
		EffectContextHandle.AddSourceObject(this); // Who did this?
		FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, 1.0f, EffectContextHandle); // returns spec handle
		TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
}


