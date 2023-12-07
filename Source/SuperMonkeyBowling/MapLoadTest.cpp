// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com


// Fill out your copyright notice in the Description page of Project Settings.

#if WITH_EDITOR
#include "MapLoadTest.h"
#include "Misc/AutomationTest.h"
#include <Tests/AutomationEditorCommon.h>
#include <FileHelpers.h>

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMapLoadTest, "FMapLoadTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMapLoadTest::RunTest(const FString& Parameters) {

	// Providing the name of the Map.
	FString MapName = TEXT("/Game/Maps/KyleNWorkspace.KyleNWorkspace");


	bool bLoadAsTemplate = false;
	bool bShowProgress = false;
	return FEditorFileUtils::LoadMap(MapName, bLoadAsTemplate, bShowProgress);

	// Testing the loading of the map.
	//FAutomationEditorCommonUtils::LoadMap(MapName);


	//return true;
}

FMapLoadTest::MapLoadTest()
{
}

FMapLoadTest::~MapLoadTest()
{
}
#endif