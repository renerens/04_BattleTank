// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

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

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

