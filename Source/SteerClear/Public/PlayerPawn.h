
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

UCLASS()
class STEERCLEAR_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UCameraComponent* CameraComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UPaperSpriteComponent* CarSpriteComp;

	UPROPERTY(EditAnywhere)
		class UInputMappingContext* InputMappingContext;
	UPROPERTY(EditAnywhere)
		class UInputAction* MoveInputAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MovementSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RotationSpeed;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		bool bCanMove;

	APlayerPawn();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void Move(const struct FInputActionValue& Value);

};
