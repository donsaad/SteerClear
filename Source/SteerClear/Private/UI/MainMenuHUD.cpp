
#include "UI/MainMenuHUD.h"
#include "UI/MainMenuWidget.h"

void AMainMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	MainMenuWidget = CreateWidget<UMainMenuWidget>(PlayerOwner, MainMenuWidgetTemplate);
	if (MainMenuWidget)
	{
		MainMenuWidget->AddToViewport();
	}
}
