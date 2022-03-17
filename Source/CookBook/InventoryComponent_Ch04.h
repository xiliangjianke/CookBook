// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InventoryActor.h"
#include "InventoryComponent_Ch04.generated.h"

UCLASS()
class COOKBOOK_API AInventoryComponent_Ch04 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInventoryComponent_Ch04();

	UPROPERTY()
		TArray<AInventoryActor*> CurrentInventory;

	UFUNCTION()
		int32 AddToInventory(AInventoryActor* ActorToAdd);

	UFUNCTION()
		void RemoveFromInventory(AInventoryActor* ActorToRemove);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
