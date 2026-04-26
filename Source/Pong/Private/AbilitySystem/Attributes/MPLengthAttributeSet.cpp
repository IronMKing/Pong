

#include "AbilitySystem/Attributes/MPLengthAttributeSet.h"

void UMPLengthAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeBaseChange(Attribute, NewValue);

	if (GetLengthAttribute() == Attribute) {
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxLength());
	}
}

UMPLengthAttributeSet::UMPLengthAttributeSet()
{
	InitLength(100.f);
	InitMaxLength(200.f);
}
