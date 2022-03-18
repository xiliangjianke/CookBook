// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTriggerVolume_Ch05.h"
#include "GameModeBase_Ch05.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMyTriggerVolume_Ch05::AMyTriggerVolume_Ch05()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a new component for the instance and initialize it
	TriggerZone = CreateDefaultSubobject<UBoxComponent>("TriggerZone");
	TriggerZone->SetBoxExtent(FVector(200, 200, 200));
	TriggerZone->bHiddenInGame = false;

}

void AMyTriggerVolume_Ch05::NotifyActorBeginOverlap(AActor* OtherActor)
{
	auto Message = FString::Printf(TEXT("%s entered me"), *(OtherActor)->GetName());

	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Message);

	// Call our delegate
	UWorld* TheWorld = GetWorld();

	if (TheWorld != nullptr)
	{
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(TheWorld);
		AGameModeBase_Ch05* MyGameMode = Cast<AGameModeBase_Ch05>(GameMode);

		if (MyGameMode != nullptr)
		{
			MyGameMode->MyStandardDelegate.ExecuteIfBound();

			// Call the function using a parameter
			auto Color = FLinearColor(1, 0, 0, 1);
			MyGameMode->MyParameterDelegate.ExecuteIfBound(Color);
		}
	}
}

void AMyTriggerVolume_Ch05::NotifyActorEndOverlap(AActor* OtherActor)
{
	auto Message = FString::Printf(TEXT("%s left me"), *(OtherActor)->GetName());

	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Message);
}

// Called when the game starts or when spawned
void AMyTriggerVolume_Ch05::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTriggerVolume_Ch05::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

