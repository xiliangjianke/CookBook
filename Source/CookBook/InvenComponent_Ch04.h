// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryActor.h"
#include "InvenComponent_Ch04.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COOKBOOK_API UInvenComponent_Ch04 : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInvenComponent_Ch04();

	UPROPERTY()
		TArray<AInventoryActor*> CurrentInventory;

	UFUNCTION()
		int32 AddToInventory(AInventoryActor* ActorToAdd);

	UFUNCTION()
		void RemoveFromInventory(AInventoryActor* ActorToRemove);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
