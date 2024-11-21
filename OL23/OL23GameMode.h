// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "OL23GameMode.generated.h"

UCLASS(minimalapi)
class AOL23GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AOL23GameMode();

    void GetAllActorData();

    // Function to gather and log player-specific data
    void GetPlayerData();

protected:
    // beginplay is overriden when the functions above are called
    virtual void BeginPlay() override;
};



