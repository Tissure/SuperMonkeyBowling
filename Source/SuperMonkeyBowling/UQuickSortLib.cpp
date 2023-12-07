// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com


// Fill out your copyright notice in the Description page of Project Settings.


#include "UQuickSortLib.h"

void UQuickSortLib::QuickSort(UPARAM(ref, DisplayName = "TimeScoreArray") TArray<FS_TimeScorePair>& timeScorePairArray, bool ByScore)
{
	if (ByScore) {
		timeScorePairArray.Sort([](const FS_TimeScorePair& A, const FS_TimeScorePair& B) {
			return A.Score > B.Score;
			});
	}
	else {

		timeScorePairArray.Sort([](const FS_TimeScorePair& A, const FS_TimeScorePair& B) {
			return A.Time < B.Time;
			});
	}
}


