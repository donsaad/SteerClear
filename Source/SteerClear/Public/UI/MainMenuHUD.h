
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainMenuHUD.generated.h"

class UMainMenuWidget;

UCLASS()
class STEERCLEAR_API AMainMenuHUD : public AHUD
{
	GENERATED_BODY()


protected:

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UMainMenuWidget> MainMenuWidgetTemplate;

	UPROPERTY()
		TObjectPtr<UMainMenuWidget> MainMenuWidget;

	void BeginPlay() override;

};
