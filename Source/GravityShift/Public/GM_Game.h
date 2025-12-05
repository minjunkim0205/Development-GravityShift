// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GM_Game.generated.h"

/**
 * 
 */
UCLASS()
class GRAVITYSHIFT_API AGM_Game : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGM_Game();

protected:
	virtual void HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer) override;

public:
	UPROPERTY(EditAnywhere, Category = "Players")
	TSubclassOf<APawn> Player1Pawn;

	UPROPERTY(EditAnywhere, Category = "Players")
	TSubclassOf<APawn> Player2Pawn;
};
