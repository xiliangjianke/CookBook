// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase_Ch07.h"
#include "SingleInterfaceActor_Ch07.h"

#include "EngineUtils.h"

void AMyGameModeBase_Ch07::BeginPlay()
{
	Super::BeginPlay();

	FTransform SpawnLocation;

	// Spawn a new actor using the singleinterfaceactor at default location
	ASingleInterfaceActor_Ch07* SpawnedActor = GetWorld()->SpawnActor<ASingleInterfaceActor_Ch07>(ASingleInterfaceActor_Ch07::StaticClass(), SpawnLocation);

	// Get a reference to the class the actor has
	UClass* ActorClass = SpawnedActor->GetClass();

	// if the class implements the interface, display a message
	if (ActorClass->ImplementsInterface(UMyInterface_Ch07::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Spawned actor implements interface!"));

	}

	for (TActorIterator<AActor> It(GetWorld(), AActor::StaticClass()); It; ++It)
	{
		AActor* Actor = *It;
		IMyInterface_Ch07* MyInterfaceInstance = Cast<IMyInterface_Ch07>(Actor);

		// If the pointer is valid, add it to the list
		if (MyInterfaceInstance)
		{
			MyInterfaceInstances.Add(MyInterfaceInstance);
		}
	}
	// Print out how many objects implement the interface
	FString Message = FString::Printf(TEXT("%d actors implement the interface"), MyInterfaceInstances.Num());

	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, Message);
}