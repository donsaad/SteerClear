
#include "PCG/PCGActor.h"
#include "Components/SplineComponent.h"
#include "PCGComponent.h"

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

void APCGActor::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(PCGComp))
	{
		PCGComp->Seed = FMath::RandRange(1, 2000);
		PCGComp->Cleanup(true);
		PCGComp->Generate(true);
	}
}

