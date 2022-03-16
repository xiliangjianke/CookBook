// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase_Chapter04.h"
#include "MyFirstActor.h"



AMyGameModeBase_Chapter04::AMyGameModeBase_Chapter04()
{
	CurrentScore = 0;
}

void AMyGameModeBase_Chapter04::SetScore(int32 NewScore)
{
	CurrentScore = NewScore;
}

int32 AMyGameModeBase_Chapter04::GetScore()
{
	return CurrentScore;
}

void AMyGameModeBase_Chapter04::BeginPlay()
{
	// Call the parent class version of this function
	Super::BeginPlay();

	// Display a red message on the screen fro 10 seconds
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Actor Spawning"));

	// default location
	FTransform SpawnLoction;
	SpawnedActor = GetWorld()->SpawnActor<AMyFirstActor>(AMyFirstActor::StaticClass(), SpawnLoction);

	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this, &AMyGameModeBase_Chapter04::DestroyActorFunction, 10);

}

void AMyGameModeBase_Chapter04::DestroyActorFunction()
{
	if (SpawnedActor != nullptr)
	{
		// Display a red message on the screen for 10 seconds
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Actor Destroyed"));

		SpawnedActor->Destroy();
	}
}

