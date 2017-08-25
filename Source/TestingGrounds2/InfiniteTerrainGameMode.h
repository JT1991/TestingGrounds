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
	AInfiniteTerrainGameMode();
	UFUNCTION(BlueprintCallable, Category = "Bounds Pool")
	void PopulateBoundsVoumePool();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pool")
	class UActorPool* NavMeshBoundsVolumePool;

private:
	void AddToPool(class ANavMeshBoundsVolume *VolumeToAdd);
	
};
