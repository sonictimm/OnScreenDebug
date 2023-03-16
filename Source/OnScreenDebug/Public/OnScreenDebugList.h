// sonictimm 2023

#pragma once

#include "CoreMinimal.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"

#include "OnScreenDebugList.generated.h"

//Base class for on-screen debug list.  Note that it's not a "ListView," just a User Widget
UCLASS(Blueprintable, BlueprintType, DisplayName = "On-Screen Debug List Widget")
class UOnScreenDebugList : public UUserWidget
{
	GENERATED_BODY()

public:

	//Override
	virtual void NativeOnInitialized() override;
	//End override

	//Record or Update a stat on-screen
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category="OnScreenDebug")
	void RecordStat(FName inTitle, const FString& inValue, FName inDescr);	//Gotta be const FString to pass into a func like this.

	//Hide or unhide a stat, stays hidden until unhidden.  Updates while hidden.
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "OnScreenDebug")
	void SetStatHidden(FName inTitle, bool inHidden);
};
