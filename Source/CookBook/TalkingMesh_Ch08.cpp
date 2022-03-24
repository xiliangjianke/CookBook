// Fill out your copyright notice in the Description page of Project Settings.


#include "TalkingMesh_Ch08.h"

ATalkingMesh_Ch08::ATalkingMesh_Ch08() : Super()
{
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Ch08/Shape_Cube.Shape_Cube'"));

	UStaticMeshComponent* SM = GetStaticMeshComponent();

	if (SM != nullptr)
	{
		if (MeshAsset.Object != nullptr)
		{
			SM->SetStaticMesh(MeshAsset.Object);
			SM->SetGenerateOverlapEvents(true);
		}
		SM->SetMobility(EComponentMobility::Movable);
	}
	SetActorEnableCollision(true);
}

void ATalkingMesh_Ch08::StartTalking_Impelmentation()
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "Hello there.What is your name?");
}
