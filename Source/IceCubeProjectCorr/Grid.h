#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Grid.generated.h"

USTRUCT()
struct FGridSettings
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, meta = (UIMin = 2, ClampMin = 2))
		int size = 4;
	UPROPERTY(EditAnywhere, meta = (UIMin = 1, ClampMin = 1))
		int gap = 100;

	TArray<FVector> gridPoints;
	float minX, maxX, minY, maxY;
};

UCLASS()
class ICECUBEPROJECTCORR_API AGrid : public AActor
{
	GENERATED_BODY()
		DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGridGenerated, FGridSettings&, _grid);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGridLocation, FVector , _location);

		UPROPERTY(EditAnywhere)
		FGridSettings settings;

		FOnGridGenerated onGridGenerated;
		FOnGridLocation onGridLocation;
public:	
	FORCEINLINE FOnGridGenerated& OnGridGenerated() {
		return onGridGenerated;
	}
	FORCEINLINE FOnGridLocation& OnGridLocation() {
		return onGridLocation;
	};
	AGrid();
	void SnapToStart(AActor* _toSnap);
	void MoveToCellDirection(AActor* _toMove, FVector _direction);
	void PickLocation(AActor* _target);
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void Generate();
	void DrawGrid();

};
