#include "BomberPawn.h"


ABomberPawn::ABomberPawn()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABomberPawn::BeginPlay()
{
	Super::BeginPlay();
}

void ABomberPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABomberPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

