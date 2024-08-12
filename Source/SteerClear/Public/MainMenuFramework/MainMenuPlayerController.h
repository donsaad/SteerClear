

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainMenuPlayerController.generated.h"

/**
 *
 */
UCLASS()
class STEERCLEAR_API AMainMenuPlayerController : public APlayerController
{
	GENERATED_BODY()


protected:

	void BeginPlay() override;

};
