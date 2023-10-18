#pragma once

#include "CoreMinimal.h"
#include "Core/Public/Math/MathFwd.h"
#include "GameFramework/Actor.h"
#include "UFunctionBasedMovement.generated.h"


UCLASS(BlueprintType, DefaultToInstanced)
class L2_API UFunctionBasedMovement : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Function", meta = (AllowPrivateAccess = "true"))
	float Time = 5.0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Function", meta = (AllowPrivateAccess = "true"))
	float Velocity = 50.0;

	FVector PositionBasedOnFunction(const AActor* ActorToMove, float T);
	virtual FVector Function(const AActor* ActorToMove, float T);

	virtual bool HasTimeRunOut();

protected:
	float TimePassed;

	FVector StartingPosition;
};

inline FVector UFunctionBasedMovement::PositionBasedOnFunction(const AActor* ActorToMove, float T)
{
	if (TimePassed == 0.0)
	{
		StartingPosition = ActorToMove->GetActorLocation();
	}

	if (HasTimeRunOut())
	{
		return FVector::ZeroVector;
	}

	TimePassed += T;

	return Function(ActorToMove, TimePassed);
}

inline FVector UFunctionBasedMovement::Function(const AActor* ActorToMove, float T)
{
	return FVector::ZeroVector;
}

inline bool UFunctionBasedMovement::HasTimeRunOut()
{
	return TimePassed > Time;
}
