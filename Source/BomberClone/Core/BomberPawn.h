#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BomberPawn.generated.h"

UCLASS()
class BOMBERCLONE_API ABomberPawn : public APawn
{
	GENERATED_BODY()

public:
	ABomberPawn();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
