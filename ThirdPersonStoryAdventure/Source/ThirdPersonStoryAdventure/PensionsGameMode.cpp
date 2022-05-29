// palinoia interactive 2022


#include "PensionsGameMode.h"
#include "StressSystemManagerComponent.h"

APensionsGameMode::APensionsGameMode()
{
	StressManager = CreateDefaultSubobject<UStressSystemManagerComponent>(TEXT("StressManager"));
}
