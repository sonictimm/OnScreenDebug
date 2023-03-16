// sonictimm 2023

#include "OnScreenDebugList.h"
#include "OnScreenDebugSubsystem.h"

void UOnScreenDebugList::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	UGameInstance* gi = GetGameInstance();
	if (gi != nullptr)
	{
		UOnScreenDebugSubsystem* sub = gi->GetSubsystem<UOnScreenDebugSubsystem>();
		if (sub != nullptr)
		{
			sub->OnDebugStatSet.AddDynamic(this, &UOnScreenDebugList::RecordStat);
			sub->OnDebugStatHidden.AddDynamic(this, &UOnScreenDebugList::SetStatHidden);
		}
	}
}