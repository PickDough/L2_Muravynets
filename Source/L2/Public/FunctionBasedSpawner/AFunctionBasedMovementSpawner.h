// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "FunctionBasedSpawner/UFunctionBasedSpawnerTuple.h"
#include "GameFramework/Actor.h"
#include "AFunctionBasedMovementSpawner.generated.h"

UCLASS()
class L2_API AAFunctionBasedMovementSpawner : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAFunctionBasedMovementSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SpawnMovementActor(const FInputActionValue& Value, TSubclassOf<AAFunctionBasedMovementActor>, ATargetPoint*);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Spawn)
	TArray<UFunctionBasedSpawnerTuple*> SpawningActors;
};
