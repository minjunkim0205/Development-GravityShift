// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_Game.h"
#include "GravityShift.h"

AGM_Game::AGM_Game()
{
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *CALLINFO);
	//PRINT_CALLINFO();
	PRINT_LOG(TEXT("My Log : %s"), TEXT("GravityShift Log test"));
}

void AGM_Game::HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer)
{
	Super::HandleStartingNewPlayer_Implementation(NewPlayer);

	// 플레이어 인덱스 얻기
	int32 PlayerIndex = NewPlayer->GetLocalPlayer()->GetControllerId();

	AActor* StartSpot = FindPlayerStart(NewPlayer);

	if (PlayerIndex == 0 && Player1Pawn)
	{
		APawn* Spawned = GetWorld()->SpawnActor<APawn>(Player1Pawn, StartSpot->GetActorLocation(), StartSpot->GetActorRotation());
		NewPlayer->Possess(Spawned);
	}
	else if (PlayerIndex == 1 && Player2Pawn)
	{
		APawn* Spawned = GetWorld()->SpawnActor<APawn>(Player2Pawn, StartSpot->GetActorLocation(), StartSpot->GetActorRotation());
		NewPlayer->Possess(Spawned);
	}
}