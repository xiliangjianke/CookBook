// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyInterface_Ch07.h"
#include "GameFramework/Actor.h"
#include "SingleInterfaceActor_Ch07.generated.h"

UCLASS()
class COOKBOOK_API ASingleInterfaceActor_Ch07 : public AActor, public IMyInterface_Ch07
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASingleInterfaceActor_Ch07();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FString GetTestName() override;

};
