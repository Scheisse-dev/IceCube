#include "Grid.h"
#include "Utils.h"

AGrid::AGrid()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
}
void AGrid::BeginPlay()
{
	Super::BeginPlay();
	Generate();
}
void AGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawGrid();
}
void AGrid::Generate()
{
	for (size_t x = 0; x < settings.size; x++)
	{
		for (size_t y = 0; y < settings.size; y++)
		{
			const FVector _point = FVector(x * settings.gap, y * settings.gap, 0) + GetActorLocation();
			settings.gridPoints.Add(_point);
		}
	}
	settings.minY = GetActorLocation().Y;
	settings.maxY = settings.minY + ((settings.size - 1) * settings.gap);
	settings.minX = GetActorLocation().X;
	settings.maxX = settings.minX + ((settings.size - 1) * settings.gap);
	onGridGenerated.Broadcast(settings);
}
void AGrid::DrawGrid()
{
	for (size_t i = 0; i < settings.gridPoints.Num(); i++)
	{
		const FVector _point = settings.gridPoints[i];
		DRAW_BOX(_point, FVector(5), FColor::Red, 2);
		DRAW_TEXT(_point + FVector(0, 0, 100), FString::Printf(TEXT("%s"), *_point.ToString()), FColor::Red, 1.2f);

	}
	DRAW_TEXT(GetActorLocation() + FVector(0, 0, 150), FString::Printf(TEXT("X: %f\n -X : %f\n, Y = %f\n, -Y = %f\n "), settings.minY, settings.maxY, settings.minX, settings.maxX), FColor::Green, 1.2f);
}
void AGrid::SnapToStart(AActor* _toSnap)
{
	if (!_toSnap)
		return;
	_toSnap->SetActorLocation(settings.gridPoints[0]);
}
void AGrid::MoveToCellDirection(AActor* _toMove, FVector _direction)
{
	if (!_toMove)
		return;
	FVector _next = _toMove->GetActorLocation() + _direction * settings.gap;
	_next.X = FMath::Clamp(_next.X, settings.minX, settings.maxX);
	_next.Y = FMath::Clamp(_next.Y, settings.minY, settings.maxY);
	_toMove->SetActorLocation(_next);
}

void AGrid::PickLocation(AActor* _target)
{
	onGridLocation.Broadcast(_target->GetActorLocation());
}

