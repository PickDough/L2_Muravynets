#include "FunctionBasedMovement/StraigtLineMovement/UStraightLineMovement.h"

FVector UStraightLineMovement::Function(const AActor* ActorToMove, float T)
{
	if (StartingPosition.IsZero())
		StartingPosition = ActorToMove->GetActorLocation();
	
	return StartingPosition + FRotationMatrix(ActorToMove->GetActorRotation()).GetScaledAxis(EAxis::X) * Velocity * T;
}
