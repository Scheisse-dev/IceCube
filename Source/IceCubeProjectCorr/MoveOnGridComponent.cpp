#include "MoveOnGridComponent.h"
#include <Kismet/KismetMathLibrary.h>

UMoveOnGridComponent::UMoveOnGridComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UMoveOnGridComponent::BeginPlay()
{
	Super::BeginPlay();
	Init();
	
}


void UMoveOnGridComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	MoveToLocation();
	LookAtDirection();
}

void UMoveOnGridComponent::Init()
{
	if (!grid)
		return;
	grid->OnGridLocation().AddDynamic(this, &UMoveOnGridComponent::SetLocation);
}

void UMoveOnGridComponent::SetLocation(FVector _location)
{
	targetLocation = _location + offset;
}

void UMoveOnGridComponent::MoveToLocation()
{
	const FVector _movement = FMath::Lerp(GetOwner()->GetActorLocation(), targetLocation, GetWorld()->DeltaTimeSeconds * 5);
	GetOwner()->SetActorLocation(_movement);
}

void UMoveOnGridComponent::LookAtDirection()
{
	const FRotator _rot = UKismetMathLibrary::FindLookAtRotation(GetOwner()->GetActorLocation(), targetLocation);
	const FRotator _lerp = FMath::Lerp(GetOwner()->GetActorRotation(), _rot, GetWorld()->DeltaTimeSeconds * 5);
	GetOwner()->SetActorRotation(_lerp);
}

