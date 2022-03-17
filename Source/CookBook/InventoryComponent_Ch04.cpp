// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent_Ch04.h"

// Sets default values
AInventoryComponent_Ch04::AInventoryComponent_Ch04()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

int32 AInventoryComponent_Ch04::AddToInventory(AInventoryActor* ActorToAdd)
{
	return CurrentInventory.Add(ActorToAdd);
}

void AInventoryComponent_Ch04::RemoveFromInventory(AInventoryActor* ActorToRemove)
{
	CurrentInventory.Remove(ActorToRemove);
}

// Called when the game starts or when spawned
void AInventoryComponent_Ch04::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInventoryComponent_Ch04::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

