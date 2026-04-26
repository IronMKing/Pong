

#pragma once

#include "CoreMinimal.h"
#include "MPBaseAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "MPSpeedAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class PONG_API UMPSpeedAttributeSet : public UMPBaseAttributeSet
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Speed;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxSpeed;

protected:
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue);

public:
	UMPSpeedAttributeSet();

	ATTRIBUTE_ACCESSORS(ThisClass, Speed)
	ATTRIBUTE_ACCESSORS(ThisClass, MaxSpeed)

};
