
#include "Actors/BallBase.h"
#include "Components/SphereComponent.h"

// Sets default values
ABallBase::ABallBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Trigger = CreateDefaultSubobject<USphereComponent>("TriggerInEditor");
	SetRootComponent(Trigger);

	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>("MeshInEditor");
	SphereMesh->SetupAttachment(RootComponent);

	Tags.Add(FName("Ball"));
}

// Called when the game starts or when spawned
void ABallBase::BeginPlay()
{
	Super::BeginPlay();

	Trigger->AddForce(FVector(50000.0, 100000.0, 0.0), "None", true);

}


