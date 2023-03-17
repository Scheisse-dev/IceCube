#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Utils.h"
#include "Bud.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ICECUBEPROJECTCORR_API UBud : public UActorComponent
{
	GENERATED_BODY()


		FVector targetPosition;
public:	
	UBud();
	void MoveBud();
	void LookAt();
private:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
