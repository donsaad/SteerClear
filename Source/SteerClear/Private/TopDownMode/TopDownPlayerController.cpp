
#include "TopDownMode/TopDownPlayerController.h"

ATopDownPlayerController::ATopDownPlayerController()
{

}

void ATopDownPlayerController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameOnly InputModeGameOnly;
	SetInputMode(InputModeGameOnly);
	SetShowMouseCursor(false);
}
