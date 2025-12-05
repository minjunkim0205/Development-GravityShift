#include "GM_Game.h"
#include "GravityShift.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerStart.h"
#include "EngineUtils.h"
#include "PC_Game.h"

AGM_Game::AGM_Game()
{
    PRINT_LOG(TEXT("GravityShift debug start!!"));
}

void AGM_Game::BeginPlay()
{
    Super::BeginPlay();

    UWorld* World = GetWorld();
    if (!World)
        return;

    // -------------------------------
    // PlayerStart 찾기 (태그 기반)
    // -------------------------------
    AActor* P1Start = nullptr;
    AActor* P2Start = nullptr;

    for (TActorIterator<APlayerStart> It(World); It; ++It)
    {
        APlayerStart* Start = *It;

        if (Start->ActorHasTag("Player01"))
        {
            P1Start = Start;
        }
        else if (Start->ActorHasTag("Player02"))
        {
            P2Start = Start;
        }
    }

    if (!P1Start || !P2Start)
    {
        PRINT_LOG(TEXT("PlayerStart Tag(Player01/Player02) not found."));
        return;
    }

    // -------------------------------
    // Pawn 스폰
    // -------------------------------
    APawn* P1Pawn = nullptr;
    APawn* P2Pawn = nullptr;

    if (Player1Pawn)
    {
        P1Pawn = World->SpawnActor<APawn>(
            Player1Pawn,
            P1Start->GetActorLocation(),
            P1Start->GetActorRotation()
        );
    }

    if (Player2Pawn)
    {
        P2Pawn = World->SpawnActor<APawn>(
            Player2Pawn,
            P2Start->GetActorLocation(),
            P2Start->GetActorRotation()
        );
    }

    // -------------------------------
    // PlayerController 설정
    // -------------------------------
    APC_Game* PC = Cast<APC_Game>(World->GetFirstPlayerController());
    if (!PC)
    {
        PRINT_LOG(TEXT("PlayerController error"));
        return;
    }

    // 컨트롤러에는 두 Pawn 전달
    PC->Player1Pawn = P1Pawn;
    PC->Player2Pawn = P2Pawn;

    // 컨트롤러가 소유할 Pawn(1P만)
    if (P1Pawn)
    {
        PC->Possess(P1Pawn);
    }
    PRINT_LOG(TEXT("P1,P2 Spawned!"));
}
