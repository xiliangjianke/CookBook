// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "PickUp_Ch05.generated.h"

// Custom event
DECLARE_DELEGATE(FPickeupEventSignature)
UCLASS()
class COOKBOOK_API APickUp_Ch05 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUp_Ch05();

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	UPROPERTY()
		UStaticMeshComponent* MyMesh;

	UPROPERTY()
		URotatingMovementComponent* RotatingComponent;

	FPickeupEventSignature OnPickedUp;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
