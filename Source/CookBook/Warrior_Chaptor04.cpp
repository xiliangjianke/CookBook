// Fill out your copyright notice in the Description page of Project Settings.


#include "Warrior_Chaptor04.h"

// Sets default values
AWarrior_Chaptor04::AWarrior_Chaptor04()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

FString AWarrior_Chaptor04::ToString()
{
	return FString::Printf(TEXT("An instance of AWarrior:%s"), *Name);
}

// Called when the game starts or when spawned
void AWarrior_Chaptor04::BeginPlay()
{
	Super::BeginPlay();

	// Will destroy this object in 10 seconds
	SetLifeSpan(10);
	
}

// Called every frame
void AWarrior_Chaptor04::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

