/*PC_Game.h*/
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "PC_Game.generated.h"

class UInputAction;
class UInputMappingContext;

UCLASS()
class GRAVITYSHIFT_API APC_Game : public APlayerController
{
    GENERATED_BODY()

protected:
    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;

public:
    // Input Mapping Context
    UPROPERTY(EditAnywhere, Category = "Input")
    UInputMappingContext* IMC_Game;

    // Input Actions (이름 통일!)
    UPROPERTY(EditAnywhere, Category = "Input")
    UInputAction* IA_PlayerMove;

    UPROPERTY(EditAnywhere, Category = "Input")
    UInputAction* IA_PlayerJump;

private:
    void Move(const FInputActionValue& Value);
    void Jump(const FInputActionValue& Value);
};
