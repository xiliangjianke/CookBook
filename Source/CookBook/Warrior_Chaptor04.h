// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Warrior_Chaptor04.generated.h"

UCLASS()
class COOKBOOK_API AWarrior_Chaptor04 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWarrior_Chaptor04();

	// Name of the actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		FString Name;

	// Return message containing the name property
	UFUNCTION(BlueprintCallable, Category = "Properties")
		FString ToString();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
