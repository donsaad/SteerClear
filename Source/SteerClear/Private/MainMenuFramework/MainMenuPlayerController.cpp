
#include "MainMenuFramework/MainMenuPlayerController.h"

void AMainMenuPlayerController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeUIOnly InputModeUI;
	SetInputMode(InputModeUI);
}
