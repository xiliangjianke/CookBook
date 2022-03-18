// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "OrbitingMovementComponent_Ch04.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COOKBOOK_API UOrbitingMovementComponent_Ch04 : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOrbitingMovementComponent_Ch04();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool RotateToFaceOutwards;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		float RotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float OrbitDistance;

	float CurrentValue;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
