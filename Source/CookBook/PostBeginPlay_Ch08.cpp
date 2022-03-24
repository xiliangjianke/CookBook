// Fill out your copyright notice in the Description page of Project Settings.


#include "PostBeginPlay_Ch08.h"

// Add default functionality here for any IPostBeginPlay_Ch08 functions that are not pure virtual.

void IPostBeginPlay_Ch08::OnPostBeginPlay()
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "PostBeginPlay called!");
}
