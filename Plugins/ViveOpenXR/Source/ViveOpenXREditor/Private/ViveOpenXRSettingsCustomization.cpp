// Copyright (c) 2022 HTC Corporation. All Rights Reserved.


#include "ViveOpenXRSettingsCustomization.h"
#include "DetailLayoutBuilder.h"
#include "DetailCategoryBuilder.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Text/SRichTextBlock.h"
#include "Widgets/Input/SButton.h"
#include "DetailWidgetRow.h"
#include "GenericPlatform/GenericPlatformProcess.h"
#include "Misc/Paths.h"
#include "EditorStyleSet.h"
#include "SHyperlinkLaunchURL.h"

#define LOCTEXT_NAMESPACE "OpenXRViveSettings"
TSharedRef<IDetailCustomization> FViveOpenXRSettingsCustomization::MakeInstance()
{
	return MakeShareable(new FViveOpenXRSettingsCustomization);
}

void FViveOpenXRSettingsCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailLayout)
{
	IDetailCategoryBuilder& OverviewCategory = DetailLayout.EditCategory(TEXT("Overview"));
	IDetailCategoryBuilder& ControllerCategory = DetailLayout.EditCategory(TEXT("Controller"));
	IDetailCategoryBuilder& SimultaneousInteractionCategory = DetailLayout.EditCategory(TEXT("Simultaneous Interaction"));
	IDetailCategoryBuilder& HandInteractionCategory = DetailLayout.EditCategory(TEXT("Hand Interaction"));
	IDetailCategoryBuilder& TrackererCategory = DetailLayout.EditCategory(TEXT("Tracker"));
	IDetailCategoryBuilder& FacialTrackingCategory = DetailLayout.EditCategory(TEXT("Facial Tracking"));
	IDetailCategoryBuilder& PassthroughCategory = DetailLayout.EditCategory(TEXT("Passthrough"));
	IDetailCategoryBuilder& InteractiveVisualComputingCategory = DetailLayout.EditCategory(TEXT("Interactive Visual Computing "));
	IDetailCategoryBuilder& DisplayRefreshRateCategory = DetailLayout.EditCategory(TEXT("Display Refresh Rate"));

	OverviewCategory.AddCustomRow(LOCTEXT("ViveOpenXROverviewlink", "Vive OpenXR Overview Hyperlink"), false)
		.WholeRowWidget
		[
			SNew(SBox)
				.HAlign(HAlign_Center)
				[
					SNew(SHyperlinkLaunchURL, TEXT("https://developer.vive.com/resources/openxr/unreal/unreal-overview/"))
						.Text(LOCTEXT("ViveOpenXROverviewPage", "Vive OpenXR Overview & Documentation"))
						.ToolTipText(LOCTEXT("ViveOpenXROverviewPageTooltip", "Overivew of features and supported devices."))
				]
		];
}

FViveOpenXRSettingsCustomization::FViveOpenXRSettingsCustomization()
{
}
