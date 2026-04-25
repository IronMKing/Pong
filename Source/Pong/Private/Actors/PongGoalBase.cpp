


#include "Actors/PongGoalBase.h"
#include "Kismet/GameplayStatics.h"
#include "Pong/Public/Game/MPPongGameMode.h"

// Sets default values
APongGoalBase::APongGoalBase()
{
	PrimaryActorTick.bCanEverTick = false;

	GoalMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GoalMeshInEditor"));
	RootComponent = GoalMesh;

	GoalMesh->SetNotifyRigidBodyCollision(true);
}

// Called when the game starts or when spawned
void APongGoalBase::BeginPlay()
{
	Super::BeginPlay();
	
	GameMode = Cast<AMPPongGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	if (GoalMesh)
	{
		GoalMesh->OnComponentHit.AddDynamic(this, &ThisClass::HandleGoalHit);
	}
}

void APongGoalBase::HandleGoalHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor && OtherActor->ActorHasTag(TEXT("Ball")))
	{
		if (GameMode)
		{
			GameMode->UpdateScore(bPlayerScored);
		}

		OnHit(OtherActor);
	}
}
