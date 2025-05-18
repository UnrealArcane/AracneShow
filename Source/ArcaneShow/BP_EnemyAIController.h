// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BP_EnemyAIController.generated.h"

UCLASS()
class ARCANESHOW_API ABP_EnemyAIController : public AAIController
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;

protected:
    FName PlayerLocationKey = "PlayerActorLocationKey"; // Blackboard ≈∞ ¿Ã∏ß
};
