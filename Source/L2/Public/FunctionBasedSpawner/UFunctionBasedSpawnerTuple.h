#pragma once
#include "AFunctionBasedMovementActor.h"
#include "InputAction.h"
#include "Engine/TargetPoint.h"
#include "UFunctionBasedSpawnerTuple.generated.h"

UCLASS(Blueprintable, BlueprintType, DefaultToInstanced, EditInlineNew)
class UFunctionBasedSpawnerTuple : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UInputAction* Input;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AAFunctionBasedMovementActor> ActorToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	ATargetPoint* PointToSpawn;
};
