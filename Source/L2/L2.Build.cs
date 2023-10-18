// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class L2 : ModuleRules
{
	public L2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new[]
		{
			"Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput"
		});
	}
}