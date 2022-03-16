// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UserProfile.h"
#include "CookBookGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class COOKBOOK_API ACookBookGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	//ACookBookGameModeBase();

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ClassNames")
		//TSubclassOf<UUserProfile> UPBlueprintClassName;
	
	UFUNCTION(BlueprintCallable)
	void GameModePrint();
};
