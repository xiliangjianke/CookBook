// Fill out your copyright notice in the Description page of Project Settings.


#include "Warrior_Ch06.h"
#include "Components/CapsuleComponent.h"
#include "MyGameModeBase_Ch06.h"

// Sets default values
AWarrior_Ch06::AWarrior_Ch06()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LastInput = FVector2D::ZeroVector;

}

void AWarrior_Ch06::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (RootComponent)
	{
		// Attach contact function to all bounding components
		GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AWarrior_Ch06::OnOverLapsBegin);
		GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this, &AWarrior_Ch06::OnOverLapsEnd);

	}

}

void AWarrior_Ch06::OnOverLapsEnd_Implementation(UPrimitiveComponent* comp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlaps warrior end"));

}

void AWarrior_Ch06::OnOverLapsBegin_Implementation(UPrimitiveComponent* comp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlaps warrior began"));
}

// Called when the game starts or when spawned
void AWarrior_Ch06::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWarrior_Ch06::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float len = LastInput.Size();

	// If the player's input is greater than 1, normalize it
	if (len > 1.f)
	{
		LastInput /= len;
	}
	AddMovementInput(GetActorForwardVector(), LastInput.Y);
	AddMovementInput(GetActorRightVector(), LastInput.X);

	// Zero off last input values
	LastInput = FVector2D(0.f, 0.f);
}

// Called to bind functionality to input
void AWarrior_Ch06::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Forward", this, &AWarrior_Ch06::Forward);
	PlayerInputComponent->BindAxis("Back", this, &AWarrior_Ch06::Back);
	PlayerInputComponent->BindAxis("Right", this, &AWarrior_Ch06::Right);
	PlayerInputComponent->BindAxis("Left", this, &AWarrior_Ch06::Left);

	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AWarrior_Ch06::Jump);

	// Calling function for hotkey
	auto GameMode = Cast<AMyGameModeBase_Ch06>(GetWorld()->GetAuthGameMode());
	auto Func = &AMyGameModeBase_Ch06::ButtonClicked;

	if (GameMode && Func)
	{
		PlayerInputComponent->BindAction("HotKey_UIButton_Spell", IE_Pressed, GameMode, Func);

	}


}

void AWarrior_Ch06::Forward(float amount)
{
	LastInput.Y += amount;
	//AddMovementInput(GetActorForwardVector(), amount);
}

void AWarrior_Ch06::Back(float amount)
{
	LastInput.Y -= amount;

	//AddMovementInput(-GetActorForwardVector(), amount);

}

void AWarrior_Ch06::Right(float amount)
{
	LastInput.X += amount;

	//AddMovementInput(GetActorRightVector(), amount);

}

void AWarrior_Ch06::Left(float amount)
{
	LastInput.X -= amount;

	//AddMovementInput(-GetActorRightVector(), amount);

}

