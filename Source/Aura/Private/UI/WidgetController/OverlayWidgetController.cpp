// Copyright Montebabbit Interactive 


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/AuraAttributeSet.h"

void UOverlayWidgetController::BroadCastInitialValue()
{
	//non chiama Super perché la definizione è vuota
	
	//******************************************************************************************* -> NOTA PER ANDREA DEL FUTURO
	//Porvando a fare questa cosa da solo mi sono piantato su una cagata, ho provato a chiamare
	// GetHealth() direttamente dall' AttributeSet ma è un puntatore di tipo "UAttributeSet" 
	// (TObjectPtr<UAttributeSet> AttributeSet;) per cui NON CONTIENE le funzioni di UAuraAttributeSet
	// tra i quali GetHealth(). Per farlo bisogna fare prima il cast o castchecked come sotto
	// 
	// ---->   OnHealthChanged.Broadcast(AttributeSet->GetHealth());  <------
	//******************************************************************************************* <- FINE NOTA PER ANDREA DEL FUTURO

	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(AuraAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(AuraAttributeSet->GetMaxHealth());
}

void UOverlayWidgetController::BindCallBacksToDependencies()
{
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}
