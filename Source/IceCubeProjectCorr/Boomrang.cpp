#include "Boomrang.h"

ABoomrang::ABoomrang()
{
	PrimaryActorTick.bCanEverTick = true;

}
void ABoomrang::BeginPlay()
{
	Super::BeginPlay();
	
}
void ABoomrang::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Rotate();

}
void ABoomrang::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABoomrang::Rotate()
{
	GetWorld()->GetFirstPlayerController()->AddYawInput(1);
}

