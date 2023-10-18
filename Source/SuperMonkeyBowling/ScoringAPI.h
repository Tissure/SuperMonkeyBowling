// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ScoringAPI.generated.h"

/**
 * 
 */
UCLASS()
class SUPERMONKEYBOWLING_API UScoringAPI : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable, Category="Scoring")
	static int CalculateScore(float time, int bowling);
};
