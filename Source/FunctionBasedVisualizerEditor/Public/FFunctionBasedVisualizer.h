﻿#pragma once

#include "ComponentVisualizer.h"

class FFunctionBasedVisualizer : public FComponentVisualizer
{
public:
	// Begin FComponentVisualizer interface
	
	virtual void DrawVisualization(const UActorComponent* Component, const FSceneView* View, FPrimitiveDrawInterface* PDI) override;
	virtual void DrawVisualizationHUD(const UActorComponent* Component, const FViewport* Viewport, const FSceneView* View, FCanvas* Canvas) override;

private:
};
