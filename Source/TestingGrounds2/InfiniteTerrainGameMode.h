// Copyright Thorn Productions Inc.

#pragma once

#include "CoreMinimal.h"
#include "TestingGrounds2GameMode.h"
#include "InfiniteTerrainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS2_API AInfiniteTerrainGameMode : public ATestingGrounds2GameMode
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "Bounds Pool")
	void PopulateBoundsVoumePool();

private:
	void AddToPool(class ANavMeshBoundsVolume *VolumeToAdd);

	
};
