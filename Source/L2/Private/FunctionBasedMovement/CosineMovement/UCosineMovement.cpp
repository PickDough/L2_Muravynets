#include "FunctionBasedMovement/CosineMovement/UCosineMovement.h"

FVector UCosineMovement::Function(const AActor* ActorToMove, float T)
{
	if (StartingPosition.IsZero())
	{
		StartingPosition = ActorToMove->GetActorLocation();
	}

	return StartingPosition + ActorToMove->GetActorForwardVector() * Velocity * T + ActorToMove->GetActorRightVector() *
		B * sin(A * T);
}
