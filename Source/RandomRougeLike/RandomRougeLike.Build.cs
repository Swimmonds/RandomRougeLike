// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RandomRougeLike : ModuleRules
{
	public RandomRougeLike(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
