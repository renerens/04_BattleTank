// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle)
{
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("Set Throttle to %f on %s"), Throttle,*Name);

	//TODO clamp Throttle to 0 and 1
}

