#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Grid.h"
#include "GridGM.generated.h"

UCLASS()
class ICECUBEPROJECTCORR_API AGridGM : public AGameModeBase
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		TSoftObjectPtr<AGrid> grid = nullptr;


public:
	FORCEINLINE TObjectPtr<AGrid> GetGrid() const
	{
		return grid.Get();
	}
};
