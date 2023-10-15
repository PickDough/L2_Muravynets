#pragma once

#include "CoreMinimal.h"
#include "FunctionBasedMovement/UFunctionBasedMovement.h"
#include "UStraightLineMovement.generated.h"

UCLASS(Blueprintable, BlueprintType, DefaultToInstanced, EditInlineNew)
class L2_API UStraightLineMovement : public UFunctionBasedMovement
{
	GENERATED_BODY()
	
public:
	virtual FVector Function(const AActor* ActorToMove, float T) override;
};
