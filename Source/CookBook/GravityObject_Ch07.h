// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GravityObject_Ch07.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGravityObject_Ch07 : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class COOKBOOK_API IGravityObject_Ch07
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void EnableGravity();
	virtual void DisableGravity();
};
