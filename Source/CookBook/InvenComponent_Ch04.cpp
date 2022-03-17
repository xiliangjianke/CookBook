// Fill out your copyright notice in the Description page of Project Settings.


#include "InvenComponent_Ch04.h"

// Sets default values for this component's properties
UInvenComponent_Ch04::UInvenComponent_Ch04()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


int32 UInvenComponent_Ch04::AddToInventory(AInventoryActor* ActorToAdd)
{
	return CurrentInventory.Add(ActorToAdd);
}

void UInvenComponent_Ch04::RemoveFromInventory(AInventoryActor* ActorToRemove)
{
	CurrentInventory.Remove(ActorToRemove);
}

// Called when the game starts
void UInvenComponent_Ch04::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInvenComponent_Ch04::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

