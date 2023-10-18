#include "FFunctionBasedVisualizer.h"

#include "L2/Public/FunctionBasedMovement/ActorMovementComponent.h"

void FFunctionBasedVisualizer::DrawVisualization(const UActorComponent* Component,
                                                 const FSceneView* View,
                                                 FPrimitiveDrawInterface* PDI)
{
	if (const UActorMovementComponent* MovementComponent = Cast<UActorMovementComponent>(Component))
	{
		if (const auto Function = MovementComponent->FunctionBasedMovement)
		{
			auto starPos = MovementComponent->GetOwner()->GetActorLocation();

			for (float i = 0.01; i < Function->Time; i += 0.01)
			{
				auto endPos = Function->Function(MovementComponent->GetOwner(), i);
				PDI->DrawLine(starPos, endPos, FLinearColor::Red, SDPG_World, 4.);

				starPos = endPos;
			}
		}
	}
}

void FFunctionBasedVisualizer::DrawVisualizationHUD(const UActorComponent* Component,
                                                    const FViewport* Viewport,
                                                    const FSceneView* View,
                                                    FCanvas* Canvas)
{
	FComponentVisualizer::DrawVisualizationHUD(Component, Viewport, View, Canvas);
}
