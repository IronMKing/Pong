


#include "Player/MPPongPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/GameplayStatics.h"

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

	TArray<AActor*> FoundCameras;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("MainCamera"), FoundCameras);

	if (FoundCameras.Num() > 0)
	{
		// Set the first camera found as the view target
		SetViewTarget(FoundCameras[0]);
	}
}


