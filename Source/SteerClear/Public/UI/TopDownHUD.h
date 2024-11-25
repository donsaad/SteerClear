

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TopDownHUD.generated.h"

/**
 *
 */
UCLASS()
class STEERCLEAR_API ATopDownHUD : public AHUD
{
	GENERATED_BODY()

public:

	void NotifyGameOver(const bool bWon);

protected:

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UGameOverWidget> GameOverWidgetTemplate;

};
