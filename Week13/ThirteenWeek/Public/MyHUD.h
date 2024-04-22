// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class THIRTEENWEEK_API AMyHUD : public AHUD
{
	GENERATED_BODY()
	AMyHUD();

	void DrawTextFunction();
	UFont* TestFontPointer;
	virtual void BeginPlay() override;
	virtual void DrawHUD() override;

	void DrawTextureFunction();

	UTexture* IconPointer;
	UTexture* IconTexturePointer;

	USoundBase* SoundPointer;
	void PlayerSound();

	//绘制实心四边形
	void DrawRectFunction();
	virtual void NotifyHitBoxClick(FName BoxName) override;
	virtual void NotifyHitBoxRelease(FName BoxName) override;
	bool bShowDogToggle;

	//定时器开关
	void TimerCallBack();
};
