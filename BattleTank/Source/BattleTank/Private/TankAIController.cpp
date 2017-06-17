// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"
#include "Public/Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

// Tick
void ATankAIController::Tick(float DeltaTime)
{
	//Super
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank	= Cast<ATank>(GetPawn());
		if (PlayerTank) 
		{
			ControlledTank->AimAt(PlayerTank->GetActorLocation());

			ControlledTank->Fire(); // TODO Limit firing rate!
		}
}



