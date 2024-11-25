
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SCGameMode.generated.h"

//enum class EObstacleType : uint8;

UCLASS()
class STEERCLEAR_API ASCGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	UPROPERTY()
	class APCGActor* PCGActor;
	//void HandlePlayerHitObstacle(const EObstacleType ObstacleType);
	void ResetPlayerLevel(const bool bNewLevel);

protected:

	FTimerHandle ResetGameTimerHandle;

	void BeginPlay() override;
};
