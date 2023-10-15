using UnrealBuildTool;

public class FunctionBasedVisualizerEditor : ModuleRules
{
	public FunctionBasedVisualizerEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(new string[] { "FunctionBasedVisualizerEditor/Public" });
		PrivateIncludePaths.AddRange(new string[] { "FunctionBasedVisualizerEditor/Private" });

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "L2" });
		PrivateDependencyModuleNames.AddRange(new string[] { "UnrealEd", "CoreUObject", "Engine",  "ComponentVisualizers"});
	}
}