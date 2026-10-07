#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BomberPlayerController.generated.h"

UCLASS()
class BOMBERCLONE_API ABomberPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ABomberPlayerController();
	virtual void BeginPlay() override;
};
