// sonictimm 2023

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "OnScreenDebugSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnDebugStatSet, FName, inTitle, const FString&, inValue, FName, inDescr);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDebugStatHidden, FName, inTitle, bool, inHidden);

UCLASS(DisplayName = "On-Screen Debug Subsystem")
class UOnScreenDebugSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:

	//Override
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	//End override

	//Callback for when a stat value is created or updated
	UPROPERTY(BlueprintAssignable)
	FOnDebugStatSet OnDebugStatSet;

	//When visibility is changed on a single stat.  Future updates won't unhide it, the SetDebugStatHidden func must be used.
	UPROPERTY(BlueprintAssignable)
	FOnDebugStatHidden OnDebugStatHidden;

	/*
	* Show / Update a Debug Stat
	* Each stat has a unique name
	* If you call this using a Stat name that has been used before, that stat will be updated
	* If you call with a new Stat name, it will add a new statistic to the list.
	*/
	UFUNCTION(BlueprintCallable, Category = "OnScreenDebug|Set/Update Stat")
	void SetDebugStat(FName inTitle, const FString& inValue, FName inDescr);

	//Set a stat's visibility.  If set hidden, will remain hidden even if updated, until unhidden.
	UFUNCTION(BlueprintCallable, Category = "OnScreenDebug|Visibility")
	void SetDebugStatHidden(FName inTitle, bool inHidden);

	//Hide or unhide the whole debug overlay.
	UFUNCTION(BlueprintCallable, Category = "OnScreenDebug|Visibility")
	void SetDebugOverlayHidden(bool inHidden);

protected:
	//Get debug overlay, create if needed
	UUserWidget* GetDebugOverlay();

	//Create the Debug Overlay if it doesn't exist
	void CreateDebugOverlay();

private:
		
	UUserWidget* DebugOverlay;

};
