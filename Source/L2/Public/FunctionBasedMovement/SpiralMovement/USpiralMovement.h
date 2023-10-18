#pragma once
#include "FunctionBasedMovement/UFunctionBasedMovement.h"
#include "USpiralMovement.generated.h"

UCLASS(Blueprintable, BlueprintType, DefaultToInstanced, EditInlineNew)
class USpiralMovement : public UFunctionBasedMovement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,
		BlueprintReadOnly,
		Category = "Function",
		meta = (AllowPrivateAccess = "true"),
		DisplayName="A*sin(t) + A*cost(t) // A")
	float A = 100;

	virtual FVector Function(const AActor* ActorToMove, float T) override;
};
