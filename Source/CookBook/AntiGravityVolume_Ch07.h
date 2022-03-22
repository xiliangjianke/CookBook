// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "AntiGravityVolume_Ch07.generated.h"

UCLASS()
class COOKBOOK_API AAntiGravityVolume_Ch07 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAntiGravityVolume_Ch07();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
		UBoxComponent* CollisionComponent;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor);

	virtual void NotifyActorEndOverlap(AActor* OtherActor);

};
