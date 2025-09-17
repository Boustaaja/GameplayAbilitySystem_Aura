// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraCharacterBase.h"

AAuraCharacterBase::AAuraCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	// note* You dont need a TEXT macro to Fnames
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	// next we attach the weapon to a socket on a mesh. Socket is named as WeaponHandSocket
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	// Weapon should not have any collision
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);


}
UAbilitySystemComponent* AAuraCharacterBase::GetAbilitySystemComponent() const
{
	// And we want to return this pointer
	return AbilitySystemComponent;
}

void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

