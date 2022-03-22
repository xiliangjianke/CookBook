// Fill out your copyright notice in the Description page of Project Settings.


#include "AntiGravityVolume_Ch07.h"
#include "GravityObject_Ch07.h"

// Sets default values
AAntiGravityVolume_Ch07::AAntiGravityVolume_Ch07()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<UBoxComponent>("CollisionComponent");

	CollisionComponent->SetBoxExtent(FVector(200, 200, 400));
	RootComponent = CollisionComponent;

}

// Called when the game starts or when spawned
void AAntiGravityVolume_Ch07::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAntiGravityVolume_Ch07::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAntiGravityVolume_Ch07::NotifyActorBeginOverlap(AActor* OtherActor)
{
	IGravityObject_Ch07* GravityObject = Cast<IGravityObject_Ch07>(OtherActor);

	if (GravityObject != nullptr)
	{
		GravityObject->DisableGravity();
	}
}

void AAntiGravityVolume_Ch07::NotifyActorEndOverlap(AActor* OtherActor)
{
	IGravityObject_Ch07* GravityObject = Cast<IGravityObject_Ch07>(OtherActor);

	if (GravityObject != nullptr)
	{
		GravityObject->EnableGravity();
	}
}

