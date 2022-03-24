// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DefaultPawn.h"
#include "Components/BoxComponent.h"
#include "TalkingPawn_Ch08.generated.h"

/**
 * 
 */
UCLASS()
class COOKBOOK_API ATalkingPawn_Ch08 : public ADefaultPawn
{
	GENERATED_BODY()
public:
	ATalkingPawn_Ch08();

	UPROPERTY()
		UBoxComponent* TalkCollider;

	UFUNCTION()
		void OnTalkOverlap(UPrimitiveComponent* OverlapperdComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	
};
