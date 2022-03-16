// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorSpawnerComponent_ch04.h"

// Sets default values for this component's properties
UActorSpawnerComponent_ch04::UActorSpawnerComponent_ch04()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UActorSpawnerComponent_ch04::Spawn()
{
	UWorld* TheWorld = GetWorld();
	AActor* temp;
	if (TheWorld != nullptr)
	{
		FTransform ComponentTransform(this->GetComponentTransform());
		 temp = TheWorld->SpawnActor(ActorToSpawn, &ComponentTransform);
		
		 /*
		 // destroy actor
		 FTimerHandle TempHandle;
		 FTimerDynamicDelegate EventTest;
		 EventTest.BindDynamic(this, &UActorSpawnerComponent_ch04::Spawn);

		 GetWorld()->GetTimerManager().SetTimer(TempHandle, EventTest, 2, true);

		 if (temp != nullptr)
		 {
			 temp->Destroy();
			 UE_LOG(LogTemp, Warning, TEXT("Destroy Actor!!!"))
		 }
		 */
		

		
	}

	
	//GetWorldTimerManager().SetTimer(TempHandle, this, &AMyActor::TimerElapsed, 5, false);




	
}

// Called when the game starts
void UActorSpawnerComponent_ch04::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UActorSpawnerComponent_ch04::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

