// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_EnemyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NavigationSystem.h"
#include "DrawDebugHelpers.h"
#include "Navigation/PathFollowingComponent.h"

void ABP_EnemyAIController::BeginPlay()
{
    Super::BeginPlay();

    UE_LOG(LogTemp, Warning, TEXT(" Enemy AI BeginPlay"));
    // Behavior Tree 실행은 블루프린트에서 이미 하고 있다고 가정
}

void ABP_EnemyAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    if (UBlackboardComponent* BB = GetBlackboardComponent())
    {
        FVector TargetLocation = BB->GetValueAsVector(PlayerLocationKey);

        if (TargetLocation.IsNearlyZero()) return;

        DrawDebugSphere(GetWorld(), TargetLocation, 40.f, 12, FColor::Red, false, 0.1f);

        EPathFollowingRequestResult::Type Result = MoveToLocation(TargetLocation);

        if (Result == EPathFollowingRequestResult::Failed)
        {
            UE_LOG(LogTemp, Error, TEXT(" MoveToLocation FAILED: %s"), *TargetLocation.ToString());
        }
        else if (Result == EPathFollowingRequestResult::Type::AlreadyAtGoal)
        {
            UE_LOG(LogTemp, Log, TEXT(" Already at goal"));
        }
        else
        {
            UE_LOG(LogTemp, Log, TEXT(" Moving to: %s"), *TargetLocation.ToString());
        }
    }
}