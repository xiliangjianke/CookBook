// Fill out your copyright notice in the Description page of Project Settings.


#include "OrbitingMovementComponent_Ch04.h"

// Sets default values for this component's properties
UOrbitingMovementComponent_Ch04::UOrbitingMovementComponent_Ch04()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	RotationSpeed = 5;
	OrbitDistance = 100;
	CurrentValue = 0;
	RotateToFaceOutwards = true;

}


// Called when the game starts
void UOrbitingMovementComponent_Ch04::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOrbitingMovementComponent_Ch04::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	float CurrentValueInRadians = FMath::DegreesToRadians<float>(CurrentValue);

	SetRelativeLocation(FVector(OrbitDistance * FMath::Cos(CurrentValueInRadians),
		OrbitDistance * FMath::Sin(CurrentValueInRadians),
		GetRelativeLocation().Z));

	if (RotateToFaceOutwards)
	{
		FVector LookDir = GetRelativeLocation().GetSafeNormal();
		FRotator LookAtRot = LookDir.Rotation();
		SetRelativeRotation((LookAtRot));
	}

	CurrentValue = FMath::Fmod(CurrentValue + (RotationSpeed * DeltaTime), 360);

}

