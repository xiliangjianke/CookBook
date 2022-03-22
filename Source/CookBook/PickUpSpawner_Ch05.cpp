// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpSpawner_Ch05.h"

// Sets default values
APickUpSpawner_Ch05::APickUpSpawner_Ch05()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnLocation = CreateDefaultSubobject<USceneComponent>("SpawnLocation");

}

void APickUpSpawner_Ch05::PickupCollected()
{
	GetWorld()->GetTimerManager().SetTimer(MyTimer, this, &APickUpSpawner_Ch05::SpawnPickup, 10, false);

	CurrentPickup->OnPickedUp.Unbind();
	CurrentPickup->Destroy();
}

void APickUpSpawner_Ch05::SpawnPickup()
{
	UWorld* MyWorld = GetWorld();

	if (MyWorld != nullptr)
	{
		CurrentPickup = MyWorld->SpawnActor<APickUp_Ch05>(APickUp_Ch05::StaticClass(), GetTransform());

		CurrentPickup->OnPickedUp.BindUObject(this, &APickUpSpawner_Ch05::PickupCollected);
	}
}

// Called when the game starts or when spawned
void APickUpSpawner_Ch05::BeginPlay()
{
	Super::BeginPlay();

	SpawnPickup();
	
}

// Called every frame
void APickUpSpawner_Ch05::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

