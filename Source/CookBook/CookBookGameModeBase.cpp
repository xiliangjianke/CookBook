// Copyright Epic Games, Inc. All Rights Reserved.


#include "CookBookGameModeBase.h"

/*
ACookBookGameModeBase::ACookBookGameModeBase()
{
	
	// Get the GameMode object, which has reference to the UClass name that we should instantiate
	ACookBookGameModeBase* gm = Cast<ACookBookGameModeBase>(GetWorld()->GetAuthGameMode());
	if (gm)
	{
		UUserProfile* newobject = NewObject<UUserProfile>((UObject*)GetTransientPackage(), UUserProfile::StaticClass());

		newobject->UserTest();

		UE_LOG(LogTemp, Warning, TEXT("Create Succeed!"));

	
	}



}
	*/

void ACookBookGameModeBase::GameModePrint()

{
	//UObject* o = 0;
	//o->GetName();
	UUserProfile* newobject = NewObject<UUserProfile>();
	newobject->UserTest();
	//UE_LOG(LogTemp, Warning, TEXT("This is GameMode!"));
	/*
	if (newobject)
	{
		newobject->ConditionalBeginDestroy();
		newobject = nullptr;
	}
	*/
}
