


#include "Game/MPPongGameMode.h"
#include "Player/MPPongPlayerController.h"
#include "Actors/PaddleBase.h"

AMPPongGameMode::AMPPongGameMode()
{
	PrimaryActorTick.bCanEverTick = false;

	PlayerControllerClass = AMPPongPlayerController::StaticClass();
	DefaultPawnClass = APaddleBase::StaticClass();
}

void AMPPongGameMode::UpdateScore(bool bPlayerScored)
{
	if (bPlayerScored)
	{
		PlayerScore++;
	}
	else
	{
		AIScore++;
	}

	UE_LOG(LogTemp, Warning, TEXT("Score Updated! Player: %d | AI: %d"), PlayerScore, AIScore);
	OnScoreChanged(PlayerScore, AIScore);
}
