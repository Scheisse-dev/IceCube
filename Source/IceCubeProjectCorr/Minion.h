#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Utils.h"
#include "Minion.generated.h"

UCLASS()
class ICECUBEPROJECTCORR_API AMinion : public AActor
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;
public:	
	AMinion();
	void SetPosition();
	
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
