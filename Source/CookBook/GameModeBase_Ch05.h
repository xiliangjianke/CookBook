// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameModeBase_Ch05.generated.h"

/**
 * 
 */
// Delegate without parameter
DECLARE_DELEGATE(FStandardDelegateSignature)
// Delegate with parameter
DECLARE_DELEGATE_OneParam(FParamDelegateSignature, FLinearColor)
// Multicast
DECLARE_MULTICAST_DELEGATE(FMulticastDelegateSignature)
UCLASS()
class COOKBOOK_API AGameModeBase_Ch05 : public AGameModeBase
{
	GENERATED_BODY()

public:
	FStandardDelegateSignature MyStandardDelegate;

	FParamDelegateSignature MyParameterDelegate;

	FMulticastDelegateSignature MyMulticastDelegate;
	
};
