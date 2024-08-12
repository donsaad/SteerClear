
#include "UI/MainMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SteerBtn->OnClicked.AddDynamic(this, &UMainMenuWidget::StartGame);
	ExitBtn->OnClicked.AddDynamic(this, &UMainMenuWidget::ExitGame);

}

void UMainMenuWidget::StartGame()
{
	UGameplayStatics::OpenLevel(this, "TopDownLevel");
}

void UMainMenuWidget::ExitGame()
{
	if (APlayerController* PC = GetOwningPlayer())
	{
		PC->ConsoleCommand("quit");
	}
}
