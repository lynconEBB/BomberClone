#include "BomberPlayerController.h"

#include "BomberCameraActor.h"
#include "BomberPawn.h"
#include "EnhancedInputComponent.h"
#include "Kismet/GameplayStatics.h"

ABomberPlayerController::ABomberPlayerController()
{
	bAutoManageActiveCameraTarget = false;
}

void ABomberPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	AActor* CameraActor = UGameplayStatics::GetActorOfClass(this, ABomberCameraActor::StaticClass());
	if (CameraActor)
		SetViewTargetWithBlend(CameraActor);
	
	BomberPawn = Cast<ABomberPawn>(GetPawn());
	if (BomberPawn == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Player controller needs Bomber Pawn!"));
	}
}


void ABomberPlayerController::HandleMoveInput(const FInputActionValue& InputActionValue)
{
	InputMovement = InputActionValue.Get<FVector2D>();		
}

void ABomberPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	
	EnhancedInputComponent->BindAction(Input_Move, ETriggerEvent::Triggered, this, &ThisClass::HandleMoveInput);
}

void ABomberPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	BomberPawn->SetMoveInput(InputMovement);
	InputMovement = FVector2D::ZeroVector;
}
