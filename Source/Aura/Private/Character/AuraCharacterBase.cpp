// Copyright Montebabbit Interactive 


#include "Character/AuraCharacterBase.h"

AAuraCharacterBase::AAuraCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned r
void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}
