
#include "Actors/PaddleBase.h"
#include "Components/BoxComponent.h"
#include "Pong/Public/AbilitySystem/Components/MPAbilitySystemComponent.h"

// Sets default values
APaddleBase::APaddleBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Trigger = CreateDefaultSubobject<UBoxComponent>("TriggerInEditor");
	SetRootComponent(Trigger);

	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>("MeshInEditor");
	CubeMesh->SetupAttachment(RootComponent);

	AbilitySystemComponent = CreateDefaultSubobject<UMPAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}

// Called when the game starts or when spawned
void APaddleBase::BeginPlay()
{
	Super::BeginPlay();

}

void APaddleBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}

UAbilitySystemComponent* APaddleBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
