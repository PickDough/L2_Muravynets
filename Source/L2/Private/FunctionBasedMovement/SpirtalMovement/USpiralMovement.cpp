#include "FunctionBasedMovement/SpiralMovement/USpiralMovement.h"

FVector USpiralMovement::Function(const AActor* ActorToMove, float T)
{
	if (StartingPosition.IsZero())
	{
		StartingPosition = ActorToMove->GetActorLocation();
	}

	return StartingPosition + ActorToMove->GetActorUpVector() * T * Velocity +
		ActorToMove->GetActorRightVector() * A * sin(T) +
		ActorToMove->GetActorForwardVector() * A * cos(T);
}
