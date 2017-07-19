// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "TestingGrounds2.h"
#include "TestingGrounds2GameMode.h"
#include "TestingGrounds2HUD.h"
#include "TestingGrounds2Character.h"

ATestingGrounds2GameMode::ATestingGrounds2GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Dynamic/Player/Behaviour/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATestingGrounds2HUD::StaticClass();
}
