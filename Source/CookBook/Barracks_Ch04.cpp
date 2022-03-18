// Fill out your copyright notice in the Description page of Project Settings.


#include "Barracks_Ch04.h"
#include "Particles/ParticleSystemComponent.h"
#include "BarracksUnit_Ch04.h"

// Sets default values
ABarracks_Ch04::ABarracks_Ch04()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BuildingMesh = CreateDefaultSubobject<UStaticMeshComponent>("BuildingMesh");

	SpawnPoint = CreateDefaultSubobject<UParticleSystemComponent>("SpawnPoint");

	SpawnInterval = 10;

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Chapter04/Shape_Cube.Shape_Cube'"));

	if (MeshAsset.Object != nullptr)
	{
		BuildingMesh->SetStaticMesh(MeshAsset.Object);
	}

	auto ParticleSystem = ConstructorHelpers::FObjectFinder<UParticleSystem>(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));

	if (ParticleSystem.Object != nullptr)
	{
		SpawnPoint->SetTemplate(ParticleSystem.Object);
	}

	SpawnPoint->SetRelativeScale3D(FVector(0.5, 0.5, 0.5));
	UnitToSpawn = ABarracksUnit_Ch04::StaticClass();

}

// Called when the game starts or when spawned
void ABarracks_Ch04::BeginPlay()
{
	Super::BeginPlay();

	RootComponent = BuildingMesh;
	SpawnPoint->AttachTo(RootComponent);
	SpawnPoint->SetRelativeLocation(FVector(150, 0, 0));
	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ABarracks_Ch04::SpawnUnit, SpawnInterval, true);

	
}

// Called every frame
void ABarracks_Ch04::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABarracks_Ch04::SpawnUnit()
{
	FVector SpawnLocation = SpawnPoint->GetComponentLocation();
	GetWorld()->SpawnActor(UnitToSpawn, &SpawnLocation);
}

void ABarracks_Ch04::EndPlay(const EEndPlayReason::Type EEndPlayReason)
{
	Super::EndPlay(EEndPlayReason);
	GetWorld()->GetTimerManager().ClearTimer(SpawnTimerHandle);

}

