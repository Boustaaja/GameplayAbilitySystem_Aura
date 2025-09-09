// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface // we want to inherit from this class, remember to include it!
{
	GENERATED_BODY()
	
public:
	virtual void HighlightActor() override; // We need to override these inherited functions
	virtual void UnHighligtActor() override;
};
