#include "PC_Game.h"
#include "GameFramework/Pawn.h"

APC_Game::APC_Game()
{
    bShowMouseCursor = false;
}

void APC_Game::BeginPlay()
{
    Super::BeginPlay();
}

void APC_Game::SetupInputComponent()
{
    Super::SetupInputComponent();

    // Player 1 입력
    InputComponent->BindAxis("P1_MoveX", this, &APC_Game::MoveP1_X);
    InputComponent->BindAxis("P1_MoveY", this, &APC_Game::MoveP1_Y);

    // Player 2 입력
    InputComponent->BindAxis("P2_MoveX", this, &APC_Game::MoveP2_X);
    InputComponent->BindAxis("P2_MoveY", this, &APC_Game::MoveP2_Y);
}

//==========================
// Player 1 Movement
//==========================
void APC_Game::MoveP1_X(float Value)
{
    if (Player1Pawn && Value != 0.f)
    {
        Player1Pawn->AddMovementInput(FVector::RightVector, Value);
    }
}

void APC_Game::MoveP1_Y(float Value)
{
    if (Player1Pawn && Value != 0.f)
    {
        Player1Pawn->AddMovementInput(FVector::ForwardVector, Value);
    }
}

//==========================
// Player 2 Movement
//==========================
void APC_Game::MoveP2_X(float Value)
{
    if (Player2Pawn && Value != 0.f)
    {
        Player2Pawn->AddMovementInput(FVector::RightVector, Value);
    }
}

void APC_Game::MoveP2_Y(float Value)
{
    if (Player2Pawn && Value != 0.f)
    {
        Player2Pawn->AddMovementInput(FVector::ForwardVector, Value);
    }
}
