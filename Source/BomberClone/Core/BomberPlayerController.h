#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "BomberPlayerController.generated.h"

class ABomberPawn;
class UInputAction;

UCLASS()
class BOMBERCLONE_API ABomberPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ABomberPlayerController();
	void HandleMoveInput(const FInputActionValue& InputActionValue);
	virtual void SetupInputComponent() override;
	
	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputAction> Input_Move;
	
	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputAction> Input_Place;
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ABomberPawn> BomberPawn;
protected:
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaSeconds) override;
	
private:
	FVector2D InputMovement = FVector2D::ZeroVector;
};
