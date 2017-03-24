// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingEscape.h"
#include "Grabber.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	UE_LOG(LogTemp, Warning, TEXT("Grabber reporting for duty!"));

}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector pPos;
	FRotator pRot;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT pPos, 
		OUT pRot
	);

	// Get Player View Point
	/*UE_LOG( 
		LogTemp, 
		Warning, 
		TEXT("Position: %s, Rotation: %s"), 
		*pPos.ToString(),
		*pRot.ToString()
	);*/

	// Draw a red line to visualise our 
	FVector LineTraceEnd = pPos + FVector(0.0f,50.0f,0.0f);

	DrawDebugLine(
		GetWorld(),
		pPos,
		LineTraceEnd,
		FColor(255,0,0),
		false,
		0.0f,
		0.0f,
		10.0f
	);
}

