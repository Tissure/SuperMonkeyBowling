// Fill out your copyright notice in the Description page of Project Settings.

/*
* WARNING:
* 1. Please take care to not have the same TestClass name as other Specs.
* 2. Tentatively, whenever changes are made to Automation Tests, you must restart the Editor completely to see any changes in the Session Frontend
*/

#include "MainUI_TestStartButton.h"
#include <Developer/AutomationDriver/Public/AutomationDriverTypeDefs.h>
#include <Tests/AutomationEditorCommon.h>
#include "Misc/AutomationTest.h"

#include <Tests/AutomationEditorCommon.h>
#include <FileHelpers.h>
#include "LocateBy.h"
#include "IAutomationDriver.h"
#include "IAutomationDriverModule.h"
#include "IDriverElement.h"
#include "IDriverSequence.h"

#include "Misc/AutomationTest.h"

#define TEST_TRUE(expression) \
	EPIC_TEST_BOOLEAN_(TEXT(#expression), expression, true)

#define TEST_FALSE(expression) \
	EPIC_TEST_BOOLEAN_(TEXT(#expression), expression, false)

#define TEST_EQUAL(expression, expected) \
	EPIC_TEST_BOOLEAN_(TEXT(#expression), expression, expected)

#define EPIC_TEST_BOOLEAN_(text, expression, expected) \
	TestEqual(text, expression, expected);

BEGIN_DEFINE_SPEC(testMainMenuStart, "Tests.UserInterface.MainMenuStartz", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

// Define Spec here... Your related variables go here so we have a reference to them when testing.
FAutomationDriverPtr Driver;

END_DEFINE_SPEC(testMainMenuStart)

void testMainMenuStart::Define() {

	Describe("describe", [this]() {

		BeforeEach([this]() {

			if (IAutomationDriverModule::Get().IsEnabled())
			{
				IAutomationDriverModule::Get().Disable();
			}

			IAutomationDriverModule::Get().Enable();

			Driver = IAutomationDriverModule::Get().CreateDriver();

		});

		It("it", [this]() {
			// Providing the name of the Map.
			FString MapName = TEXT("/Game/Maps/MainMenuMap.MainMenuMap");

			bool bLoadAsTemplate = false;
			bool bShowProgress = false;
			TEST_TRUE(FEditorFileUtils::LoadMap(MapName, bLoadAsTemplate, bShowProgress));
			
			/*bool b = Driver->FindElement(By::Id(""))->Exists();*/

			//FDriverSequenceRef Sequence = Driver->CreateSequence();
			//Sequence->Actions()
			//	.Click(By::Id("KeyG"))
			//	.Click(By::Id("KeyF"))
			//	.Click(By::Id("KeyE"));
		});

		It("it pt.2",[this]() {
			TEST_TRUE(Driver->FindElement(By::Id("BStart"))->Exists());
		});

		AfterEach([this]() {

		});

	});
}