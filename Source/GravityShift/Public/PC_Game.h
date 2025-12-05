#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PC_Game.generated.h"

UCLASS()
class GRAVITYSHIFT_API APC_Game : public APlayerController
{
    GENERATED_BODY()

public:
    APC_Game();

protected:
    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;

public:
    // 두 캐릭터에 접근하기 위한 변수
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    APawn* Player1Pawn;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    APawn* Player2Pawn;

private:
    // Player1 입력
    void MoveP1_X(float Value);
    void MoveP1_Y(float Value);

    // Player2 입력
    void MoveP2_X(float Value);
    void MoveP2_Y(float Value);
};
