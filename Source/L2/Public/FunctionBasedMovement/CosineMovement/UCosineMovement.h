#pragma once

#include "CoreMinimal.h"
#include "FunctionBasedMovement/UFunctionBasedMovement.h"
#include "UCosineMovement.generated.h"

UCLASS(Blueprintable, BlueprintType, DefaultToInstanced, EditInlineNew)
class L2_API UCosineMovement : public UFunctionBasedMovement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,
		BlueprintReadOnly,
		Category = "Function",
		meta = (AllowPrivateAccess = "true"),
		DisplayName="b*sin(A*t) // A")
	float A = 10.0;

	UPROPERTY(EditAnywhere,
		BlueprintReadOnly,
		Category = "Function",
		meta = (AllowPrivateAccess = "true"),
		DisplayName="B*sin(a*t) // B")
	float B = 100.0;

	virtual FVector Function(const AActor* ActorToMove, float T) override;
};
