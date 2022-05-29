// palinoia interactive 2022

using UnrealBuildTool;
using System.Collections.Generic;

public class ThirdPersonStoryAdventureEditorTarget : TargetRules
{
	public ThirdPersonStoryAdventureEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "ThirdPersonStoryAdventure" } );
	}
}
