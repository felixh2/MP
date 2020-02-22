// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TugOfWar.generated.h"

/**
 * 
 */
UCLASS()
class LEARNINGMP_API UTugOfWar : public UUserWidget
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable)
		float InitTugOfWar(TArray<float> EnemiesHP, TArray<float> Weights, float PlayersInsenity, float& OutMaxRight, float& OutMinLeft);

		UFUNCTION(BlueprintCallable)
		float CalcMeanValue(TArray<float> EnemiesHP, float PlayersInsenity);


private:
	TArray<float> EnemiesWeights;
	float MeanValue = 0;
	float Denominator = 0;
	float Numerator = 0;
	float X1 = 0;
	bool InitCompleted = 0;
};
