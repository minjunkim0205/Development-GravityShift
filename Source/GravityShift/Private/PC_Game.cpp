#include "GravityShift.h"
#include "PC_Game.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Character.h"

APC_Game::APC_Game()
{
	bShowMouseCursor = false;
}

void APC_Game::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		if (IMC_Game)
		{
			Subsystem->AddMappingContext(IMC_Game, 0);
		}
	}
}

void APC_Game::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(InputComponent);
	if (!EIC)
	{
		return;
	}

	// Player1
	if (IA_Player01Move)
	{
		EIC->BindAction(IA_Player01Move, ETriggerEvent::Triggered, this, &APC_Game::MoveP1);
	}
	if (IA_Player01Jump) 
	{
		EIC->BindAction(IA_Player01Jump, ETriggerEvent::Started, this, &APC_Game::JumpP1);
	}

	// Player2
	if (IA_Player02Move)
	{
		EIC->BindAction(IA_Player02Move, ETriggerEvent::Triggered, this, &APC_Game::MoveP2);
	}
	if (IA_Player02Jump)
	{
		EIC->BindAction(IA_Player02Jump, ETriggerEvent::Started, this, &APC_Game::JumpP2);
	}
}

// ------------------------------------------
// Player 1 Move & Jump
// ------------------------------------------
void APC_Game::MoveP1(const FInputActionValue& Value)
{
	PRINT_LOG(TEXT("A,D"));
	if (Player1Character)
	{
		float Axis = Value.Get<float>();
		Player1Character->AddMovementInput(FVector::RightVector, Axis);
	}
}

void APC_Game::JumpP1(const FInputActionValue& Value)
{
	PRINT_LOG(TEXT("W"));
	if (Player1Character)
	{
		Player1Character->Jump();
	}
}

// ------------------------------------------
// Player 2 Move & Jump
// ------------------------------------------
void APC_Game::MoveP2(const FInputActionValue& Value)
{
	PRINT_LOG(TEXT("LEFT,RIGHT"));
	if (Player2Character)
	{
		float Axis = Value.Get<float>();
		Player2Character->AddMovementInput(FVector::RightVector, Axis);
	}
}

void APC_Game::JumpP2(const FInputActionValue& Value)
{
	PRINT_LOG(TEXT("UP"));
	if (Player2Character) 
	{
		Player2Character->Jump();
	}
}
