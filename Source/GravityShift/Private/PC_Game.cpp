/*PC_Game.cpp*/
#include "GravityShift.h"
#include "PC_Game.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Character.h"

void APC_Game::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	if (Subsystem && IMC_Game)
	{
		Subsystem->ClearAllMappings();
		Subsystem->AddMappingContext(IMC_Game, 0);
	}

	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
	bShowMouseCursor = false;
}

void APC_Game::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(InputComponent);
	if (!EIC)
	{
		return;
	}

	if (IA_PlayerMove)
	{
		PRINT_LOG(TEXT("Move IA mapping"));
		EIC->BindAction(IA_PlayerMove, ETriggerEvent::Triggered, this, &APC_Game::Move);
	}

	if (IA_PlayerJump)
	{
		PRINT_LOG(TEXT("Jump IA mapping"));
		EIC->BindAction(IA_PlayerJump, ETriggerEvent::Started, this, &APC_Game::Jump);
	}
}

void APC_Game::Move(const FInputActionValue& Value)
{
	PRINT_LOG(TEXT("Move!"));
	const float AxisValue = Value.Get<float>();
	ACharacter* MyCharacter = Cast<ACharacter>(GetPawn());

	if (MyCharacter)
	{
		MyCharacter->AddMovementInput(FVector(0.f, 1.f, 0.f), AxisValue);

	}
}

void APC_Game::Jump(const FInputActionValue&)
{
	PRINT_LOG(TEXT("Jump!"));
	ACharacter* MyCharacter = Cast<ACharacter>(GetPawn());
	if (MyCharacter)
	{
		MyCharacter->Jump();
	}
}
