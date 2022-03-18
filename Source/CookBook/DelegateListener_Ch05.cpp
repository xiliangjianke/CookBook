// Fill out your copyright notice in the Description page of Project Settings.


#include "DelegateListener_Ch05.h"
#include "GameModeBase_Ch05.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADelegateListener_Ch05::ADelegateListener_Ch05()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a point light
	PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLihgt");
	RootComponent = PointLight;

	// Turn it off at the beginning so we can turn it on later
	PointLight->SetVisibility(false);

	// set the color
	PointLight->SetLightColor(FLinearColor::Blue);


}

void ADelegateListener_Ch05::EnableLight()
{
	PointLight->SetVisibility(true);
	UE_LOG(LogTemp, Warning, TEXT("EnableLight!"))
}

void ADelegateListener_Ch05::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	UWorld* TheWorld = GetWorld();

	if (TheWorld != nullptr)
	{
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(TheWorld);
		AGameModeBase_Ch05* MyGameMode = Cast<AGameModeBase_Ch05>(GameMode);

		if (MyGameMode != nullptr)
		{
			MyGameMode->MyStandardDelegate.Unbind();
		}
	}
}

// Called when the game starts or when spawned
void ADelegateListener_Ch05::BeginPlay()
{
	Super::BeginPlay();

	UWorld* TheWorld = GetWorld();

	if (TheWorld != nullptr)
	{
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(TheWorld);

		AGameModeBase_Ch05* MyGameMode = Cast<AGameModeBase_Ch05>(GameMode);
		if (MyGameMode != nullptr)
		{
			MyGameMode->MyStandardDelegate.BindUObject(this, &ADelegateListener_Ch05::EnableLight);

		}
	}
	
}

// Called every frame
void ADelegateListener_Ch05::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

