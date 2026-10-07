#include "BomberPlayerController.h"

#include "BomberCameraActor.h"
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
}

