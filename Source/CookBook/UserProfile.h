// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ColoredTexture.h"
#include "UserProfile.generated.h"

/**
 * 
 */
UENUM()
enum Status
{
	Stopped	UMETA(DisplayName = "Stopped"),
	Moving UMETA(DisplayName = "Moving"),
	Attacking UMETA(DisplayName = "Attacking"),
};

UCLASS(Blueprintable, BlueprintType)
class COOKBOOK_API UUserProfile : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		float Armor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		float HpMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		FString Name;

	// Display any UClass deriving from UObject in a dropdown menu in Blueprints
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
		TSubclassOf<UObject> UClassOfPlayer;

	// Display string names of UClasses that derive from the GameMode C++ base class
	UPROPERTY(EditAnywhere, meta = (MetaClass = "GameMode"), Category = "Unit")
		FStringClassReference UClassGameMode;

	UFUNCTION(BlueprintCallable)
	void UserTest();

	// Custom struct example
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
		FColoredTexture Texture;

	// Custom enum example
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
		TEnumAsByte<Status> status;

};


