// sonictimm 2023

#include "OnScreenDebugSubsystem.h"
#include "OnScreenDebugSettings.h"
#include "OnScreenDebugList.h"

#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
PRAGMA_DISABLE_OPTIMIZATION

void UOnScreenDebugSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	DebugOverlay = nullptr;
}

void UOnScreenDebugSubsystem::Deinitialize()
{
	if (DebugOverlay != nullptr)
	{
		DebugOverlay->RemoveFromParent();
	}
}

void UOnScreenDebugSubsystem::CreateDebugOverlay()
{
	//Get the CDO and load the widget class from settings
	const UOnScreenDebugSettings* debugSettings = GetDefault<UOnScreenDebugSettings>();
	DebugOverlay = CreateWidget<UOnScreenDebugList>(GetOuterUGameInstance(), debugSettings->OnScreenWidget.LoadSynchronous());


	if (DebugOverlay != nullptr)
	{
		DebugOverlay->AddToViewport();
	}
}

void UOnScreenDebugSubsystem::SetDebugStat(FName inTitle, const FString& inValue, FName inDescr)
{
	//make sure debug overlay exists
	
	if (DebugOverlay == nullptr)
	{
		CreateDebugOverlay();
		if (DebugOverlay == nullptr)
		{
			return;
		}
	}


	//run callbacks, UI should have connected itself to these
	OnDebugStatSet.Broadcast(inTitle, inValue, inDescr);
}

void UOnScreenDebugSubsystem::SetDebugStatHidden(FName inTitle, bool inHidden)
{
	OnDebugStatHidden.Broadcast(inTitle, inHidden);
}

void UOnScreenDebugSubsystem::SetDebugOverlayHidden(bool inHidden)
{
	if (DebugOverlay != nullptr)
	{
		DebugOverlay->SetVisibility(inHidden ? ESlateVisibility::Collapsed : ESlateVisibility::HitTestInvisible);
	}
}

UUserWidget* UOnScreenDebugSubsystem::GetDebugOverlay()
{
	if (DebugOverlay == nullptr)
	{
		CreateDebugOverlay();
	}

	return DebugOverlay;
}
PRAGMA_ENABLE_OPTIMIZATION