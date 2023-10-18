// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FunctionBasedMovement/ActorMovementComponent.h"
#include "GameFramework/Actor.h"
#include "AFunctionBasedMovementActor.generated.h"

UCLASS(Blueprintable, BlueprintType)
class L2_API AAFunctionBasedMovementActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAFunctionBasedMovementActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = FunctionMovement, meta = (AllowPrivateAccess = "true"))
	UActorMovementComponent* ActorMovementComponent;
};