// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEnemyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class AURA_API IEnemyInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// A function that highlights the enemy when hoovered over. We can use these functions in all actors that implements this interface
	virtual void HighlightActor() = 0; // 0; means it is now a pure virtual function. needs to be implemented in enemy class
	virtual void UnHighlightActor() = 0;
};
