// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Killable_Ch07.generated.h"

// This class does not need to be modified.
//UINTERFACE(MinimalAPI)
UINTERFACE(meta = (CannotImplementInterfaceInBlueprint))
class UKillable_Ch07 : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class COOKBOOK_API IKillable_Ch07
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, Category = "Killable")
		virtual bool IsDead();

	UFUNCTION(BlueprintCallable, Category = "Killable")
		virtual void Die();
};
