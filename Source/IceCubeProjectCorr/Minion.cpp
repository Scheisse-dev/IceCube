#include "Minion.h"

AMinion::AMinion()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("mesh");
	RootComponent = mesh;
}

void AMinion::BeginPlay()
{
	Super::BeginPlay();
	
}
void AMinion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector _targetLocation = LERP(GetActorLocation(),PAWN->GetActorLocation() + PAWN->GetActorRightVector() * 200, DELTATIME);
	SetActorLocation(_targetLocation);
	SetActorRotation(PAWN->GetActorRotation());
	//TODO setrotation to target point

}



void AMinion::SetPosition()
{
	//if (GetWorld()->GetFirstPlayerController()->GetPawn() == nullptr)
	//	return;

	SetActorLocation(GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation());
}
