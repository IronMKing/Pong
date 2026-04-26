

#pragma once

#include "CoreMinimal.h"
#include "MPBaseAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "MPLengthAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class PONG_API UMPLengthAttributeSet : public UMPBaseAttributeSet
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Length;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxLength;

protected:
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue);

public:
	UMPLengthAttributeSet();

	ATTRIBUTE_ACCESSORS(ThisClass, Length)
	ATTRIBUTE_ACCESSORS(ThisClass, MaxLength)
};
