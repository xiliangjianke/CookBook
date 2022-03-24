// Fill out your copyright notice in the Description page of Project Settings.


#include "TalkingPawn_Ch08.h"
#include "Talker_Ch08.h"


ATalkingPawn_Ch08::ATalkingPawn_Ch08() : Super()
{
	PrimaryActorTick.bCanEverTick = true;

	TalkCollider = CreateDefaultSubobject<UBoxComponent>("TalkCollider");

	TalkCollider->SetBoxExtent(FVector(200, 200, 200));

	TalkCollider->OnComponentBeginOverlap.AddDynamic(this, &ATalkingPawn_Ch08::OnTalkOverlap);

	TalkCollider->AttachTo(RootComponent);
}

void ATalkingPawn_Ch08::OnTalkOverlap(UPrimitiveComponent* OverlapperdComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto Class = OtherActor->GetClass();
	if (Class->ImplementsInterface(UTalker_Ch08::StaticClass()))
	{
		ITalker_Ch08::Execute_StartTalking(OtherActor);
	}
}
