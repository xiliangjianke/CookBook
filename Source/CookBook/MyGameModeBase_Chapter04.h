// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyFirstActor.h"
#include "MyGameModeBase_Chapter04.generated.h"

/**
 * 
 */
UCLASS()
class COOKBOOK_API AMyGameModeBase_Chapter04 : public AGameModeBase
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

	UPROPERTY()
		AMyFirstActor* SpawnedActor;

	UFUNCTION()
		void DestroyActorFunction();
	
};
