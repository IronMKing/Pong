

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PongGoalBase.generated.h"

UCLASS()
class PONG_API APongGoalBase : public AActor
{
	GENERATED_BODY()
	
public:
	APongGoalBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void HandleGoalHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> GoalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bPlayerScored;

	UPROPERTY(BlueprintReadOnly)
	class AMPPongGameMode* GameMode;

	UFUNCTION(BlueprintImplementableEvent)
	void OnHit(AActor* OtherActor);

};
