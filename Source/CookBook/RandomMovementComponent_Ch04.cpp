// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomMovementComponent_Ch04.h"

// Sets default values for this component's properties
URandomMovementComponent_Ch04::URandomMovementComponent_Ch04()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	MovementRadius = 5.f;
}


// Called when the game starts
void URandomMovementComponent_Ch04::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URandomMovementComponent_Ch04::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	AActor* Parent = GetOwner();

	if (Parent)
	{
		// Find a new position for the object to go to
		auto NewPos = Parent->GetActorLocation() + FVector(
			FMath::FRandRange(-1, 1) * MovementRadius,
			FMath::FRandRange(-1, 1) * MovementRadius,
			FMath::FRandRange(-1, 1) * MovementRadius
		);
		// update the object's position
		Parent->SetActorLocation(NewPos);
	}
}

