// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Blueprint/UserWidget.h"
#include "MetaDataAdderHelper.generated.h"

/**
 * 
 */

UCLASS()
class SUPERMONKEYBOWLING_API UMetaDataAdderHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category="Example Nodes")
	static void AddMetaDataFunc(UPARAM(DisplayName = "UI Asset") UUserWidget* InAsset, UPARAM(DisplayName = "ID Value") FName InName);

};
