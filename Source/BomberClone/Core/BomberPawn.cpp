#include "BomberPawn.h"

#include "ToolBuilderUtil.h"
#include "BomberClone/World/BomberGrid.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"


ABomberPawn::ABomberPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SetRootComponent(SphereComponent);
	SphereComponent->bHiddenInGame = false;
	MovementSpeed = 10.f;
}

void ABomberPawn::BeginPlay()
{
	Super::BeginPlay();
	Grid = Cast<ABomberGrid>(UGameplayStatics::GetActorOfClass(this, ABomberGrid::StaticClass()));
	checkf(Grid != nullptr, TEXT("Bomber Pawn needs a grid"));
}

void ABomberPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (MoveInput.Length() == 0)
		return;
	
	FVector Dir = FVector::ZeroVector;
	if (MoveInput.X != 0)
		Dir.X = MoveInput.X;	
	else
		Dir.Y = MoveInput.Y;	
	
	
	FHitResult Hit;
	SphereComponent->MoveComponent(DeltaX, FQuat::Identity, true, &Hit);
	if (Hit.bBlockingHit) 
		UE_LOG(LogTemp, Warning, TEXT("Bateu"));
	
	SphereComponent->MoveComponent(DeltaY, FQuat::Identity, true, &Hit);
	if (Hit.bBlockingHit) 
		UE_LOG(LogTemp, Warning, TEXT("Bateu"));
}

void ABomberPawn::SetMoveInput(FVector2D PlayerMoveInput)
{
	MoveInput = PlayerMoveInput;
}