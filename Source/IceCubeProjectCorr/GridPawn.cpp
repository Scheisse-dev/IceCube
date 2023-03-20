#include "GridPawn.h"
#include "Utils.h"
#include "GridGM.h"


AGridPawn::AGridPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CREATE(UStaticMeshComponent, "mesh");
	RootComponent = mesh;
	camera = CreateDefaultSubobject<UCameraComponent>("camera");
	spring = CreateDefaultSubobject<USpringArmComponent>("springArm");

	spring->SetupAttachment(RootComponent);
	camera->SetupAttachment(spring);


}
void AGridPawn::BeginPlay()
{
	Super::BeginPlay();

	InitPawn();
	//SetRandom();
	startTimer = true;
}
void AGridPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Timer();

}
void AGridPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Up", IE_Pressed, this, &AGridPawn::UpMove);
	PlayerInputComponent->BindAction("Down", IE_Pressed, this, &AGridPawn::DownMove);
	PlayerInputComponent->BindAction("Left", IE_Pressed, this, &AGridPawn::LeftMove);
	PlayerInputComponent->BindAction("Right", IE_Pressed, this, &AGridPawn::RightMove);
	PlayerInputComponent->BindAction("Call", IE_Pressed, this, &AGridPawn::SelectGridCell);
}
void AGridPawn::InitPawn()
{
	grid = GetGrid();
	if (!grid)
		return;
	grid->SnapToStart(this);
	SelectGridCell();


}
TObjectPtr<AGrid> AGridPawn::GetGrid() const
{
	AGridGM* _gm = GetWorld()->GetAuthGameMode<AGridGM>();
	if (!_gm)
		return nullptr;
	return _gm->GetGrid();
}
void AGridPawn::UpMove()
{
	if (!grid)
		return;
	grid->MoveToCellDirection(this, FVector(1,0,0));
}
void AGridPawn::DownMove()
{
	if (!grid)
		return;
	grid->MoveToCellDirection(this, FVector(-1, 0, 0));
}
void AGridPawn::LeftMove()
{
	if (!grid)
		return;
	grid->MoveToCellDirection(this, FVector(0, -1, 0));
}
void AGridPawn::RightMove()
{
	if (!grid)
		return;
	grid->MoveToCellDirection(this, FVector(0, 1, 0));
}
void AGridPawn::SelectGridCell()
{
	if (!grid)
		return;
	grid->PickLocation(this);
}

void AGridPawn::SetRandom()
{
	randomList.Empty();
	moveNumber = FMath::RandRange(3,6);
	for (size_t i = 0; i < moveNumber; i++)
	{
		float _move = FMath::RandRange(0, 3);
		randomList.Add(_move);
	}


	
}

void AGridPawn::Timer()
{
	if (!startTimer)
		return; 
	timer += DELTATIME;
	if (timer > timerGap)
	{
		//onGap.Broadcast();
		timer = 0;
		timerLoop += 1;
		AutoPlay();
		LOG_W(LogTemp, "%f", timerLoop)
	}
	if (timerLoop == moveNumber)
	{
		//onTimerEnd.Broadcast();
		timer = 0;
		timerLoop = 0;
		startTimer = false;
		ResetTimer();
		SelectGridCell();
		
	}
}

void AGridPawn::AutoPlay()
{
	if (!testMod)
		return;
	float _move = FMath::RandRange(0, 3);

	//for (float _movement : randomList)
	//{
		if (_move == 0)
			UpMove();
		else if (_move == 1)
			DownMove();
		else if (_move == 2)
			RightMove();
		else if (_move == 3)
			LeftMove();
	//}
	

}
void AGridPawn::ResetTimer()
{
	timer = 0;
	timerLoop = 0;
	startTimer = true;
	SetRandom();
}