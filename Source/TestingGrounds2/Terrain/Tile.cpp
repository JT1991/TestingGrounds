// Copyright Thorn Productions Inc.

#include "TestingGrounds2.h"
#include "Tile.h"
#include "DrawDebugHelpers.h"

// Sets default values
ATile::ATile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ATile::PlaceActors(TSubclassOf<AActor> ToSpawn, int MinSpawn, int MaxSpawn, float Radius)
{
	int numbertospawn = FMath::RandRange(MinSpawn, MaxSpawn);
	for (size_t i = 0; i < numbertospawn; i++)
	{
		FVector SpawnPoint;
		bool Found = FindEmptyLocation(SpawnPoint, Radius);
		if (Found) {
			PlaceActor(ToSpawn, SpawnPoint);
		}
	}
}

bool ATile::FindEmptyLocation(FVector& OutLocation ,float Radius)
{
	FVector Min(0, -2000, 0);
	FVector Max(4000, 2000, 0);
	FBox Bounds(Min, Max);
	const int MAX_ATTEMPTS = 100;
	for (size_t i = 0; i < MAX_ATTEMPTS; i++) 
	{
		FVector CandidatePoint = FMath::RandPointInBox(Bounds);
		if (CanSpawnAtLocation(CandidatePoint, Radius)) {
			OutLocation = CandidatePoint;
			return true;
		}
	}
	return false;
};

void ATile::PlaceActor(TSubclassOf<AActor> ToSpawn, FVector SpawnPoint){
	AActor* Spawned = GetWorld()->SpawnActor<AActor>(ToSpawn);
	Spawned->SetActorRelativeLocation(SpawnPoint);
	Spawned->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
};


void ATile::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ATile::CanSpawnAtLocation(FVector Location, float Radius)
{

	FHitResult HitResult;
	//convert from local space to global space.
	FVector GlobalLocation = ActorToWorld().TransformPosition(Location);
	bool HasHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		GlobalLocation,
		GlobalLocation,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(Radius)
	);
	// if hashit = true, return red sphere, otherwise return green sphere
	FColor ResultColour = HasHit ? FColor::Red : FColor::Green; 
	DrawDebugCapsule(GetWorld(), GlobalLocation, 0 , Radius, FQuat::Identity, ResultColour, true, 100);
	return !HasHit;
}
