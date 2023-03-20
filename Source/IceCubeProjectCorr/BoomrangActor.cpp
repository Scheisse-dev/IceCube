

#include "BoomrangActor.h"

ABoomrangActor::ABoomrangActor()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("mesh");
	RootComponent = mesh;
}

void ABoomrangActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABoomrangActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Rotate();
	LocationSwitch();
}

void ABoomrangActor::Rotate()
{
	AddActorLocalRotation(FRotator(0, 1, 0));
}

void ABoomrangActor::LocationSwitch()
{
	FVector _lerp = FMath::Lerp(GetActorLocation(), GetActorLocation() + GetActorForwardVector(), GetWorld()->DeltaTimeSeconds);
	SetActorLocation(_lerp);
}

