#include "BomberPawn.h"

#include "Components/SphereComponent.h"


ABomberPawn::ABomberPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SetRootComponent(SphereComponent);
	SphereComponent->bHiddenInGame = false;
	MovementSpeed = 10.f;
}

void ABomberPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector Delta = FVector(MoveInput.X, MoveInput.Y, 0.f);
	Delta *= DeltaTime * MovementSpeed;
	FHitResult Hit;
	SphereComponent->MoveComponent(Delta, FQuat::Identity, true, &Hit);
	if (Hit.bBlockingHit) 
		UE_LOG(LogTemp, Warning, TEXT("Bateu"));
}

void ABomberPawn::SetMoveInput(FVector2D PlayerMoveInput)
{
	MoveInput = PlayerMoveInput;
}