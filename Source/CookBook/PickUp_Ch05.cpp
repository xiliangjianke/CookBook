// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUp_Ch05.h"


// Sets default values
APickUp_Ch05::APickUp_Ch05()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>("MyMesh");
	RootComponent = MyMesh;

	RotatingComponent = CreateDefaultSubobject<URotatingMovementComponent>("RotatingComponent");

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Ch05/Shape_Cube.Shape_Cube'"));

	if (MeshAsset.Object != nullptr)
	{
		MyMesh->SetStaticMesh(MeshAsset.Object);
	}

	MyMesh->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	RotatingComponent->RotationRate = FRotator(10, 0, 10);

}

void APickUp_Ch05::NotifyActorBeginOverlap(AActor* OtherActor)
{
	OnPickedUp.ExecuteIfBound();
}

// Called when the game starts or when spawned
void APickUp_Ch05::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickUp_Ch05::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

