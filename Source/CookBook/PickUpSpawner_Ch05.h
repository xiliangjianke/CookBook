// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUp_Ch05.h"
#include "PickUpSpawner_Ch05.generated.h"

UCLASS()
class COOKBOOK_API APickUpSpawner_Ch05 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUpSpawner_Ch05();

	UPROPERTY()
		USceneComponent* SpawnLocation;

	UFUNCTION()
		void PickupCollected();

	UFUNCTION()
		void SpawnPickup();

	UPROPERTY()
		APickUp_Ch05* CurrentPickup;

	FTimerHandle MyTimer;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
