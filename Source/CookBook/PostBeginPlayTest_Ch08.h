// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PostBeginPlay_Ch08.h"
#include "PostBeginPlayTest_Ch08.generated.h"

UCLASS()
class COOKBOOK_API APostBeginPlayTest_Ch08 : public AActor, public IPostBeginPlay_Ch08
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APostBeginPlayTest_Ch08();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
