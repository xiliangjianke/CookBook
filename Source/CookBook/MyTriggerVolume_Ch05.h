// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "MyTriggerVolume_Ch05.generated.h"

// CustomEvent
DECLARE_EVENT(AMyTriggerVolume_Ch05, FPlayerEntered)
UCLASS()
class COOKBOOK_API AMyTriggerVolume_Ch05 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyTriggerVolume_Ch05();
	
	UPROPERTY()
		UBoxComponent* TriggerZone;

	UFUNCTION()
		virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	UFUNCTION()
		virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	// Instance of declared event
	FPlayerEntered OnplayerEntered;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
