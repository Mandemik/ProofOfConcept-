// palinoia interactive 2022

using UnrealBuildTool;
using System.Collections.Generic;

public class ThirdPersonStoryAdventureTarget : TargetRules
{
	public ThirdPersonStoryAdventureTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "ThirdPersonStoryAdventure" } );
	}
}
