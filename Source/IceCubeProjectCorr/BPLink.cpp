#include "BPLink.h"
#include "Utils.h"

ABPLink::ABPLink()
{
	PrimaryActorTick.bCanEverTick = true;

}
void ABPLink::BeginPlay()
{
	Super::BeginPlay();
	onTest.Broadcast();
}
void ABPLink::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABPLink::Test()
{
	LOG_W(LogTemp, "Test");
}

void ABPLink::TestParam(float _value)
{
	LOG_W(LogTemp, "%f", _value);
}

