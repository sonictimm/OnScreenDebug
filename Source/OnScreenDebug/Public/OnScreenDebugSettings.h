// sonictimm 2023

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"

#include "OnScreenDebugSettings.generated.h"


UCLASS(Config=Editor, defaultconfig, meta=(DisplayName="On-Screen Debug Settings"))
class UOnScreenDebugSettings : public UDeveloperSettings		//Don't forget to add public dependency "DeveloperSettings" to build.cs
{
	GENERATED_BODY()

public:

	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "General")
	TSoftClassPtr<UOnScreenDebugList> OnScreenWidget;
};
