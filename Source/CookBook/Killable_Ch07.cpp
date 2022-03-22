// Fill out your copyright notice in the Description page of Project Settings.


#include "Killable_Ch07.h"

// Add default functionality here for any IKillable_Ch07 functions that are not pure virtual.

bool IKillable_Ch07::IsDead()
{
	return false;
}

void IKillable_Ch07::Die()
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "Arrrgh");

	AActor* Me = Cast<AActor>(this);

	if (Me)
	{
		Me->Destroy();
	}
}
