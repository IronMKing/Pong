

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MPLengthBooster.generated.h"

class UGameplayEffect;
class USphereComponent;

UCLASS()
class PONG_API AMPLengthBooster : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMPLengthBooster();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<USphereComponent>Trigger;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> SphereMesh;

protected:
	// Called when the game starts or when spawned
	UFUNCTION(BlueprintCallable, Category = "Effects")
	void ApplyEffectToTarget(AActor* InTargetActor);


private:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effects", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UGameplayEffect> EffectClass;

};
