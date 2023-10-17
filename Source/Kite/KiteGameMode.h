// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "KiteGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerDiedSignature, ACharacter*, Character);

UCLASS(minimalapi)
class AKiteGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AKiteGameMode();
    
    const FOnPlayerDiedSignature& GetOnPlayerDied() const { return OnPlayerDied; }
    
    // Tries to Spawn the player's pawn.
    virtual void RestartPlayer(AController* NewPlayer) override;
    
protected:
    virtual void BeginPlay() override;

    // Called when Player character has died.
    UFUNCTION()
    virtual void PlayerDied(ACharacter* Character);

    // Signature to bind delegate.
    UPROPERTY()
    FOnPlayerDiedSignature OnPlayerDied;
};



