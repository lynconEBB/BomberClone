#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BomberGrid.generated.h"

class UInstancedStaticMeshComponent;

UCLASS()
class BOMBERCLONE_API ABomberGrid : public AActor
{
	GENERATED_BODY()
protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	TObjectPtr<UInstancedStaticMeshComponent> InstancedStaticMeshComponent;
	
private:
	UPROPERTY(EditAnywhere, Category = "Grid")
	int32 Width = 13;
	
	UPROPERTY(EditAnywhere, Category = "Grid")
	int32 Height = 13;
	
	UPROPERTY(EditAnywhere, Category = "Grid")
	int32 CellSize = 100.f;
	
	UPROPERTY(EditAnywhere, Category = "Grid")
	bool bShouldDrawDebug;

public:
	ABomberGrid();
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual bool ShouldTickIfViewportsOnly() const override;
	virtual void Tick(float DeltaTime) override;
	
	FVector CellToWorld(FIntVector2 Position);
};
