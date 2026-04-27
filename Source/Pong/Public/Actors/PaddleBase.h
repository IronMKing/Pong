
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AbilitySystemInterface.h"
#include "PaddleBase.generated.h"

class UBoxComponent;
class UMPAbilitySystemComponent;
class UMPSpeedAttributeSet;
class UMPLengthAttributeSet;

UCLASS()
class PONG_API APaddleBase : public APawn, public IAbilitySystemInterface
{
	GENERATED_BODY()

private:


	UPROPERTY()
	TObjectPtr<UMPSpeedAttributeSet> SpeedAttributes;

	UPROPERTY()
	TObjectPtr<UMPLengthAttributeSet> LengthAttributes;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PossessedBy(AController* NewController) override;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UMPAbilitySystemComponent> AbilitySystemComponent;

public:	
	
	APaddleBase();

	UFUNCTION(BlueprintImplementableEvent, Category = "Movement")
	void MovePaddle(float InputValue);

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UBoxComponent>Trigger;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> CubeMesh;


	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	TObjectPtr<UMPSpeedAttributeSet> GetSpeedAttributeSet() const;
	TObjectPtr<UMPLengthAttributeSet> GetLengthAttributeSet() const;

};
