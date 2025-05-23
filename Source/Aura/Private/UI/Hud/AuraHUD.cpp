// Copyright Montebabbit Interactive 


#include "UI/Hud/AuraHUD.h"
#include "UI/Widget/AuraUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	//******************************************************************************************* -> NOTA PER ANDREA DEL FUTURO
	//in questo punto Stephen lo ha fatto diverso. Io ho fatto sotto di testa mia, se ci sono problemi ho un riferimento all'implementazione
	// originale.
	// if (OverlayWidgetController == nullptr)
	//{
	//	OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
	//	OverlayWidgetController->SetWidgetControllerParams(WCParams);
	//
	//	return OverlayWidgetController;
	//}
	//return OverlayWidgetController;
	//******************************************************************************************* <- FINE NOTA PER ANDREA DEL FUTURO
	if (OverlayWidgetController)
	{
		return OverlayWidgetController;
	}
	else {
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		OverlayWidgetController->BindCallBacksToDependencies();//<-- manca sopra perch� agiunto in un video successivo
		return OverlayWidgetController;
	}
	
}

void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	//checkf fa il controllo e restituisce un messaggio di errore specifico che gli viene passato nella funzione
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class uninitialized, please fill out BP_AuraHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class uninitialized, please fill out BP_AuraHUD"));
	
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UAuraUserWidget>(Widget);

	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);

	OverlayWidget->SetWidgetController(WidgetController);
	WidgetController->BroadCastInitialValue();
	//WidgetController->BindCallBacksToDependencies(); <--La mia prima idea, ma stephen suggerisce di metterlo nel get appena il widget controller viene costruito

	OverlayWidget->AddToViewport();

}
