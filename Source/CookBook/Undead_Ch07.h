// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Killable_Ch07.h"
#include "Undead_Ch07.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UUndead_Ch07 : public UKillable_Ch07
{
	GENERATED_BODY()
};

/**
 * 
 */
class COOKBOOK_API IUndead_Ch07 : public IKillable_Ch07
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual bool IsDead() override;
	virtual void Die() override;
	virtual void Turn();
	virtual void Banish();
};
