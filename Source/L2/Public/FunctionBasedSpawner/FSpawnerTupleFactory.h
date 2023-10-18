// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UFunctionBasedSpawnerTuple.h"
#include "Factories/Factory.h"
#include "FSpawnerTupleFactory.generated.h"

/**
 * 
 */
UCLASS()
class L2_API UFSpawnerTupleFactory : public UFactory
{
	GENERATED_UCLASS_BODY()

public:
	UPROPERTY(EditAnywhere, Category=InputAction)
	TSubclassOf<UFunctionBasedSpawnerTuple> UFunctionBasedSpawnerTupleClass;

	virtual UObject* FactoryCreateNew(UClass* InClass,
	                                  UObject* InParent,
	                                  FName InName,
	                                  EObjectFlags Flags,
	                                  UObject* Context,
	                                  FFeedbackContext* Warn) override;
};
