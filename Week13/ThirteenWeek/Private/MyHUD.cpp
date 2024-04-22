// Fill out your copyright notice in the Description page of Project Settings.
#include "MyHUD.h"

#include "TimerManager.h"
#include  "Engine/Canvas.h"
#include  "Engine/Font.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

AMyHUD::AMyHUD()
{
	TestFontPointer = nullptr;
	IconPointer = nullptr;
	IconTexturePointer = nullptr;
	bShowDogToggle = true;
	// SoundPointer = nullptr;

	//匿名泛型构造函数
	ConstructorHelpers::FObjectFinder<UTexture> const FindPath(TEXT(
		"/Script/Engine.Texture2D'/Game/Icon/lQLPKHVoSfoCW_XNAnDNAuew97mscrNd40YF7919ttZjAQ_743_624.lQLPKHVoSfoCW_XNAnDNAuew97mscrNd40YF7919ttZjAQ_743_624'"));
	if (FindPath.Object)
	{
		IconTexturePointer = FindPath.Object;
	}
}

void AMyHUD::DrawTextFunction()
{
	if (TestFontPointer)
	{
		DrawText(TEXT("Hello World"), FLinearColor::Red, Canvas->SizeX / 2.f - 50, Canvas->SizeY / 2.f - 30,
		         TestFontPointer);
	}
	else
	{
		DrawText(TEXT("Hello World"), FLinearColor::Red, 100.f, 100.f);
	}
}

void AMyHUD::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("HUD BeginPlayer"));
	TestFontPointer = LoadObject<UFont>(nullptr,TEXT("/Script/Engine.Font'/Game/Fonts/ARIALUNI_Font.ARIALUNI_Font'"));

	IconPointer = LoadObject<UTexture>(nullptr,TEXT(
		                                   "/Script/Engine.Texture2D'/Game/Icon/lQLPKHVoSfoCW_XNAnDNAuew97mscrNd40YF7919ttZjAQ_743_624.lQLPKHVoSfoCW_XNAnDNAuew97mscrNd40YF7919ttZjAQ_743_624'"));

	// SoundPointer = LoadObject<USoundBase>(nullptr,TEXT(
	// 	                                      "/Script/Engine.SoundWave'/Game/Sounds/Weapons_Pistol_Noise-Interior-Close_03.Weapons_Pistol_Noise-Interior-Close_03'"));
	//
	// UGameplayStatics::PlaySound2D(GetWorld(),);

	// PlayerSound();
	class APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	// class APlayerController* PC = UGameplayStatics::GetPlayerController(Cast<UObject>(GetWorld()), 0);
	PC->SetShowMouseCursor(true);
	PC->bEnableClickEvents = true;

	FTimerHandle Handle;
	GetWorld()->GetTimerManager().SetTimer(Handle,this,&AMyHUD::TimerCallBack,3.f);
	
}

void AMyHUD::DrawHUD()
{
	// UE_LOG(LogTemp, Log, TEXT("DrawHUD 被调用"));
	Super::DrawHUD();
	DrawTextFunction();
	DrawTextureFunction();

	if (bShowDogToggle)
	{
		DrawRectFunction();
	}
}

void AMyHUD::DrawTextureFunction()
{
	if (IconPointer)
	{
		// UE_LOG(LogTemp, Log, TEXT("DrawTextureFuntion"));
		DrawTexture(IconPointer, 70.f, 50.f, 30.f, 100.f, 1, 1, 1, 1);
	}
}

void AMyHUD::PlayerSound()
{
	if (SoundPointer)
	{
	}
}

void AMyHUD::DrawRectFunction()
{
	DrawRect(FLinearColor::Red, 70.f, 50.f, 30.f, 100.f);
	AddHitBox(FVector2D(50.f, 50.f), FVector2D(35.f, 120.f),TEXT("Pause"), true);
}

void AMyHUD::NotifyHitBoxClick(FName BoxName)
{
	Super::NotifyHitBoxClick(BoxName);
	if (BoxName == TEXT("Pause"))
	{
		UE_LOG(LogTemp, Log, TEXT("被点击"));
	}
}

void AMyHUD::NotifyHitBoxRelease(FName BoxName)
{
	Super::NotifyHitBoxRelease(BoxName);
	if (BoxName == TEXT("Pause"))
	{
		UE_LOG(LogTemp, Log, TEXT("松开点击"));
	}
}

void AMyHUD::TimerCallBack()
{
	bShowDogToggle = false;
}
