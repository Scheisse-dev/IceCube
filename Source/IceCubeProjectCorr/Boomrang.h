#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Boomrang.generated.h"

UCLASS()
class ICECUBEPROJECTCORR_API ABoomrang : public APawn
{
	GENERATED_BODY()

public:
	ABoomrang();

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void Rotate();

};
