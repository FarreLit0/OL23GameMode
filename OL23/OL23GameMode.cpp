// Copyright Epic Games, Inc. All Rights Reserved.

#include "OL23GameMode.h"
#include "OL23Character.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/Actor.h"
#include "EngineUtils.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"

AOL23GameMode::AOL23GameMode()
    : Super()
{
    // Set default pawn class to our Blueprinted character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
    DefaultPawnClass = PlayerPawnClassFinder.Class;
}

void AOL23GameMode::BeginPlay()
{
    Super::BeginPlay();

    // Collect all actor data
    GetAllActorData();

    // Collect player-specific data
    GetPlayerData();
}

void AOL23GameMode::GetAllActorData()
{
    // Get the current game world
    UWorld* World = GetWorld();

    if (!World)
    {
        UE_LOG(LogTemp, Warning, TEXT("World context is invalid"));
        return; // Exit the function to prevent crash
    }

    // Iterate through all actors in the world
    for (TActorIterator<AActor> ActorItr(World); ActorItr; ++ActorItr)
    {
        AActor* Actor = *ActorItr;

        // Get actor name, location, and class
        FString ActorName = Actor->GetName();
        FVector ActorLocation = Actor->GetActorLocation();
        FString ActorClass = Actor->GetClass()->GetName();

        // Log the actor data
        UE_LOG(LogTemp, Log, TEXT("Actor Name: %s, Class: %s, Location: %s"),
            *ActorName, *ActorClass, *ActorLocation.ToString());
    }
}

void AOL23GameMode::GetPlayerData()
{
    UWorld* World = GetWorld();

    if (!World)
    {
        UE_LOG(LogTemp, Warning, TEXT("World context is invalid!"));
        return;
    }

    // Get the player controller (single player)
    APlayerController* PlayerController = World->GetFirstPlayerController();
    if (!PlayerController)
    {
        UE_LOG(LogTemp, Warning, TEXT("Player controller not found"));
        return;
    }

    // Get the player's pawn
    APawn* PlayerPawn = PlayerController->GetPawn();
    if (!PlayerPawn)
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerPawn not found"));
        return;
    }

    // Get player-specific data
    FString PlayerName = PlayerPawn->GetName();
    FVector PlayerLocation = PlayerPawn->GetActorLocation();
    FString PlayerClass = PlayerPawn->GetClass()->GetName();

    // Log the player data
    UE_LOG(LogTemp, Log, TEXT("Player Name: %s, Class: %s, Location: %s"),
        *PlayerName, *PlayerClass, *PlayerLocation.ToString());
}
