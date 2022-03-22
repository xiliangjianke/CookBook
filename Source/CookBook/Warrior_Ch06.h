// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Warrior_Ch06.generated.h"

UCLASS()
class COOKBOOK_API AWarrior_Ch06 : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWarrior_Ch06();

	UFUNCTION(BlueprintNativeEvent, Category = "Collision")
		void OnOverLapsBegin(UPrimitiveComponent* comp, AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult& SweepResult);

	UFUNCTION(BlueprintNativeEvent, Category = "Collision")
		void OnOverLapsEnd(UPrimitiveComponent* comp, AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);

	virtual void PostInitializeComponents() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// The movement from the previous fram
	FVector2D LastInput;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Movement functions
	void Forward(float amount);
	void Back(float amount);
	void Right(float amount);
	void Left(float amount);
};
