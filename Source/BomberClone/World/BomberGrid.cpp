#include "BomberGrid.h"

#include "Components/InstancedStaticMeshComponent.h"


ABomberGrid::ABomberGrid()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("RootComp");
	StartCornerLocation = FVector::ZeroVector;
	CellHalf = CellSize/2;
	
	InstancedStaticMeshComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>("CornerBlocks");
	InstancedStaticMeshComponent->SetupAttachment(RootComponent);
}

void ABomberGrid::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	InstancedStaticMeshComponent->ClearInstances();
	
	CellHalf = CellSize / 2;
	StartCornerLocation = this->GetActorLocation() - FVector(Width * CellHalf,Height * CellHalf, 0);
	
	// Y = 0
	for (int32 i = 0; i <= Width - 1; i++)
	{
		FTransform trans = FTransform(CellToWorld(FIntVector2(i, 0)));
		InstancedStaticMeshComponent->AddInstance(trans, true);
	}
	// X = 0
	for (int32 i = 1; i <= Height - 1; i++)
	{
		FTransform trans = FTransform(CellToWorld(FIntVector2(0, i)));
		InstancedStaticMeshComponent->AddInstance(trans, true);
	}
	// X = Width - 1
	for (int32 i = 1; i <= Height - 1; i++)
	{
		FTransform trans = FTransform(CellToWorld(FIntVector2(Width - 1, i)));
		InstancedStaticMeshComponent->AddInstance(trans, true);
	}
	// Y = Height - 1
	for (int32 i = 1; i <= Width - 2; i++)
	{
		FTransform trans = FTransform(CellToWorld(FIntVector2(i, Height - 1)));
		InstancedStaticMeshComponent->AddInstance(trans, true);
	}
	UE_LOG(LogTemp, Warning, TEXT("Instanced Meshes size: %d"), InstancedStaticMeshComponent->GetInstanceCount())
}

bool ABomberGrid::ShouldTickIfViewportsOnly() const
{
	return true;
}

void ABomberGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!bShouldDrawDebug)
		return;
	
	FVector center = this->GetActorLocation() - FVector((Width-1) * CellHalf,(Height-1) * CellHalf, 0);
	DrawDebugSphere(GetWorld(), center, 10, 12, FColor::Green);
	for (int32 i = 0; i < Width; i++)
	{
		float ogY = center.Y;
		for (int32 j = 0; j < Height; ++j)
		{
			DrawDebugBox(GetWorld(), center, FVector(CellHalf), FColor::Red);
			center.Y += CellSize;
		}	
		center.Y = ogY;
		center.X += CellSize;
	}
}

FVector ABomberGrid::CellToWorld(FIntVector2 Position)
{
	FVector center = this->GetActorLocation() - FVector((Width-1) * CellHalf,(Height-1) * CellHalf, 0);
	center.X += CellSize * Position.X;
	center.Y += CellSize * Position.Y;
	
	return center;
}

FIntVector2 ABomberGrid::WorldToCell(FVector WorldPosition)
{
	FVector Index = (WorldPosition - StartCornerLocation) / CellSize;
	return FIntVector2(Index.X, Index.Y);
}

FVector ABomberGrid::WorldToCellCenter(FVector WorldPosition)
{
	FIntVector2 Index = WorldToCell(WorldPosition);
	return CellToWorld(Index);
}
