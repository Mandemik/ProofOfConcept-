// palinoia interactive 2022

#include "StressComponent.h"
#include "Kismet/GameplayStatics.h"
#include "StressSystemManagerComponent.h"
#include "PensionsGameMode.h"

UStressComponent::UStressComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UStressComponent::BeginPlay()
{
	Super::BeginPlay();

	auto GameMode = Cast<APensionsGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	StressManager = GameMode->StressManager;

	CurrentStress = InitialStress;

	if (!bIncreaseStressOverTime)
	{
		SetComponentTickEnabled(false);
	}
}

void UStressComponent::CheckStressBounds() noexcept
{
	for (int i = 0; i < StressManager->StressTresholds.Num(); ++i)
	{
		if (StressManager->StressTresholds[i] > CurrentStress)
		{
			EStressType TmpStressType = static_cast<EStressType>(i);

			if (TmpStressType != StressType)
			{
				StressType = TmpStressType;

				if (OnStressTypeChanged.IsBound())
				{
					OnStressTypeChanged.Broadcast(StressType);
				}
			}

			return;
		}
	}
}

void UStressComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!bIncreaseStressOverTime)
	{
		SetComponentTickEnabled(false);
		return;
	}

	CurrentTime += DeltaTime;

	if (CurrentTime >= TimeToIncreaseStressBy1)
	{
		CurrentStress += 1;
		CurrentTime = 0.f;
		CheckStressBounds();
	}
}

