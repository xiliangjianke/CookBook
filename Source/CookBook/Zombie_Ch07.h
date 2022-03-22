// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Undead_Ch07.h"
#include "Zombie_Ch07.generated.h"

UCLASS()
class COOKBOOK_API AZombie_Ch07 : public AActor, public IUndead_Ch07
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AZombie_Ch07();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
