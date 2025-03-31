// Copyright Montebabbit Interactive 


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;//serve per il multiplayer, serve per replicare modifiche dal server
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem< UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	check(Subsystem);
	Subsystem->AddMappingContext(AuraContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}
