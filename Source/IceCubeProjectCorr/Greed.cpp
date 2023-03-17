#include "Greed.h"
#include "Utils.h"

AGreed::AGreed()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CREATE(UStaticMeshComponent, "mesh");
	RootComponent = mesh;
}
void AGreed::BeginPlay()
{
	Super::BeginPlay();
	
}
void AGreed::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawBoard();
	//DRAW_LINE(FVector(0, 0, 0), FVector(300, 0, 0), FColor::Green, 2);
}

void AGreed::DrawBoard()
{
	for (int i = 0; i < settings.pointNumber; i++)
	{
		FVector _baseFwdPos = FVector(GetActorLocation().X , GetActorLocation().Y + settings.gap * i , GetActorLocation().Z);
		FVector _finalFwdPos = FVector(GetActorLocation().X +settings.gap * (settings.pointNumber- 1), GetActorLocation().Y + settings.gap * i, GetActorLocation().Z);
		DRAW_LINE(_baseFwdPos, _finalFwdPos, FColor::Red, 2);

		FVector _baseRightPos = FVector(GetActorLocation().X + settings.gap * i, GetActorLocation().Y , GetActorLocation().Z);
		FVector _finalRightPos = FVector(GetActorLocation().X +settings.gap * i, GetActorLocation().Y + settings.gap * (settings.pointNumber -1), GetActorLocation().Z);
		DRAW_LINE(_baseRightPos, _finalRightPos, FColor::Red, 2);
	}

}

