// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class L2Target : TargetRules
{
	public L2Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_1;
		ExtraModuleNames.Add("L2");
		
		if (bBuildEditor)
		{
			ExtraModuleNames.AddRange( 
				new string[]
				{
					"FunctionBasedVisualizerEditor"
				});
		}
	}
}
