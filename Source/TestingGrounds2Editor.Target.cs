// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class TestingGrounds2EditorTarget : TargetRules
{
	public TestingGrounds2EditorTarget(TargetInfo Target)
	{
		Type = TargetType.Editor;
	}

	//
	// TargetRules interface.
	//

	public override void SetupBinaries(
		TargetInfo Target,
		ref List<UEBuildBinaryConfiguration> OutBuildBinaryConfigurations,
		ref List<string> OutExtraModuleNames
		)
	{
		OutExtraModuleNames.Add("TestingGrounds2");
	}
}
