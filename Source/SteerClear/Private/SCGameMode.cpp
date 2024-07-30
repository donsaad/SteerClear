
#include "SCGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "SCTypes.h"
#include "SCGameInstance.h"

void ASCGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	if (USCGameInstance* RGI = GetGameInstance<USCGameInstance>())
	{
		RGI->PlayBGMusic();
	}
}

void ASCGameMode::ResetRacerLevel(const EObstacleType ObstacleType)
{
	float TimerDelay = 0.5;
	switch (ObstacleType)
	{
		case EObstacleType::Fence:
			TimerDelay = 1.0f;
			break;
		case EObstacleType::FinishLine:
			TimerDelay = 3.0f;
			break;
	}
	GetWorldTimerManager().SetTimer(ResetGameTimerHandle, this, &ASCGameMode::OnResetGameTimerTimeout, 1.0f);
}

void ASCGameMode::OnResetGameTimerTimeout()
{
	UGameplayStatics::OpenLevel(this, FName("MainLevel"));
}
