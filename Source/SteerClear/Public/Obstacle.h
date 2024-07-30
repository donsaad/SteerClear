
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstacle.generated.h"

enum class EObstacleType : uint8;

UCLASS()
class STEERCLEAR_API AObstacle : public AActor
{
	GENERATED_BODY()

public:
	AObstacle();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UPaperSpriteComponent* ObstacleSpriteComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USoundBase* HitSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EObstacleType ObstacleType;

	virtual void BeginPlay() override;
	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
	//virtual void Tick(float DeltaTime) override;

};
