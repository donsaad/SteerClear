

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PCGActor.generated.h"

class UPCGComponent;
class USplineComponent;

UCLASS()
class STEERCLEAR_API APCGActor : public AActor
{
	GENERATED_BODY()

public:
	APCGActor();
	int32 GetCurrentSeed() const;
protected:

	UPROPERTY(EditAnywhere)
	TObjectPtr <USceneComponent> DefaultSceneComp;
	UPROPERTY(EditAnywhere)
	TObjectPtr <UPCGComponent> PCGComp;
	UPROPERTY(EditAnywhere)
	TObjectPtr <USplineComponent> SplineComp;

	virtual void BeginPlay() override;
	/* #TODO: guarantee unique seed */
	void RegenerateWithRandomSeed();

public:

};
