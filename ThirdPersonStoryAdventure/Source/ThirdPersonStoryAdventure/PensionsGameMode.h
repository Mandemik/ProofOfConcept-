// palinoia interactive 2022

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PensionsGameMode.generated.h"

class UStressSystemManagerComponent;

UCLASS()
class THIRDPERSONSTORYADVENTURE_API APensionsGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	APensionsGameMode();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStressSystemManagerComponent* StressManager;
};
