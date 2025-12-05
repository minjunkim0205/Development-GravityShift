#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "PC_Game.generated.h"

class UInputAction;
class UInputMappingContext;
class ACharacter;

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
    // ½ºÆùµÈ Character
    UPROPERTY(BlueprintReadWrite)
    ACharacter* Player1Character;

    UPROPERTY(BlueprintReadWrite)
    ACharacter* Player2Character;

    // Input Actions
    UPROPERTY(EditAnywhere, Category = "Input")
    UInputMappingContext* IMC_Game;

    UPROPERTY(EditAnywhere, Category = "Input")
    UInputAction* IA_Player01Move;

    UPROPERTY(EditAnywhere, Category = "Input")
    UInputAction* IA_Player01Jump;

    UPROPERTY(EditAnywhere, Category = "Input")
    UInputAction* IA_Player02Move;

    UPROPERTY(EditAnywhere, Category = "Input")
    UInputAction* IA_Player02Jump;

private:
    void MoveP1(const FInputActionValue& Value);
    void JumpP1(const FInputActionValue& Value);

    void MoveP2(const FInputActionValue& Value);
    void JumpP2(const FInputActionValue& Value);
};
