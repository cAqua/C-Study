// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <ThirdParty/OpenColorIO/Deploy/OpenColorIO-2.2.0/include/OpenColorIO/OpenColorIO.h>

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyFirstActor.generated.h"

UCLASS()
class THIRTEENWEEK_API AMyFirstActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	/**
	 * @brief 
	 */
	AMyFirstActor();

	virtual void Destroyed() override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
