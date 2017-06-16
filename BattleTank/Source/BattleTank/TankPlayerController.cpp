// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

	// AimTowardsCrosshair();

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("TankPlayerController Begin Play!"));

	ATank* TankGotten = GetControlledTank();
	if (!TankGotten) 
	{
		UE_LOG(LogTemp, Error, TEXT("No Tank found?!"));
		return;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank found: %s"),*TankGotten->GetName());
	}
}

// Tick
void ATankPlayerController::Tick(float DeltaTime)
{
	//Super
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	//(!GetControlledTank()) { return; }

	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
		// TODO Tell controlled tank to aim at this point
	}
}

// Get world location of line trace through cross hair, true it it hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find the cross hair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(OUT ViewportSizeX, OUT ViewportSizeY);

	FVector2D ScreenLocation;
	ScreenLocation.X = ViewportSizeX*CrossHairXLocation;
	ScreenLocation.Y = ViewportSizeY*CrossHairYLocation;

	//UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *ScreenLocation.ToString());
	// "De-project" the screen position of the cross hair to a world direction
	// Ray-cast along that look direction, and see what we hit (up to a max range)

	OutHitLocation = FVector(2.f, 3.f, 4.f);
	return true;
}

