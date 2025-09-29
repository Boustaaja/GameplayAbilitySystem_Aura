// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "AbilitySystemComponent.h" // Lisätty ehkä ennen aikojaan!!!!
#include "AuraCharacterBase.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS(Abstract) // Abstract prevent from dragging into editor. This is a base class for all characters (Aura/enemy)
class AURA_API AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AAuraCharacterBase();
	// We have to override this
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	// Also we want a getter for AttributeSet
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:
	// We want to add weapons to all characters. This needs a skeletal mesh component pointer and a socket
	virtual void BeginPlay() override;
	// All member pointers should be UPROPERTY
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	// we will need a pointer to the AbilitySystemComponent + AttributeSet. (engine version for this base class, not Aura)
	// the player will construct these in player state. Enemy will construct these in enemyCharacter
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	// TÄSTÄ ALKAA LISÄYKSET ENNEN AIKOJAAN JOS ONGELMIA POISTA!!!
	virtual void InitAbilityActorInfo();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultPrimaryAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultSecondaryAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultVitalAttributes;

	void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float level) const;
	void InitializeDefaultAttributes() const;

	// TÄHÄN LOPPPUU LISÄYKSET ENNEN AIKOJAAN!!!!!
	void AddCharacterAbilities();
private:
	// ABilities that should be given from the beginning of the game
	UPROPERTY(EditAnywhere, Category="Abilities")
	TArray < TSubclassOf<UGameplayAbility>> StartupAbilities;

};
