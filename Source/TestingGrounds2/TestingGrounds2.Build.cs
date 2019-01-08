// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TestingGrounds2 : ModuleRules
{
	public TestingGrounds2(ReadOnlyTargetRules Target) : base (Target)
    {
  		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule", "GameplayTasks" });
    }
}
