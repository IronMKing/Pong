
#include "Actors/MPSpeedBooster.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"
#include "Components/SphereComponent.h"


// Sets default values
AMPSpeedBooster::AMPSpeedBooster()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Trigger = CreateDefaultSubobject<USphereComponent>("TriggerInEditor");
	SetRootComponent(Trigger);

	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>("MeshInEditor");
	SphereMesh->SetupAttachment(RootComponent);

}

void AMPSpeedBooster::ApplyEffectToTarget(AActor* InTargetActor)
{
	if (UAbilitySystemComponent* targetAbilitySystemComponent = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(InTargetActor))
	{
		FGameplayEffectContextHandle effectContextHandle = targetAbilitySystemComponent->MakeEffectContext();
		effectContextHandle.AddInstigator(InTargetActor, this);
		FGameplayEffectSpecHandle specHandle = targetAbilitySystemComponent->MakeOutgoingSpec(EffectClass, 1.f, effectContextHandle);
		targetAbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*specHandle.Data.Get());
	} 
}


