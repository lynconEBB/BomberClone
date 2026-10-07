#include "BomberCameraActor.h"

#include "Camera/CameraComponent.h"


// Sets default values
ABomberCameraActor::ABomberCameraActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCameraComponent()->bConstrainAspectRatio = false;
}

// Called when the game starts or when spawned
void ABomberCameraActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABomberCameraActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

