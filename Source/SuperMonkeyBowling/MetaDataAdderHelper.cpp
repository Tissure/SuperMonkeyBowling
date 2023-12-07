// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com


// Fill out your copyright notice in the Description page of Project Settings.

#include "MetaDataAdderHelper.h"
#include "CoreMinimal.h"
#include <Framework/MetaData/DriverMetaData.h>

void UMetaDataAdderHelper::AddMetaDataFunc(UPARAM(DisplayName = "UI Asset") UUserWidget* InAsset, UPARAM(DisplayName = "ID Value") FName InName)
{
	InAsset->TakeWidget()->AddMetadata(FDriverMetaData::Id(InName));
	InAsset->SetIsEnabled(true);
	InAsset->SetVisibility(ESlateVisibility::Visible);

}

