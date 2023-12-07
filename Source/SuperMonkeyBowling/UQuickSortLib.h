// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FS_TimeScorePair.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UQuickSortLib.generated.h"

/**
 *
 */
UCLASS()
class SUPERMONKEYBOWLING_API UQuickSortLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable, Category = "QuickSort")
	static void QuickSort(UPARAM(ref, DisplayName = "TimeScoreArray") TArray<FS_TimeScorePair>& timeScorePairArray, bool ByScore);
};
