#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BomberPawn.generated.h"

class ABomberGrid;
class USphereComponent;

UCLASS()
class BOMBERCLONE_API ABomberPawn : public APawn
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="Components")
	TObjectPtr<USphereComponent> SphereComponent;
	
	UPROPERTY(EditAnywhere, Category="Movement")
	float MovementSpeed;
	// TODO: fazer o grid ser criado pelo gamemode e receber quando criar o pawn
	UPROPERTY()
	TObjectPtr<ABomberGrid> Grid;
	
	ABomberPawn();
	
	virtual void Tick(float DeltaTime) override;
	void SetMoveInput(FVector2D PlayerMoveInput);
	virtual void BeginPlay() override;
	
private:
	FVector2D MoveInput;
};



