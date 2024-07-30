
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SCGameMode.generated.h"

enum class EObstacleType : uint8;

UCLASS()
class STEERCLEAR_API ASCGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	void ResetRacerLevel(const EObstacleType ObstacleType);
	void OnResetGameTimerTimeout();

protected:
	
	FTimerHandle ResetGameTimerHandle;

	void BeginPlay() override;

};
