#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Grid.h"
#include "MoveOnGridComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ICECUBEPROJECTCORR_API UMoveOnGridComponent : public UActorComponent
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		TObjectPtr<AGrid> grid = nullptr;
	UPROPERTY(EditAnywhere)
		FVector offset = FVector(0, 0, 100);

	FVector targetLocation;
public:	
	UMoveOnGridComponent();
private:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Init();
	UFUNCTION() void SetLocation(FVector _location);
	void MoveToLocation();
	void LookAtDirection();
		
};
