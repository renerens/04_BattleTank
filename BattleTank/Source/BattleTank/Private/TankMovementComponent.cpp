// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/Tank.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("Set IntendMoveForward to %f on %s"), Throw, *Name);
}
