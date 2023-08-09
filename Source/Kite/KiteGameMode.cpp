// Copyright Epic Games, Inc. All Rights Reserved.

#include "KiteGameMode.h"
#include "KiteCharacter.h"
#include "UObject/ConstructorHelpers.h"

AKiteGameMode::AKiteGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
