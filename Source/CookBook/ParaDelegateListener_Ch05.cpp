// Fill out your copyright notice in the Description page of Project Settings.


#include "ParaDelegateListener_Ch05.h"
#include "GameModeBase_Ch05.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AParaDelegateListener_Ch05::AParaDelegateListener_Ch05()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight"));
	RootComponent = PointLight;


}

void AParaDelegateListener_Ch05::SetLightColor(FLinearColor LightColor, bool EnableLight)
{
	PointLight->SetLightColor(LightColor);
	PointLight->SetVisibility(EnableLight);
}

// Called when the game starts or when spawned
void AParaDelegateListener_Ch05::BeginPlay()
{
	Super::BeginPlay();

	UWorld* TheWorld = GetWorld();

	if (TheWorld != nullptr)
	{
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(TheWorld);
		AGameModeBase_Ch05* MyGameMode = Cast<AGameModeBase_Ch05>(GameMode);

		if (MyGameMode != nullptr)
		{
			MyGameMode->MyParameterDelegate.BindUObject(this, &AParaDelegateListener_Ch05::SetLightColor, false);
		}
	}
	
}

// Called every frame
void AParaDelegateListener_Ch05::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

