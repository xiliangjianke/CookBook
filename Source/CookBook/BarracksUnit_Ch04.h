// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Particles/ParticleSystemComponent.h"
#include "BarracksUnit_Ch04.generated.h"

UCLASS()
class COOKBOOK_API ABarracksUnit_Ch04 : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABarracksUnit_Ch04();

	UPROPERTY()
		UParticleSystemComponent* SpawnPoint;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
