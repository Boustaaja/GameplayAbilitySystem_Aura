// Fill out your copyright notice in the Description page of Project Settings.

#include "Actor/AuraEffectActor.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "Components/SphereComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"



// Sets default values
AAuraEffectActor::AAuraEffectActor()
{
	// We removed our tick, so this is false
	PrimaryActorTick.bCanEverTick = false;
	// We want a static mesh as the root and attach the sphere to it.	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	// Attaching the sphere to the root. That way if the mesh moves, the sphere moves with it.
	Sphere->SetupAttachment(GetRootComponent());
	// Overlap function. Called when sphere overlaps with some other actor + end overlap

}

void AAuraEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// What to do when overlapping. We should use effects, but for now we are just going to change a value of the attribute
	// 1. Check if the actor that is overlapping has the ASC

	// Cast the actor to IAbilitySystemInterf. and wrap this in an if statement to check if it has it. And find an attribute set on this ASC. This is only a temporary way of to do this
	// TODO: Change this to apply a Gameplay Effect. For now, using const_cast as a hack!
	if
		(IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		// this expression is going to return an object of type Uattribute set
		const UAuraAttributeSet* AuraAttributeSet = Cast<UAuraAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UAuraAttributeSet::StaticClass()));
		UAuraAttributeSet* MutableAuraAttributeSet = const_cast<UAuraAttributeSet*>(AuraAttributeSet);
		// set the health equal to itse own health plus 25
		MutableAuraAttributeSet->SetHealth(AuraAttributeSet->GetHealth() + 25.f);
		// After doing this, destroy the effect actor
		MutableAuraAttributeSet->SetMana(AuraAttributeSet->GetMana() - 25.f);
		Destroy();
	}

}

void AAuraEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
	// Binding the onComp.Begin/End.. to Sphere
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AAuraEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AAuraEffectActor::EndOverlap);
}


