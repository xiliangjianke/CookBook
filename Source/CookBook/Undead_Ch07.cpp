// Fill out your copyright notice in the Description page of Project Settings.


#include "Undead_Ch07.h"

// Add default functionality here for any IUndead_Ch07 functions that are not pure virtual.

bool IUndead_Ch07::IsDead()
{
	return true;
}

void IUndead_Ch07::Die()
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("You can't kill what is already dead"));
}

void IUndead_Ch07::Turn()
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("I'm fleeing!"));

}

void IUndead_Ch07::Banish()
{
	AActor* Me = Cast<AActor>(this);
	if (Me)
	{
		Me->Destroy();
	}
}
