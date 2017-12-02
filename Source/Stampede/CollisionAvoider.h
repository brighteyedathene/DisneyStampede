// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollisionAvoider.generated.h"

UCLASS()
class STAMPEDE_API ACollisionAvoider : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollisionAvoider();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SimpleMovementTick(float DeltaTime);

	TArray<AActor*> NearbyActors;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float RunningTime;

	UPROPERTY(EditAnywhere)
	float AVOIDANCE_CONST = 100000.0f;
	
	UPROPERTY(EditAnywhere)
	float MAX_DELTA = 10.0f;

};
