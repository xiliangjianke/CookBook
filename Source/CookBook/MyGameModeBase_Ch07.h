// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyInterface_Ch07.h"
#include "MyGameModeBase_Ch07.generated.h"

/**
 * 
 */
UCLASS()
class COOKBOOK_API AMyGameModeBase_Ch07 : public AGameModeBase
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

	TArray<IMyInterface_Ch07*> MyInterfaceInstances;
	
};
