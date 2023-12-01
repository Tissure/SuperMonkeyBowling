// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FS_TimeScorePair.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct SUPERMONKEYBOWLING_API FS_TimeScorePair
{

	GENERATED_USTRUCT_BODY()
public:
	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Time", MakeStructureDefaultValue = "0.000000"))
	double Time;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Score", MakeStructureDefaultValue = "0"))
	int32 Score;

};
