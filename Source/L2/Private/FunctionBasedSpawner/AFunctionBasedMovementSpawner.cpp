// Fill out your copyright notice in the Description page of Project Settings.


#include "FunctionBasedSpawner/AFunctionBasedMovementSpawner.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AAFunctionBasedMovementSpawner::AAFunctionBasedMovementSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	EnableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));
}

// Called when the game starts or when spawned
void AAFunctionBasedMovementSpawner::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<
			UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);

			if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerController->InputComponent))
			{
				for (auto SpawningActor : SpawningActors)
				{
					EnhancedInputComponent->BindAction(SpawningActor->Input,
													   ETriggerEvent::Triggered,
													   this,
													   &AAFunctionBasedMovementSpawner::SpawnMovementActor,
													   SpawningActor->ActorToSpawn,
													   SpawningActor->PointToSpawn);
				}
			}
		}
	}
}

void AAFunctionBasedMovementSpawner::SpawnMovementActor(const FInputActionValue& Value,
                                                        TSubclassOf<AAFunctionBasedMovementActor> Actor,
                                                        ATargetPoint* Point)
{
	GetWorld()->SpawnActor<AAFunctionBasedMovementActor>(Actor, Point->GetActorLocation(), Point->GetActorRotation());
}


// Called every frame
void AAFunctionBasedMovementSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAFunctionBasedMovementSpawner::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		
		for (auto SpawningActor : SpawningActors)
		{
			EnhancedInputComponent->BindAction(SpawningActor->Input,
											   ETriggerEvent::Triggered,
											   this,
											   &AAFunctionBasedMovementSpawner::SpawnMovementActor,
											   SpawningActor->ActorToSpawn,
											   SpawningActor->PointToSpawn);
		}
	}
}
