

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MPPongPlayerController.generated.h"

/**
 * 
 */

class UInputMappingContext;

UCLASS()
class PONG_API AMPPongPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* PongMappingContext;

	
};
