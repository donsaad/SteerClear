
#include "UI/TopDownHUD.h"
#include "UI/GameOverWidget.h"


void ATopDownHUD::NotifyGameOver(const bool bWon)
{
	if (APlayerController* PC = GetOwningPlayerController())
	{
		FInputModeUIOnly InputModeUIOnly;
		PC->SetInputMode(InputModeUIOnly);
		PC->SetShowMouseCursor(true);
		UGameOverWidget* GameOverWidget = CreateWidget<UGameOverWidget>(PC, GameOverWidgetTemplate);
		if (GameOverWidget)
		{
			GameOverWidget->SetMessageText(FString::Printf(TEXT("You %s the level! Do you want to start a new level?"), (bWon ? TEXT("passed") : TEXT("failed"))));
			GameOverWidget->AddToViewport();
		}
	}
}
