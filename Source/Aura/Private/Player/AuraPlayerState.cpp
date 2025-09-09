// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerState.h"

AAuraPlayerState::AAuraPlayerState()
{
	// This is how often the server tries to update clients. Normally it is lower, but because this is in a player state, it has to update faster
	NetUpdateFrequency = 100.f;
}
