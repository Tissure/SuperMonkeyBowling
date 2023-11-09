// Fill out your copyright notice in the Description page of Project Settings.

#include "CoreMinimal.h"
#include "MetaDataAdderHelper.h"
#include <Framework/MetaData/DriverMetaData.h>

void UMetaDataAdderHelper::AddMetaDataFunc(UPARAM(DisplayName = "UI Asset") UUserWidget* InAsset, UPARAM(DisplayName = "ID Value") FName InName)
{
	InAsset->TakeWidget()->AddMetadata(FDriverMetaData::Id(InName));

}
