// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerVolEventListener_Ch05.h"

// Sets default values
ATriggerVolEventListener_Ch05::ATriggerVolEventListener_Ch05()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");
	RootComponent = PointLight;

}

void ATriggerVolEventListener_Ch05::OnTriggerEvent()
{
	PointLight->SetLightColor(FLinearColor(0, 1, 0, 1));
}

// Called when the game starts or when spawned
void ATriggerVolEventListener_Ch05::BeginPlay()
{
	Super::BeginPlay();

	if (TriggerEventSource != nullptr)
	{
		TriggerEventSource->OnplayerEntered.AddUObject(this, &ATriggerVolEventListener_Ch05::OnTriggerEvent);
	}
	
}

// Called every frame
void ATriggerVolEventListener_Ch05::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

