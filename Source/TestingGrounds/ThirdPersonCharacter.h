// Copyright Thorn Productions Inc.

#pragma once

#include "CoreMinimal.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "ThirdPersonCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API AThirdPersonCharacter : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()
	
	UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
	TArray<AActor*> PatrolPointsCPP;
	
	
};
