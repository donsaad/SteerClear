
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SCGameInstance.generated.h"

UCLASS()
class STEERCLEAR_API USCGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	USCGameInstance(const FObjectInitializer& ObjectInitializer);

	void PlayBGMusic();

protected:

	UPROPERTY(EditDefaultsOnly)
		class USoundBase* BGMusic;

	UPROPERTY()
		UAudioComponent* BGAudioComp;
	UPROPERTY()
		bool bPLayingMusic;
};
