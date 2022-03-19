// Fill out your copyright notice in the Description page of Project Settings.


#include "Clock_Ch05.h"
#include "TimeOfDayHandler_Ch05.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AClock_Ch05::AClock_Ch05()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootSceneComponet = CreateDefaultSubobject<USceneComponent>("RootSceneComponent");
	ClockFace = CreateDefaultSubobject<UStaticMeshComponent>("ClockFace");
	HourHand = CreateDefaultSubobject<UStaticMeshComponent>("HourHand");
	MinuteHand = CreateDefaultSubobject<UStaticMeshComponent>("MinuteHand");
	HourHandle = CreateDefaultSubobject<USceneComponent>("HourHandle");
	MinuteHandle = CreateDefaultSubobject<USceneComponent>("MinuteHandle");

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Ch05/Shape_Cylinder.Shape_Cylinder'"));

	if (MeshAsset.Object != nullptr)
	{
		ClockFace->SetStaticMesh(MeshAsset.Object);
		HourHand->SetStaticMesh(MeshAsset.Object);
		MinuteHand->SetStaticMesh(MeshAsset.Object);
	}

	RootComponent = RootSceneComponet;

	HourHand->AttachToComponent(HourHandle, FAttachmentTransformRules::KeepRelativeTransform);
	MinuteHand->AttachToComponent(MinuteHandle, FAttachmentTransformRules::KeepRelativeTransform);
	HourHandle->AttachToComponent(RootSceneComponet, FAttachmentTransformRules::KeepRelativeTransform);
	MinuteHandle->AttachToComponent(RootSceneComponet, FAttachmentTransformRules::KeepRelativeTransform);
	ClockFace->AttachToComponent(RootSceneComponet, FAttachmentTransformRules::KeepRelativeTransform);

	ClockFace->SetRelativeTransform(FTransform(FRotator(90, 0, 0), FVector(10, 0, 0), FVector(2, 2, 0.1)));
	HourHand->SetRelativeTransform(FTransform(FRotator(0, 0, 0), FVector(0, 0, 25), FVector(0.1, 0.1, 0.5)));
	MinuteHand->SetRelativeTransform(FTransform(FRotator(0, 0, 0), FVector(0, 0, 50), FVector(0.1, 0.1, 1)));




}

void AClock_Ch05::TimeChanged(int32 Hours, int32 Minutes)
{
	HourHandle->SetRelativeRotation(FRotator(0, 0, 30 * Hours));
	MinuteHandle->SetRelativeRotation(FRotator(0, 0, 6 * Minutes));
}

// Called when the game starts or when spawned
void AClock_Ch05::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> TimeOfDayHandlers;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATimeOfDayHandler_Ch05::StaticClass(), TimeOfDayHandlers);

	if (TimeOfDayHandlers.Num() != 0)
	{
		auto TimeOfDayHandler = Cast<ATimeOfDayHandler_Ch05>(TimeOfDayHandlers[0]);
		MyDelegateHandle = TimeOfDayHandler->OnTimeChanged.AddUObject(this, &AClock_Ch05::TimeChanged);

	}

	
}

// Called every frame
void AClock_Ch05::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

