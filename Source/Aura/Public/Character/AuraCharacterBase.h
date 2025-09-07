// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AuraCharacterBase.generated.h"

UCLASS(Abstract) // Abstract prevent from dragging into editor. This is a base class for all characters (Aura/enemy)
class AURA_API AAuraCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AAuraCharacterBase();

protected:
	// We want to add weapons to all characters. This needs a skeletal mesh component pointer and a socket
	virtual void BeginPlay() override;
	// All member pointers should be UPROPERTY
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

};
