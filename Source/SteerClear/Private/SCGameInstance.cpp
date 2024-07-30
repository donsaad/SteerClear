
#include "SCGameInstance.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"

USCGameInstance::USCGameInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bPLayingMusic = false;
}

void USCGameInstance::PlayBGMusic()
{
	if (!bPLayingMusic)
	{
		BGAudioComp = UGameplayStatics::SpawnSound2D(this, BGMusic, 0.2f, 1.0f, 0.0f, nullptr, true, false);
		bPLayingMusic = true;
	}
}
