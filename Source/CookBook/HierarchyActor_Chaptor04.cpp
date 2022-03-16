// Fill out your copyright notice in the Description page of Project Settings.


#include "HierarchyActor_Chaptor04.h"

// Sets default values
AHierarchyActor_Chaptor04::AHierarchyActor_Chaptor04()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create four subobjects
	Root = CreateDefaultSubobject<USceneComponent>("Root");

	ChildSceneComponent = CreateDefaultSubobject<USceneComponent>("ChildSceneComponent");

	BoxOne = CreateDefaultSubobject<UStaticMeshComponent>("BoxOne");

	BoxTwo = CreateDefaultSubobject<UStaticMeshComponent>("BoxTwo");

	// Get a reference to the cube
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Rock.SM_Rock'"));

	// Give both boxes a mesh
	if (MeshAsset.Object)
	{
		BoxOne->SetStaticMesh(MeshAsset.Object);
		BoxTwo->SetStaticMesh(MeshAsset.Object);
	}

	RootComponent = Root;

	// Set up the object's hierarchy
	BoxOne->AttachTo(Root);
	BoxTwo->AttachTo(ChildSceneComponent);

	ChildSceneComponent->AttachTo(Root);

	// Offset and sca;e the child from the root
	ChildSceneComponent->SetRelativeTransform(FTransform(FRotator(0, 0, 0), FVector(250, 0, 0), FVector(0.1f)));


}

// Called when the game starts or when spawned
void AHierarchyActor_Chaptor04::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHierarchyActor_Chaptor04::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

