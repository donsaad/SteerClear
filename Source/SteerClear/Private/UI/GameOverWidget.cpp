

#include "UI/GameOverWidget.h"
#include "SCGameMode.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"


void UGameOverWidget::SameLevelButtonClicked()
{
	if (UWorld* World = GetWorld())
	{
		if (ASCGameMode* GM = World->GetAuthGameMode<ASCGameMode>())
		{
			GM->ResetPlayerLevel(false);
		}
	}
}

void UGameOverWidget::NewLevelButtonClicked()
{
	if (UWorld* World = GetWorld())
	{
		if (ASCGameMode* GM = World->GetAuthGameMode<ASCGameMode>())
		{
			GM->ResetPlayerLevel(true);
		}
	}
}

void UGameOverWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (NewLevelButton)
	{
		NewLevelButton->OnClicked.AddUniqueDynamic(this, &UGameOverWidget::NewLevelButtonClicked);
	}
	if (SameLevelButton)
	{
		SameLevelButton->OnClicked.AddUniqueDynamic(this, &UGameOverWidget::SameLevelButtonClicked);
	}

}

void UGameOverWidget::SetMessageText(const FString& MessageText)
{
	if (MessageTextBlock)
	{
		MessageTextBlock->SetText(FText::FromString(MessageText));
	}
}
