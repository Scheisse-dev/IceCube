#pragma once

#include "CoreMinimal.h"
#include "BoardSettings.generated.h"

USTRUCT()
struct FBoardParams
{

	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		float gap = 100;
	UPROPERTY(EditAnywhere)
		int pointNumber = 10;

};