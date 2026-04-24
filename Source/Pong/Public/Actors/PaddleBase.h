
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AbilitySystemInterface.h"
#include "PaddleBase.generated.h"

class UBoxComponent;
class UMPAbilitySystemComponent;

UCLASS()
class PONG_API APaddleBase : public APawn, public IAbilitySystemInterface
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UMPAbilitySystemComponent> AbilitySystemComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PossessedBy(AController* NewController) override;

public:	
	
	APaddleBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Movement")
	void MovePaddle(float InputValue);


	//virtual void Tick(float DeltaTime) override;

	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UBoxComponent>Trigger;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> CubeMesh;

};
