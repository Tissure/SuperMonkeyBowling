// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class SuperMonkeyBowlingTarget : TargetRules
{
	public SuperMonkeyBowlingTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;

        //StaticAnalyzer = StaticAnalyzer.PVSStudio;

        ExtraModuleNames.AddRange( new string[] { "SuperMonkeyBowling" } );
	}
}
