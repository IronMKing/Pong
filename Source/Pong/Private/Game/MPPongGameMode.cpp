


#include "Game/MPPongGameMode.h"
#include "Player/MPPongPlayerController.h"
#include "Actors/PaddleBase.h"
#include "Actors/BallBase.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Components/PrimitiveComponent.h"
#include "Components/SphereComponent.h"



AMPPongGameMode::AMPPongGameMode()
{
	PrimaryActorTick.bCanEverTick = false;

	PlayerControllerClass = AMPPongPlayerController::StaticClass();
	DefaultPawnClass = APaddleBase::StaticClass();
}

void AMPPongGameMode::BeginPlay()
{
	TArray<AActor*> FoundBalls;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("Ball"), FoundBalls);

	if (FoundBalls.Num() > 0)
	{
		BallRef = Cast<ABallBase>(FoundBalls[0]);
		BallReset();
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("NO BALL FOUND WITH TAG 'Ball'!"));
	}
}

void AMPPongGameMode::UpdateScore(bool bPlayerScored)
{
	if (bPlayerScored)
	{
		PlayerScore++;
	}
	else
	{
		AIScore++;
	}

	BallReset();
	UE_LOG(LogTemp, Warning, TEXT("Score Updated! Player: %d | AI: %d"), PlayerScore, AIScore);
	OnScoreChanged(PlayerScore, AIScore);
}

void AMPPongGameMode::BallReset()
{
	BallRef->OnBallResetEffect();

	BallRef->Trigger->SetPhysicsLinearVelocity(FVector::ZeroVector);
	BallRef->Trigger->SetPhysicsAngularVelocityInDegrees(FVector::ZeroVector);

	BallRef->SetActorLocation(FVector(UKismetMathLibrary::RandomFloatInRange(-300.0f, 900.0f), 0.0f, 0.0f));
	LaunchBall();
}


void AMPPongGameMode::LaunchBall()
{

	float ForceX = UKismetMathLibrary::RandomFloatInRange(-25000.0f, 25000.0f);
	float ForceY = UKismetMathLibrary::RandomBool() ? 50000.0f : -50000.0f;

	FVector LaunchForce = FVector(ForceX, ForceY, 0.0f);
	BallRef->Trigger->AddForce(LaunchForce, NAME_None, true);
}