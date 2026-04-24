

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BallBase.generated.h"

class USphereComponent;

UCLASS()
class PONG_API ABallBase : public AActor
{
	GENERATED_BODY()
	
protected:

	virtual void BeginPlay() override;

public:	

	ABallBase();
	//virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<USphereComponent>Trigger;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> SphereMesh;

};
