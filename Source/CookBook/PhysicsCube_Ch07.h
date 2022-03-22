// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "GravityObject_Ch07.h"
#include "PhysicsCube_Ch07.generated.h"

UCLASS()
class COOKBOOK_API APhysicsCube_Ch07 : public AActor, public IGravityObject_Ch07
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APhysicsCube_Ch07();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
		UStaticMeshComponent* MyMesh;

};
