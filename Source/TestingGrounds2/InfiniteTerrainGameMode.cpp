// Copyright Thorn Productions Inc.

#include "TestingGrounds2.h"
#include "InfiniteTerrainGameMode.h"
#include "AI/Navigation/NavMeshBoundsVolume.h"
#include "EngineUtils.h"
#include "ActorPool.h"

AInfiniteTerrainGameMode::AInfiniteTerrainGameMode()
{
	NavMeshBoundsVolumePool = CreateDefaultSubobject<UActorPool>(FName("Nav Mesh Bounds Volume Pool"));
}

void AInfiniteTerrainGameMode::PopulateBoundsVoumePool()
{
	auto  VolumeIterator = TActorIterator<ANavMeshBoundsVolume>(GetWorld());
	while (VolumeIterator)
	{
		AddToPool(*VolumeIterator);
		++VolumeIterator;
	}
}

void AInfiniteTerrainGameMode::AddToPool(class ANavMeshBoundsVolume *VolumeToAdd)
{
	UE_LOG(LogTemp, Warning, TEXT("Found Actor: %s"), *VolumeToAdd->GetName());
	NavMeshBoundsVolumePool->Add(VolumeToAdd);
}


