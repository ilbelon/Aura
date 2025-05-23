// Copyright Montebabbit Interactive 


#include "AbilitySystem/AuraAbilitySystemComponent.h"

void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied);
}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle GameplayEffectHandle)
{
	GEngine->AddOnScreenDebugMessage(1, 8.f, FColor::Blue, FString("Effect Applied!"));

    FGameplayTagContainer TagContainer;
    EffectSpec.GetAllAssetTags(TagContainer);
    //for (const FGameplayTag& Tag : TagContainer)
    //{
    //    //TODO: Broadcast the tag to the Widget Controller
    //    const FString Msg = FString::Printf(TEXT("GE Tag: %s"), *Tag.ToString());
    //    GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Blue, Msg);
    //}

    EffectAssetTags.Broadcast(TagContainer);
}
