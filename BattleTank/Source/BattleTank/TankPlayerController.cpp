// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/Tank.h"
#include "TankPlayerController.h"
#include "CollisionQueryParams.h"
#include "GameFramework/Actor.h"

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
		GetControlledTank()->AimAt(HitLocation);
	}
}

// Get world location of line trace through cross hair, true it it hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// Find the cross hair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(OUT ViewportSizeX, OUT ViewportSizeY);

	FVector2D ScreenLocation;
	ScreenLocation.X = ViewportSizeX*CrossHairXLocation;
	ScreenLocation.Y = ViewportSizeY*CrossHairYLocation;

	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		// Ray-cast along that look direction, and see what we hit (up to a max range)
		 GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; // Not needed!
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, OUT CameraWorldLocation, OUT LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;

	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection* LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility))
	{
		HitLocation = HitResult.Location;
	//	UE_LOG(LogTemp, Warning, TEXT("Result: %s"), *HitLocation.ToString());
		return true;
	}
	HitLocation = FVector(0);
	return false;
}