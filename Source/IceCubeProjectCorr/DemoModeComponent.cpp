#include "DemoModeComponent.h"
#include "GridPawn.h"
UDemoModeComponent::UDemoModeComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}



void UDemoModeComponent::BeginPlay()
{
	Super::BeginPlay();
	onDemoAction.AddDynamic(this, &UDemoModeComponent::RunDemo);
}

void UDemoModeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}



void UDemoModeComponent::StartDemo(float _delay)
{
	GetOwner()->GetWorldTimerManager().SetTimer(demoTimer, this, &UDemoModeComponent::DemoAction, _delay, true);
	onDemoStart.Broadcast();
}

void UDemoModeComponent::DemoAction()
{
	onDemoAction.Broadcast();
}

void UDemoModeComponent::RunDemo()
{
	AGridPawn* _player = Cast<AGridPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!_player)
		return;

	int _randAction = FMath::RandRange(0, 4);
	switch (_randAction)
	{
	case 0 :
		_player->RightMove();
		break;
	case 1:
		_player->LeftMove();
		break;
	case 2:
		_player->UpMove();
		break;
	case 3:
		_player->DownMove();
		break;
	}
	_randAction = FMath::RandRange(0, 100);
	if (_randAction > demoCallPlayerRange)
		_player->SelectGridCell();

}

void UDemoModeComponent::StopDemo()
{
	GetWorld()->GetTimerManager().ClearTimer(demoTimer);
	onDemoStop.Broadcast();
}
