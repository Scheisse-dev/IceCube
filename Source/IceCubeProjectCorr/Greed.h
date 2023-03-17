#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoardSettings.h"
#include "Greed.generated.h"



UCLASS()
class ICECUBEPROJECTCORR_API AGreed : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;

	UPROPERTY(EditAnywhere)
		FBoardParams settings;

	
public:	
	AGreed();

protected:
	virtual void BeginPlay() override;	
	virtual void Tick(float DeltaTime) override;
	void DrawBoard();

};
