// Fill out your copyright notice in the Description page of Project Settings.


#include "PhysicsCube_Ch07.h"

// Sets default values
APhysicsCube_Ch07::APhysicsCube_Ch07()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>("MyMesh");

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Ch07/Shape_Cube.Shape_Cube'"));

	if (MeshAsset.Object != nullptr)
	{
		MyMesh->SetStaticMesh(MeshAsset.Object);
	}

	MyMesh->SetMobility(EComponentMobility::Movable);
	MyMesh->SetSimulatePhysics(true);
	SetActorEnableCollision(true);

}

// Called when the game starts or when spawned
void APhysicsCube_Ch07::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APhysicsCube_Ch07::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

