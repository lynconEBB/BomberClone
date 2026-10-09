#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BomberPawn.generated.h"

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
	
	ABomberPawn();
	
	virtual void Tick(float DeltaTime) override;

	void SetMoveInput(FVector2D PlayerMoveInput);
	
private:
	FVector2D MoveInput;
};
