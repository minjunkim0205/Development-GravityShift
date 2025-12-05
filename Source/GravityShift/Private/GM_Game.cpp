#include "GravityShift.h"
#include "GM_Game.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerStart.h"
#include "EngineUtils.h"
#include "PC_Game.h"
#include "GameFramework/Character.h"

AGM_Game::AGM_Game()
{
    PRINT_LOG(TEXT("GravityShift debug start!!"));
}

void AGM_Game::BeginPlay()
{
    Super::BeginPlay();

    UWorld* World = GetWorld();
    if (!World) return;

    AActor* P1Start = nullptr;
    AActor* P2Start = nullptr;

    for (TActorIterator<APlayerStart> It(World); It; ++It)
    {
        APlayerStart* Start = *It;

        if (Start->ActorHasTag("Player01"))
            P1Start = Start;
        else if (Start->ActorHasTag("Player02"))
            P2Start = Start;
    }

    if (!P1Start || !P2Start)
    {
        PRINT_LOG(TEXT("PlayerStart Tag(Player01/Player02) not found."));
        return;
    }

    // ------------------------------------------
    // Character Spawn
    // ------------------------------------------
    ACharacter* P1 = nullptr;
    ACharacter* P2 = nullptr;

    if (Player1Character)
    {
        P1 = World->SpawnActor<ACharacter>(
            Player1Character,
            P1Start->GetActorLocation(),
            P1Start->GetActorRotation()
        );
    }

    if (Player2Character)
    {
        P2 = World->SpawnActor<ACharacter>(
            Player2Character,
            P2Start->GetActorLocation(),
            P2Start->GetActorRotation()
        );
    }

    APC_Game* PC = Cast<APC_Game>(World->GetFirstPlayerController());
    if (!PC)
    {
        PRINT_LOG(TEXT("PlayerController error"));
        return;
    }

    PC->Player1Character = P1;
    PC->Player2Character = P2;

    if (P1)
        PC->Possess(P1);

    PRINT_LOG(TEXT("P1, P2 Character Spawned!"));
}
