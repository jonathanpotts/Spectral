// Copyright 2018 Jonathan Potts. All rights reserved.

using System.IO;
using UnrealBuildTool;

public class Spectral : ModuleRules
{
	public Spectral(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				"Spectral/Public"
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"Spectral/Private",
				// ... add other private include paths required here ...
			}
			);
			
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Projects"
				// ... add other public dependencies that you statically link with here ...
			}
			);


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "InputCore"
				// ... add private dependencies that you statically link with here ...	
			}
            );


        DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);

        string BaseDirectory = Path.GetFullPath(Path.Combine(ModuleDirectory, "..", ".."));
        string SpectralDirectory = Path.Combine(BaseDirectory, "ThirdParty", "Spectral", Target.Platform.ToString());
        string CorsairDirectory = Path.Combine(BaseDirectory, "ThirdParty", "Corsair", Target.Platform.ToString());

        if (Target.Platform == UnrealTargetPlatform.Win32)
        {
            RuntimeDependencies.Add(Path.Combine(SpectralDirectory, "Spectral.dll"));
            RuntimeDependencies.Add(Path.Combine(CorsairDirectory, "CUESDK_2015.dll"));
        }
        else if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            RuntimeDependencies.Add(Path.Combine(SpectralDirectory, "Spectral.dll"));
            RuntimeDependencies.Add(Path.Combine(CorsairDirectory, "CUESDK.x64_2015.dll"));
        }
    }
}
