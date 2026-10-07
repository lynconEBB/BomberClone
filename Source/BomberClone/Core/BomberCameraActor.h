// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "BomberCameraActor.generated.h"

UCLASS()
class BOMBERCLONE_API ABomberCameraActor : public ACameraActor
{
	GENERATED_BODY()

public:
	ABomberCameraActor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
