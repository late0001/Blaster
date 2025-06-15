// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include "GameFramework/GameStateBase.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	int32 NumberOfPlayers = GameState.Get()->PlayerArray.Num();
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1,
			15.f,
			FColor::Yellow,
			FString::Printf(TEXT("Current level have %d player joined!"),NumberOfPlayers));
	}
	if (NumberOfPlayers == 2)
	{
		UWorld* World = GetWorld();
		if (World)
		{
			if (GEngine) {
				GEngine->AddOnScreenDebugMessage(-1,
					15.f,
					FColor::Yellow,
					FString::Printf(TEXT("Entry next level !!!!")));
			}
			bUseSeamlessTravel = true;
			World->ServerTravel(FString("/Game/Maps/BlasterMap?listen"));
		}
	}
}
