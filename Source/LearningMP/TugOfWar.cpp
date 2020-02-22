// Fill out your copyright notice in the Description page of Project Settings.


#include "TugOfWar.h"



/*
//  We calculate the the following formula :
//
//					(X1 - insenity)w0 - HP1*w1 - HP2*w2 - HP3w3...
//   mean value =		-------------------------------------------
//						w0 + w1 + w2 + w3 + ...
//	Notice:
//	1. we set w0 to be 1 by default
//	2.  0 <= Insenity <= infinite number
*/
float UTugOfWar::InitTugOfWar(TArray<float> EnemiesHP, TArray<float> Weights, float PlayersInsenity, float & OutMaxRight, float & OutMinLeft)
{
	if (EnemiesHP.GetData() != nullptr) {

		if (Weights.GetData() == nullptr) {
			EnemiesWeights.Init(0, EnemiesHP.Num());
			for (int i = 0; i < EnemiesHP.Num(); i++) {
				EnemiesWeights[i] = 1;
			}
		}
		else {
			EnemiesWeights = Weights;
		}

		MeanValue = CalcMeanValue(EnemiesHP, PlayersInsenity);

		OutMaxRight = X1 / 2;
		OutMinLeft = -OutMaxRight;
		InitCompleted = true;
		
		return MeanValue;
	}

	return MAX_FLT;
}

float UTugOfWar::CalcMeanValue(TArray<float> EnemiesHP, float PlayersInsenity)
{
	if (EnemiesHP.GetData() != nullptr) {
	
		Numerator = Denominator = 0;
		for (int i = 0; i < EnemiesHP.Num(); i++) {
			
			// In case Enemy dies we zero his Weight
			if (EnemiesHP[i] <= 0.1) { EnemiesWeights[i] = 0; }
			
			Numerator += EnemiesHP[i] * EnemiesWeights[i];
			if (!InitCompleted) { X1 += EnemiesHP[i]* EnemiesWeights[i]; }
			Denominator += EnemiesWeights[i];
		}
		 
		// Adding player's part
		Numerator = (X1 - PlayersInsenity) - Numerator;
		Denominator += 1;
		MeanValue = (Numerator / Denominator);
		
		return MeanValue;
	}
	
	return MAX_FLT;
	
}
