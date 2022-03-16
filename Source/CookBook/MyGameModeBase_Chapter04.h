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

	// Constructor to initialize CurrentScore
	AMyGameModeBase_Chapter04();

	// Will set the CurrentScore variable
	UFUNCTION(BlueprintCallable, Category = "MyFunction")
		void SetScore(int32 NewScore);

	// Getter
	UFUNCTION(BlueprintCallable, Category = "MyFunction")
		int32 GetScore();

	virtual void BeginPlay() override;

	UPROPERTY()
		AMyFirstActor* SpawnedActor;

	UFUNCTION()
		void DestroyActorFunction();
private:
	UPROPERTY()
		int32 CurrentScore;

	
};
