#include "FFunctionBasedVisualizerEditorModule.h"

#include "FFunctionBasedVisualizer.h"
#include "Modules/ModuleManager.h"
#include "Modules/ModuleInterface.h"
#include "UnrealEdGlobals.h"
#include "Components/SphereComponent.h"
#include "Editor/UnrealEdEngine.h"
#include "L2/Public/ActorMovementComponent.h"

IMPLEMENT_GAME_MODULE(FFunctionBasedVisualizerEditorModule, FunctionBasedVisualizerEditor);

DEFINE_LOG_CATEGORY(FunctionBasedVisualizerEditor)

#define LOGTEXT_NAMESPACE "FunctionBasedVisualizerEditor"

void FFunctionBasedVisualizerEditorModule::StartupModule()
{
	UE_LOG(FunctionBasedVisualizerEditor, Warning, TEXT("FunctionBasedVisualizerEditor: Log Started"));
	if (GUnrealEd)
	{
		TSharedPtr<FFunctionBasedVisualizer> Visualizer = MakeShareable(new FFunctionBasedVisualizer());
		GUnrealEd->RegisterComponentVisualizer(UActorMovementComponent::StaticClass()->GetFName(), Visualizer);
		Visualizer->OnRegister();
		UE_LOG(FunctionBasedVisualizerEditor, Warning, TEXT("FunctionBasedVisualizerEditor: Log Started"));
	}
}

void FFunctionBasedVisualizerEditorModule::ShutdownModule()
{
	UE_LOG(FunctionBasedVisualizerEditor, Warning, TEXT("FunctionBasedVisualizerEditor: Log Ended"));
	if (GUnrealEd)
	{
		GUnrealEd->UnregisterComponentVisualizer(UActorMovementComponent::StaticClass()->GetFName());
	}
}

#undef LOGTEXT_NAMESPACE