
#include "PCG/PCGActor.h"
#include "Components/SplineComponent.h"
#include "PCGComponent.h"
#include "SCGameMode.h"

APCGActor::APCGActor()
{
	PrimaryActorTick.bCanEverTick = false;
	DefaultSceneComp = CreateDefaultSubobject<USceneComponent>("DefaultSceneComp");
	if (IsValid(DefaultSceneComp))
	{
		SetRootComponent(DefaultSceneComp);
		SplineComp = CreateDefaultSubobject<USplineComponent>("SplineComp");
		if (IsValid(SplineComp))
			SplineComp->SetupAttachment(RootComponent);
	}
	PCGComp = CreateDefaultSubobject<UPCGComponent>("PCGComp");
}

int32 APCGActor::GetCurrentSeed() const
{
	return PCGComp ? PCGComp->Seed : 42;
}

void APCGActor::BeginPlay()
{
	Super::BeginPlay();

	RegenerateWithRandomSeed();

	if (UWorld* World = GetWorld())
	{
		if (ASCGameMode* GM = World->GetAuthGameMode<ASCGameMode>())
		{
			GM->PCGActor = this;
		}
	}
}

void APCGActor::RegenerateWithRandomSeed()
{
	if (IsValid(PCGComp))
	{
		PCGComp->Seed = FMath::RandRange(1, 2000);
		PCGComp->Cleanup(true);
		PCGComp->Generate(true);
	}
}

