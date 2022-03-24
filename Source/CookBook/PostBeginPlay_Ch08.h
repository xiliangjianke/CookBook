// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PostBeginPlay_Ch08.generated.h"

// This class does not need to be modified.
UINTERFACE(meta = (CannotImplementInterfaceInBlueprint))
class UPostBeginPlay_Ch08 : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class COOKBOOK_API IPostBeginPlay_Ch08
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, Category = "Test")
		virtual void OnPostBeginPlay();
};
