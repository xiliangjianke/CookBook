// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Talker_Ch08.h"
#include "TalkingMesh_Ch08.generated.h"

/**
 * 
 */
UCLASS()
class COOKBOOK_API ATalkingMesh_Ch08 : public AStaticMeshActor, public ITalker_Ch08
{
	GENERATED_BODY()
public:
	ATalkingMesh_Ch08();
	void StartTalking_Impelmentation();
	
};
