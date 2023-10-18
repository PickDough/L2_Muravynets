// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class L2EditorTarget : TargetRules
{
	public L2EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_1;
		ExtraModuleNames.Add("L2");

		// Game editor
		ExtraModuleNames.AddRange(
			new[]
			{
				"FunctionBasedVisualizerEditor"
			});
	}
}