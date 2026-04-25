

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MPPongGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PONG_API AMPPongGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	AMPPongGameMode();

	UFUNCTION(BlueprintCallable, Category = "Pong Logic")
	void UpdateScore(bool bPlayerScored);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Pong Logic")
	int32 PlayerScore = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Pong Logic")
	int32 AIScore = 0;

	UFUNCTION(BlueprintImplementableEvent, Category = "Pong Logic")
	void OnScoreChanged(int32 NewPlayerScore, int32 NewAIScore);
};
