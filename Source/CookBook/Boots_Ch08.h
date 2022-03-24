// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Wearable_Ch08.h"
#include "Boots_Ch08.generated.h"

UCLASS()
class COOKBOOK_API ABoots_Ch08 : public AActor, public IWearable_Ch08
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoots_Ch08();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Implementing the functions needed for IWearable
	virtual void OnEquip_Implementation(APawn* Wearer)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "Item being worn");
	}

	virtual bool CanEquip_Implementation(APawn* Wearer)
	{
		return true;
	}

	virtual int32 GetStrengthRequirement_Implementation() override
	{
		return 0;
	}
};
