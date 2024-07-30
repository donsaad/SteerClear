
#include "PlayerPawn.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "PaperSpriteComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

APlayerPawn::APlayerPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComp"));
	if (CapsuleComp)
	{
		SetRootComponent(CapsuleComp);
		SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
		if (SpringArmComp)
		{
			SpringArmComp->SetupAttachment(RootComponent);
			CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
			if (CameraComp)
				CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
		}
		CarSpriteComp = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("CarSpriteComp"));
		if (CarSpriteComp)
			CarSpriteComp->SetupAttachment(RootComponent);
	}

	MovementSpeed = 1000.0f;
	RotationSpeed = 100.0f;
	bCanMove = true;
}

void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PC = GetController<APlayerController>())
	{
		if (ULocalPlayer* LocalPlayer = PC->GetLocalPlayer())
		{
			if (UEnhancedInputLocalPlayerSubsystem* InputSubSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
			{
				InputSubSystem->AddMappingContext(InputMappingContext, 0);
			}
		}
	}
}

void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComp = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComp->BindAction(MoveInputAction, ETriggerEvent::Triggered, this, &APlayerPawn::Move);
	}
}

void APlayerPawn::Move(const FInputActionValue& Value)
{
	if (bCanMove)
	{
		FVector2D MoveActionVal = Value.Get<FVector2D>();
		bool bWantsToMove = abs(MoveActionVal.Y) > 0.0f; // W or S is pressed
		if (bWantsToMove)
		{
			float DeltaTime = GetWorld()->DeltaTimeSeconds;
			bool bWantsToRotate = abs(MoveActionVal.X) > 0.0f; // A or D is pressed
			const bool bMovingBackwards = MoveActionVal.Y < 0.0f;
			if (bWantsToRotate)
			{
				float PitchRot = -RotationSpeed * MoveActionVal.X * DeltaTime;
				if (bMovingBackwards)
					PitchRot *= -1;
				AddActorWorldRotation(FRotator(PitchRot, 0.0f, 0.0f));
			}
			float FinalMovementSpeed = MovementSpeed;
			if (bMovingBackwards)
				FinalMovementSpeed *= 0.5f;
			FVector DistanceToMove = GetActorUpVector() * FinalMovementSpeed * MoveActionVal.Y * DeltaTime;
			SetActorLocation(GetActorLocation() + DistanceToMove);
		}
	}
}
