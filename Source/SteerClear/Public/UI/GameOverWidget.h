

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOverWidget.generated.h"

class UButton;
class UTextBlock;

UCLASS()
class STEERCLEAR_API UGameOverWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(meta = (BindWidget))
	UButton* NewLevelButton;

	UPROPERTY(meta = (BindWidget))
	UButton* SameLevelButton;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* MessageTextBlock;

	UFUNCTION()
	void SameLevelButtonClicked();
	UFUNCTION()
	void NewLevelButtonClicked();

public:

	void NativeConstruct() override;
	void SetMessageText(const FString& MessageText);

};
