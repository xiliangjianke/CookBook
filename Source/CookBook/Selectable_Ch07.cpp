// Fill out your copyright notice in the Description page of Project Settings.


#include "Selectable_Ch07.h"

// Add default functionality here for any ISelectable_Ch07 functions that are not pure virtual.

bool ISelectable_Ch07::IsSelectable()
{
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, "Selectable");
	return true;
}

bool ISelectable_Ch07::TrySelect()
{
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, "Accepting Selection");
	return true;
}

void ISelectable_Ch07::Deselect()
{
	unimplemented();
}
