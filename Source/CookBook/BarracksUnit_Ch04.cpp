// Fill out your copyright notice in the Description page of Project Settings.


#include "BarracksUnit_Ch04.h"

// Sets default values
ABarracksUnit_Ch04::ABarracksUnit_Ch04()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnPoint = CreateDefaultSubobject<UParticleSystemComponent>("SpawnPoint");

	auto ParticleSystem = ConstructorHelpers::FObjectFinder<UParticleSystem>(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));

	if (ParticleSystem.Object)
	{
		SpawnPoint->SetTemplate(ParticleSystem.Object);
	}

	SpawnPoint->SetRelativeScale3D(FVector(0.5, 0.5, 0.5));

	SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;



}

// Called when the game starts or when spawned
void ABarracksUnit_Ch04::BeginPlay()
{
	Super::BeginPlay();

	SpawnPoint->AttachTo(RootComponent);
	
}

// Called every frame
void ABarracksUnit_Ch04::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(GetActorLocation() + FVector(10, 0, 0));

}

// Called to bind functionality to input
void ABarracksUnit_Ch04::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

