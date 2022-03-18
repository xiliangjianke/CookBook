// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/PointLightComponent.h"
#include "DelegateListener_Ch05.generated.h"

UCLASS()
class COOKBOOK_API ADelegateListener_Ch05 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADelegateListener_Ch05();

	UFUNCTION()
		void EnableLight();

	UPROPERTY()
		UPointLightComponent* PointLight;

	UFUNCTION()
		virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
