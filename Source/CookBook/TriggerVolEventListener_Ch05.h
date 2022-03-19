// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/PointLightComponent.h"
#include "MyTriggerVolume_Ch05.h"
#include "TriggerVolEventListener_Ch05.generated.h"

UCLASS()
class COOKBOOK_API ATriggerVolEventListener_Ch05 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATriggerVolEventListener_Ch05();

	UPROPERTY()
		UPointLightComponent* PointLight;

	UPROPERTY(EditAnywhere)
		AMyTriggerVolume_Ch05* TriggerEventSource;

	UFUNCTION()
		void OnTriggerEvent();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
