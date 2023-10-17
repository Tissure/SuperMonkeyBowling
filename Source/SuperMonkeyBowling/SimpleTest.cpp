// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreMinimal.h"
#include "SimpleTest.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(templateMathTest, "SimpleTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool templateMathTest::RunTest(const FString& Parameters) {
	
	return TestTrue("Testing Math.", 1<0);
	
	//return true;
}

SimpleTest::SimpleTest()
{
}

SimpleTest::~SimpleTest()
{
}
