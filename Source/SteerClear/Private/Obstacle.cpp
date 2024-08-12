
#include "Obstacle.h"
#include "PaperSpriteComponent.h"
#include "Components/CapsuleComponent.h"
#include "PlayerPawn.h"
#include "SCGameMode.h"
#include "SCTypes.h"
#include "Kismet/GameplayStatics.h"

AObstacle::AObstacle()
{
	PrimaryActorTick.bCanEverTick = false;
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>("CapsuleComp");
	if (CapsuleComp)
	{
		SetRootComponent(CapsuleComp);
		ObstacleSpriteComp = CreateDefaultSubobject<UPaperSpriteComponent>("SpriteComp");
		if (ObstacleSpriteComp)
		{
			ObstacleSpriteComp->SetupAttachment(RootComponent);
		}
	}
	ObstacleType = EObstacleType::Fence;
}

void AObstacle::BeginPlay()
{
	Super::BeginPlay();

	if (CapsuleComp)
	{
		CapsuleComp->OnComponentBeginOverlap.AddDynamic(this, &AObstacle::OnBeginOverlap);
	}

}

void AObstacle::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// overlapping player
	if (APlayerPawn* PlayerPawn = Cast<APlayerPawn>(OtherActor))
	{
		if (PlayerPawn->bCanMove)
		{
			PlayerPawn->bCanMove = false;
			UGameplayStatics::PlaySound2D(this, HitSound);
			if (UWorld* World = GetWorld())
			{
				if (ASCGameMode* GM = World->GetAuthGameMode<ASCGameMode>())
				{
					GM->ResetTopDownLevel(ObstacleType);
				}
			}
		}
	}
}
