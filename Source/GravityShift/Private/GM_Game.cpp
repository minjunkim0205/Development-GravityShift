/*GM_Game.cpp*/
#include "GravityShift.h"
#include "GM_Game.h"
#include "PC_Game.h"
#include "GameFramework/Character.h"

AGM_Game::AGM_Game()
{
    PlayerControllerClass = APC_Game::StaticClass();
    // DefaultPawnClass는 BP에서 지정
}