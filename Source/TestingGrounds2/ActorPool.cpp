// Copyright Thorn Productions Inc.

#include "TestingGrounds2.h"
#include "ActorPool.h"


// Sets default values for this component's properties
UActorPool::UActorPool()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

AActor* UActorPool::CheckOut()
{
	UE_LOG(LogTemp, Warning, TEXT("[%s} Checkout."), *GetName());
	if (Pool.Num() == 0)
	{
		return nullptr;
	}
	return Pool.Pop();
}

void UActorPool::Return(AActor* ActorToReturn)
{

	if (ActorToReturn == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("[%s] Returned null actor"), *GetName());
		return;
	}
	Add(ActorToReturn);
}

void UActorPool::Add(AActor* ActorToAdd)
{
	if (ActorToAdd == nullptr)
		{
			UE_LOG(LogTemp, Error, TEXT("[%s] Returned null actor"), *GetName());
			return;
		}
	Pool.Push(ActorToAdd);
}

