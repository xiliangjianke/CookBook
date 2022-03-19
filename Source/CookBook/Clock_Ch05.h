// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Clock_Ch05.generated.h"

UCLASS()
class COOKBOOK_API AClock_Ch05 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AClock_Ch05();

	UPROPERTY()
		USceneComponent* RootSceneComponet;

	UPROPERTY()
		UStaticMeshComponent* ClockFace;

	UPROPERTY()
		USceneComponent* HourHandle;

	UPROPERTY()
		UStaticMeshComponent* HourHand;

	UPROPERTY()
		USceneComponent* MinuteHandle;

	UPROPERTY()
		UStaticMeshComponent* MinuteHand;

	UFUNCTION()
		void TimeChanged(int32 Hours, int32 Minutes);

	FDelegateHandle MyDelegateHandle;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
