// Copyright Thorn Productions Inc.

#pragma once

#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTINGGROUNDS2_API UPatrolRoute : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPatrolRoute();
	TArray<AActor*> GetPatrolPoints() const;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
	TArray<AActor*> PatrolPoints;
};
