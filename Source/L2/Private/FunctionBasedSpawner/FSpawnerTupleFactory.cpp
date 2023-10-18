// Fill out your copyright notice in the Description page of Project Settings.

#include "FunctionBasedSpawner/FSpawnerTupleFactory.h"

UFSpawnerTupleFactory::UFSpawnerTupleFactory(const class FObjectInitializer& OBJ)
	: Super(OBJ)
{
	SupportedClass = UFunctionBasedSpawnerTuple::StaticClass();
	bEditAfterNew = true;
	bCreateNew = true;
}

UObject* UFSpawnerTupleFactory::FactoryCreateNew(UClass* InClass,
                                                 UObject* InParent,
                                                 FName InName,
                                                 EObjectFlags Flags,
                                                 UObject* Context,
                                                 FFeedbackContext* Warn)
{
	if (UFunctionBasedSpawnerTupleClass != nullptr)
	{
		return NewObject<UFunctionBasedSpawnerTuple>(InParent,
		                                             UFunctionBasedSpawnerTupleClass,
		                                             InName,
		                                             Flags | RF_Transactional,
		                                             Context);
	}
	check(InClass->IsChildOf(UFunctionBasedSpawnerTuple::StaticClass()));
	return NewObject<UFunctionBasedSpawnerTuple>(InParent, InClass, InName, Flags | RF_Transactional, Context);
}
