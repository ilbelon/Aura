// Copyright Montebabbit Interactive 


#include "Character/AuraEnemy.h"
#include "Aura/Aura.h"

void AAuraEnemy::HighlightActor()
{
	//UE_LOG(LogTemp, Warning, TEXT("HighlightActor BeingCalled"));
	//DrawDebugSphere(GetWorld(), GetActorLocation(), 23.f, 24, FColor::Emerald, false);
	bHighligth = true;
	GetMesh()->SetRenderCustomDepth(true);
	//GetMesh()->SetCustomDepthStencilValue(250);
	if (Weapon)
	{
		Weapon->SetRenderCustomDepth(true);
	}
}

void AAuraEnemy::UnHighlightActor()
{
	//UE_LOG(LogTemp, Warning, TEXT("UnHighlightActor BeingCalled"));
	bHighligth = false;
	GetMesh()->SetRenderCustomDepth(false);
	if (Weapon) 
	{
		Weapon->SetRenderCustomDepth(false);
	}
	
}

AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM__DEPTH_RED);
	if (Weapon)
	{
		Weapon->SetCustomDepthStencilValue(CUSTOM__DEPTH_RED);
	}
}
