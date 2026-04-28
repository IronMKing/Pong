


#include "Actors/MPBoostGiver.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"
#include "Components/SphereComponent.h"

// Sets default values
AMPBoostGiver::AMPBoostGiver()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Trigger = CreateDefaultSubobject<USphereComponent>("TriggerInEditor");
	SetRootComponent(Trigger);

	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>("MeshInEditor");
	SphereMesh->SetupAttachment(RootComponent);

}

void AMPBoostGiver::ApplyEffectToTarget(AActor* InTargetActor)
{
    if (!InTargetActor)
    {
        UE_LOG(LogTemp, Error, TEXT("Booster: Missing Target"));
        if (!EffectClass)
        {
            UE_LOG(LogTemp, Error, TEXT("Booster: Missing EffectClass!"));

        }
        return;
    }
	if (UAbilitySystemComponent* targetAbilitySystemComponent = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(InTargetActor))
	{
		FGameplayEffectContextHandle effectContextHandle = targetAbilitySystemComponent->MakeEffectContext();
		effectContextHandle.AddInstigator(InTargetActor, this);
		FGameplayEffectSpecHandle specHandle = targetAbilitySystemComponent->MakeOutgoingSpec(EffectClass, 1.f, effectContextHandle);
	
        if (specHandle.Data.IsValid())
        {
            targetAbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*specHandle.Data.Get());
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("Booster: SpecHandle Data was NULL for %s"), *GetName());
        }
	}

}



