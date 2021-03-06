// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include <Runtime/SlateCore/Public/Styling/SlateStyle.h>

class FWakaTimeForUE4Module : public IModuleInterface
{
public:


	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	TSharedRef<FSlateStyleSet> Create();
	void OnNewActorDropped(const TArray<UObject*>& Objects, const TArray<AActor*>& Actors);
	void OnDuplicateActorsEnd();
	void OnDeleteActorsEnd();
	void OnAddLevelToWorld(ULevel* Level);
	void OnPostSaveWorld(uint32 SaveFlags, UWorld* World, bool bSucces);
	void OnPostPIEStarted(bool bIsSimulating);
	void OnPrePIEEnded(bool bIsSimulating);
	void OpenSettingsWindow();
	void AddToolbarButton(FToolBarBuilder& Builder);
	FReply SetDeveloper();
	FReply SetDesigner();
	FReply SaveData();

	TSharedPtr<FUICommandList> PluginCommands;
};

class WakaCommands : public TCommands<WakaCommands>
{
public:

	WakaCommands()
		: TCommands<WakaCommands>
		(
			TEXT("WakatimeEditor"),
			NSLOCTEXT("Wakatime", "WakatimeEditor", "Wakatime Plugin"),
			NAME_None,
			FEditorStyle::GetStyleSetName()
			) {}

	virtual void RegisterCommands() override;

public:

	TSharedPtr<FUICommandInfo> TestCommand;
};