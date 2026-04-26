

#include "AbilitySystem/Attributes/MPSpeedAttributeSet.h"


void UMPSpeedAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeBaseChange(Attribute, NewValue);

	if (GetSpeedAttribute() == Attribute) {
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxSpeed());
	}
}

UMPSpeedAttributeSet::UMPSpeedAttributeSet()
{
	InitSpeed(100.f);
	InitMaxSpeed(200.f);
}
