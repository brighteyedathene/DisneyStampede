// Fill out your copyright notice in the Description page of Project Settings.

#include "CollisionAvoider.h"


// Sets default values
ACollisionAvoider::ACollisionAvoider()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACollisionAvoider::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollisionAvoider::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//GEngine->AddOnScreenDebugMessage(-1, 12.0f, FColor::Yellow, TEXT("text"));
	
	// Get nearby actors and avoid them
	FVector totalAvoidVector = FVector(0.0, 0.0, 0.0);
	GetOverlappingActors(NearbyActors);
	for (int i = 0; i < NearbyActors.Num(); i++)
	{
		//GEngine->AddOnScreenDebugMessage(-10, 12.0f, FColor::Yellow, TEXT("ouch i'm colliding!"));
		

		FVector avoidVector = GetActorLocation() - NearbyActors[i]->GetActorLocation();
		float inverseSqaureDistance = 1/ (avoidVector.Size() * avoidVector.Size());
		avoidVector.Normalize();
		avoidVector *= inverseSqaureDistance * AVOIDANCE_CONST;
		totalAvoidVector += avoidVector;
		
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, avoidVector.ToString());
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::SanitizeFloat(inverseSqaureDistance));
	}
	totalAvoidVector = totalAvoidVector.GetClampedToMaxSize(MAX_DELTA);
	SetActorLocation(GetActorLocation() + totalAvoidVector * DeltaTime);

}



void ACollisionAvoider::SimpleMovementTick(float DeltaTime)
{
	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * 20.0f;
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);
}