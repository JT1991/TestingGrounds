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
	return nullptr;
}

void UActorPool::Return(AActor* ActorToReturn)
{

	if (ActorToReturn == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("[%s] Returned null actor"), *GetName());
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("[%s] Actor returned: [%s]."), *GetName(), *ActorToReturn->GetName());
}

void UActorPool::Add(AActor* ActorToAdd)
{
	if (ActorToAdd == nullptr)
		{
			UE_LOG(LogTemp, Error, TEXT("[%s] Returned null actor"), *GetName());
			return;
		}
	UE_LOG(LogTemp, Warning, TEXT("[%s] Actor Added: [%s]."), *GetName(), *ActorToAdd->GetName());
}

