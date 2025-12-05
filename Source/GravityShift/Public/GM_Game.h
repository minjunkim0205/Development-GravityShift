#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GM_Game.generated.h"

UCLASS()
class GRAVITYSHIFT_API AGM_Game : public AGameModeBase
{
    GENERATED_BODY()

public:
    AGM_Game();

protected:
    virtual void BeginPlay() override;

public:
    // 2개의 Pawn 클래스 (BP로 설정)
    UPROPERTY(EditAnywhere, Category = "Players")
    TSubclassOf<APawn> Player1Pawn;

    UPROPERTY(EditAnywhere, Category = "Players")
    TSubclassOf<APawn> Player2Pawn;
};
