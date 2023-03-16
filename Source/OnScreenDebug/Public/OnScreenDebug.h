// sonictimm 2023

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FOnScreenDebugModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
