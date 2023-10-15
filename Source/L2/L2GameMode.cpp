// Copyright Epic Games, Inc. All Rights Reserved.

#include "L2GameMode.h"
#include "L2Character.h"
#include "UObject/ConstructorHelpers.h"

AL2GameMode::AL2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
