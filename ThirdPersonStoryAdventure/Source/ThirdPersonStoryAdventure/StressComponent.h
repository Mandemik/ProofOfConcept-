// palinoia interactive 2022

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StressComponent.generated.h"

class UStressSystemManagerComponent;

UENUM(BlueprintType)
enum class EStressType : uint8
{
	Calm = 0,
	Uneasy,
	Anxious,
	Stressed
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDynamicMulticastDelegateOP_Stress, EStressType, NewType);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THIRDPERSONSTORYADVENTURE_API UStressComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UStressComponent();

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void CheckStressBounds() noexcept;

	UFUNCTION(BlueprintCallable)
	float ModifyStress(float Value) noexcept
	{
		CurrentStress += Value;
		CheckStressBounds();
		return CurrentStress;
	}

	UFUNCTION(BlueprintCallable)
	float SetStress(float Value) noexcept
	{
		CurrentStress = Value;
		CheckStressBounds();
		return CurrentStress;
	}

	UFUNCTION(BlueprintCallable)
	void EnableIncreaseStressOverTime(float InTimeToIncreaseStressBy1 = 5.f) noexcept
	{
		TimeToIncreaseStressBy1 = InTimeToIncreaseStressBy1;
		bIncreaseStressOverTime = true;
		SetComponentTickEnabled(true);
	}

	UFUNCTION(BlueprintCallable)
	void DisableIncreaseStressOverTime() noexcept
	{
		bIncreaseStressOverTime = false;
		SetComponentTickEnabled(false);
	}

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float InitialStress = 0.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bIncreaseStressOverTime = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (EditCondition = "bIncreaseStressOverTime"))
	float TimeToIncreaseStressBy1 = 5.f;

	UPROPERTY(BlueprintAssignable)
	FDynamicMulticastDelegateOP_Stress OnStressTypeChanged;

	float CurrentStress;

	float CurrentTime = 0.f;

	UPROPERTY(BlueprintReadOnly)
	EStressType StressType;

	UPROPERTY()
	UStressSystemManagerComponent* StressManager;
};
