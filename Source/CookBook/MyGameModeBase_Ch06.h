// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase_Ch06.generated.h"

/**
 * 
 */
UCLASS()
class COOKBOOK_API AMyGameModeBase_Ch06 : public AGameModeBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "UFFuncs")
		void ButtonClicked()
	{
		UE_LOG(LogTemp, Warning, TEXT("UI Button clicked!"));
	}
	
};
