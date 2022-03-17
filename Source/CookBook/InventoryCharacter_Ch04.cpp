// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryCharacter_Ch04.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AInventoryCharacter_Ch04::AInventoryCharacter_Ch04()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyInventory = CreateDefaultSubobject<UInvenComponent_Ch04>("MyInventory");

}

void AInventoryCharacter_Ch04::DropItem()
{
	if (MyInventory->CurrentInventory.Num() == 0)
	{
		return;
	}
	AInventoryActor* Item = MyInventory->CurrentInventory.Last();
	MyInventory->RemoveFromInventory(Item);

	FVector ItemOrigin;
	FVector ItemBounds;
	Item->GetActorBounds(false, ItemOrigin, ItemBounds);

	FTransform PutDownLocation = GetTransform() + FTransform(RootComponent->GetForwardVector() * ItemBounds.GetMax());

	Item->PutDown(PutDownLocation);
}

void AInventoryCharacter_Ch04::TakeItem(AInventoryActor* InventoryItem)
{
	InventoryItem->PickUp();
	MyInventory->AddToInventory(InventoryItem);
}

void AInventoryCharacter_Ch04::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	AInventoryActor* InventoryItem = Cast<AInventoryActor>(Other);
	if (InventoryItem != nullptr)
	{
		TakeItem(InventoryItem);
	}

}

void AInventoryCharacter_Ch04::MoveForward(float AxisValue)
{
	MovementInput.X = FMath::Clamp<float>(AxisValue, -1.0f, 1.0f);
}

void AInventoryCharacter_Ch04::MoveRight(float AxisValue)
{
	MovementInput.Y = FMath::Clamp<float>(AxisValue, -1.0f, 1.0f);

}

void AInventoryCharacter_Ch04::PitchCamera(float AxisValue)
{
	CameraInput.Y = AxisValue;
}

void AInventoryCharacter_Ch04::YawCamera(float AxisValue)
{
	CameraInput.X = AxisValue;

}

// Called when the game starts or when spawned
void AInventoryCharacter_Ch04::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInventoryCharacter_Ch04::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!MovementInput.IsZero())
	{
		MovementInput *= 100;

		// Scale our movement input axis values by 100 units per second
		FVector InputVector = FVector(0, 0, 0);
		InputVector += GetActorForwardVector() * MovementInput.X * DeltaTime;
		InputVector += GetActorRightVector() * MovementInput.Y * DeltaTime;
		GetCharacterMovement()->AddInputVector(InputVector);

		// Debug
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("x- %f, y - %f, z - %f"), InputVector.X, InputVector.Y, InputVector.Z));


	}
	if (!CameraInput.IsNearlyZero())
	{
		FRotator NewRotation = GetActorRotation();
		NewRotation.Pitch += CameraInput.Y;
		NewRotation.Yaw += CameraInput.X;

		APlayerController* MyPlayerController = Cast<APlayerController>(GetController());
		if (MyPlayerController != nullptr)
		{
			MyPlayerController->AddYawInput(CameraInput.X);
			MyPlayerController->AddPitchInput(CameraInput.Y);
		}
		SetActorRotation(NewRotation);
	}
}

// Called to bind functionality to input
void AInventoryCharacter_Ch04::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("DropItem", EInputEvent::IE_Pressed, this, &AInventoryCharacter_Ch04::DropItem);

	// Movement
	PlayerInputComponent->BindAxis("MoveForward", this, &AInventoryCharacter_Ch04::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AInventoryCharacter_Ch04::MoveRight);
	PlayerInputComponent->BindAxis("PitchCamera", this, &AInventoryCharacter_Ch04::PitchCamera);
	PlayerInputComponent->BindAxis("YawCamera", this, &AInventoryCharacter_Ch04::YawCamera);

}

