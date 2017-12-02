// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h" // for random
#include "Runtime/Engine/Classes/Engine/World.h" // for FActorSpawnParameters
#include "CollisionAvoider.h"
#include "CollisionAvoidMaster.generated.h"

UCLASS()
class STAMPEDE_API ACollisionAvoidMaster : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollisionAvoidMaster();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	TSubclassOf <ACollisionAvoider> SpawnableBlueprint;

	UPROPERTY(EditAnywhere)
	int NumberOfAgents;

	UPROPERTY(EditAnywhere)
	float SpawnVariance;
	
};
