// Copyright Montebabbit Interactive 


#include "UI/WidgetController/AuraWidgetController.h"

void UAuraWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
    PlayerController = WCParams.PlayerController;
    PlayerState = WCParams.PlayerState;
    AbilitySystemComponent = WCParams.AbilitySystemComponent;
    AttributeSet = WCParams.AttributeSet;
}

void UAuraWidgetController::BroadCastInitialValue()
{
}

void UAuraWidgetController::BindCallBacksToDependencies()
{
}
