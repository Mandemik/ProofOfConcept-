// palinoia interactive 2022

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StressSystemManagerComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THIRDPERSONSTORYADVENTURE_API UStressSystemManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<int> StressTresholds;
};
