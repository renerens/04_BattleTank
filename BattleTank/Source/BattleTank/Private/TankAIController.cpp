// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"
#include "Public/Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	//UE_LOG(LogTemp, Warning, TEXT("TankAIController Begin Play!"));

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AIController can't find player tank"));
		return;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player %s"), *PlayerTank->GetName());
	}
}

// Tick
void ATankAIController::Tick(float DeltaTime)
{
	//Super
	Super::Tick(DeltaTime);
	auto myTank = GetControlledTank();
	//myTank->AimAt(GetPlayerTank()->GetActorLocation());
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>(PlayerPawn);
}



