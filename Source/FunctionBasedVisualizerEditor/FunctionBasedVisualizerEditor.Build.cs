using UnrealBuildTool;

public class FunctionBasedVisualizerEditor : ModuleRules
{
	public FunctionBasedVisualizerEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(new[] { "FunctionBasedVisualizerEditor/Public" });
		PrivateIncludePaths.AddRange(new[] { "FunctionBasedVisualizerEditor/Private" });

		PublicDependencyModuleNames.AddRange(new[] { "Core", "L2" });
		PrivateDependencyModuleNames.AddRange(new[] { "UnrealEd", "CoreUObject", "Engine", "ComponentVisualizers" });
	}
}