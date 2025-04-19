// Copyright Epic Games, Inc. All Rights Reserved.

#include "RandomRougeLikeGameMode.h"
#include "RandomRougeLikeCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARandomRougeLikeGameMode::ARandomRougeLikeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
