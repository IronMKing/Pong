


#include "Player/MPPongPlayerController.h"
#include "EnhancedInputSubsystems.h"

void AMPPongPlayerController::BeginPlay()
{
	SetInputMode(FInputModeGameOnly());
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		if (PongMappingContext)
		{
			Subsystem->AddMappingContext(PongMappingContext, 0);
		}
	}
}


