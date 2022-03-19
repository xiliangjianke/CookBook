// Fill out your copyright notice in the Description page of Project Settings.


#include "MulticastListener_Ch05.h"
#include "GameModeBase_Ch05.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMulticastListener_Ch05::AMulticastListener_Ch05()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");
	RootComponent = PointLight;

}

void AMulticastListener_Ch05::ToggleLight()
{
	PointLight->ToggleVisibility();
}

void AMulticastListener_Ch05::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	UWorld* TheWorld = GetWorld();
	AGameModeBase* GameMode = UGameplayStatics::GetGameMode(TheWorld);
	AGameModeBase_Ch05* MyGameMode = Cast<AGameModeBase_Ch05>(GameMode);

	if (MyGameMode != nullptr)
	{
		MyGameMode->MyMulticastDelegate.Remove(MyDelegateHandle);

	}
}

// Called when the game starts or when spawned
void AMulticastListener_Ch05::BeginPlay()
{
	Super::BeginPlay();
	UWorld* TheWorld = GetWorld();

	if (TheWorld != nullptr)
	{
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(TheWorld);
		AGameModeBase_Ch05* MyGameMode = Cast<AGameModeBase_Ch05>(GameMode);

		if (MyGameMode != nullptr)
		{
			MyDelegateHandle = MyGameMode->MyMulticastDelegate.AddUObject(this, &AMulticastListener_Ch05::ToggleLight);

		}
	}
	
}

// Called every frame
void AMulticastListener_Ch05::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

