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
	
	FVector MainAxis = FVector::ZeroVector;
	FVector PerpendicularAxis = FVector::ZeroVector;
	if (MoveInput.X != 0)
	{
		MainAxis.X = MoveInput.X;	
		PerpendicularAxis.Y = 1.0f;	
	} else
	{
		MainAxis.Y = MoveInput.Y;	
		PerpendicularAxis.X = 1.0f;	
	}
	
	FVector CellCenter = Grid->WorldToCellCenter(GetActorLocation());
	
	DrawDebugSphere(GetWorld(), CellCenter, 10, 12, FColor::Blue);
	
	FVector Diff = CellCenter - GetActorLocation();	
	float MainOff = FVector::DotProduct(Diff, MainAxis);
	float PerpendicularOff = FVector::DotProduct(Diff, PerpendicularAxis);
	
	
	FHitResult Hit;
	SphereComponent->MoveComponent(MainAxis, FQuat::Identity, true, &Hit);
	if (Hit.bBlockingHit) 
		UE_LOG(LogTemp, Warning, TEXT("Bateu"));
}

void ABomberPawn::SetMoveInput(FVector2D PlayerMoveInput)
{
	MoveInput = PlayerMoveInput;
}