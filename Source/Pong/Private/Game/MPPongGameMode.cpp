


#include "Game/MPPongGameMode.h"
#include "Player/MPPongPlayerController.h"
#include "Actors/PaddleBase.h"

AMPPongGameMode::AMPPongGameMode()
{
	PlayerControllerClass = AMPPongPlayerController::StaticClass();
	DefaultPawnClass = APaddleBase::StaticClass();
}
