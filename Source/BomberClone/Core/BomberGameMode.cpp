#include "BomberGameMode.h"

#include "BomberPawn.h"
#include "BomberPlayerController.h"

ABomberGameMode::ABomberGameMode()
{
	DefaultPawnClass = ABomberPawn::StaticClass();	
	PlayerControllerClass = ABomberPlayerController::StaticClass();
}
