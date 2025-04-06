// Copyright Montebabbit Interactive 

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AuraAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UAuraAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	//Replicated sta a dire che deve essere replicata per la rete, ReplicatedUsing serve a definire quale funzione usa per notificare la replica
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Main attribute")
	FGameplayAttributeData Health;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Main attribute")
	FGameplayAttributeData MaxHealth;
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Main attribute")
	FGameplayAttributeData Mana;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Main attribute")
	FGameplayAttributeData MaxMana;

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldValue) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldValue) const;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldValue) const;

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldValue) const;
};
