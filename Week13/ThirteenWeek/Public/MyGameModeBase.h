
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class THIRTEENWEEK_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	AMyGameModeBase();
	
	virtual void BeginPlay() override;
	
	void TestSpawnActor();

	UFUNCTION(Exec) void TestDestroyActor()const;
	
	class AMyFirstActor* AFirstActor;
	
protected:
public:
	// virtual void Tick(float DeltaTime) override;
};