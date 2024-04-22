// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameModeBase.h"
#include "Kismet/KismetSystemLibrary.h"

#include "MyFirstActor.h"
#include "Engine/World.h"

#include "Kismet/GameplayStatics.h"


#include "MyHUD.h"


AMyGameModeBase::AMyGameModeBase()
	:AFirstActor(nullptr)
{
	HUDClass = AMyHUD::StaticClass();
}

void AMyGameModeBase::TestSpawnActor()
{
	AFirstActor = GetWorld()->SpawnActor<AMyFirstActor>(AMyFirstActor::StaticClass(),FVector::ZeroVector,FRotator::ZeroRotator);	
	// class APlayerController* PC =UGameplayStatics::GetPlayerController(AFirstActor,0);
	// PC->SetShowMouseCursor(true);
	// PC->bEnableClickEvents = true;
}

void AMyGameModeBase::TestDestroyActor() const
{
	if(AFirstActor)
	{
		AFirstActor->Destroyed();
	}else
	{
		UE_LOG(LogTemp, Warning, TEXT("空指针"))
	}
}

void AMyGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	TestSpawnActor();
	UKismetSystemLibrary::PrintString(GetWorld(),TEXT("世界你好！"),true,true,FLinearColor::Red,5);
}

// void 