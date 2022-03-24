// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AttackAvoider_Ch08.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UAttackAvoider_Ch08 : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class COOKBOOK_API IAttackAvoider_Ch08
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "AttackAvodier")
		void AttackIncoming(AActor* AttackActor);
};
