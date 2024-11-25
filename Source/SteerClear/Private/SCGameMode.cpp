
#include "SCGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "SCTypes.h"
#include "SCGameInstance.h"

void ASCGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (USCGameInstance* GI = GetGameInstance<USCGameInstance>())
	{
		GI->PlayBGMusic();
	}
}

void ASCGameMode::ResetPlayerLevel(const bool bNewLevel)
{
	/* Saad: HACK: Re-Open same level #TODO: properly reset level state */
	UGameplayStatics::OpenLevel(this, FName("MainLevel"));
}
