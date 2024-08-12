

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

class UButton;

UCLASS()
class STEERCLEAR_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	// play or start button
	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UButton> SteerBtn;
	UPROPERTY(meta = (BindWidgetOptional))
		TObjectPtr<UButton> GarageBtn;
	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UButton> ExitBtn;

	void NativeConstruct() override;
	UFUNCTION()
		void StartGame();
	UFUNCTION()
		void ExitGame();

public:
};
