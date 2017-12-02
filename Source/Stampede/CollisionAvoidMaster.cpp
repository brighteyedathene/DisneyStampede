// Fill out your copyright notice in the Description page of Project Settings.

#include "CollisionAvoidMaster.h"


/** Spawns and returns class T, forcibly sets world position. */
template< class T >
T* SpawnActor
(
	FVector const& Location,
	FRotator const& Rotation,
	AActor* Owner = NULL,
	APawn* Instigator = NULL,
	bool bNoCollisionFail = false
)
{
	return (T*)(GetWorld()->SpawnActor(T::StaticClass(), NAME_None, &Location, &Rotation, NULL, bNoCollisionFail, false, Owner, Instigator));
}


// Sets default values
ACollisionAvoidMaster::ACollisionAvoidMaster()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ACollisionAvoidMaster::BeginPlay()
{
	Super::BeginPlay();
	
	// spawn Blueprint defined by ToSpawn in a random offset constrained by SpawnArea
	if (SpawnableBlueprint)
	{

		for (int i = 0; i < NumberOfAgents; i++)
		{
			// randomly offset the location
			FVector offset = FVector(FMath::RandRange(-SpawnVariance, SpawnVariance),
									 FMath::RandRange(-SpawnVariance, SpawnVariance),
									 FMath::RandRange(-SpawnVariance, SpawnVariance));

			FVector location = GetActorLocation() + offset;
			GetWorld()->SpawnActor<ACollisionAvoider>(SpawnableBlueprint, location, GetActorRotation(), FActorSpawnParameters());

		}
	}



}

// Called every frame
void ACollisionAvoidMaster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
