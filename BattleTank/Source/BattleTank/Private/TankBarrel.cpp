// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	// Move the barrel the right amount this frame
	// Given a max elevation speed, and the frame time
	UE_LOG(LogTemp, Warning, TEXT("%f: Barrel->Elevate() called at speed %f"), GetWorld()->GetTimeSeconds(), RelativeSpeed);
}