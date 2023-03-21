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
	demo = CreateDefaultSubobject<UDemoModeComponent>("demo");
	spring->SetupAttachment(RootComponent);
	camera->SetupAttachment(spring);

	AddOwnedComponent(demo);
}
void AGridPawn::BeginPlay()
{
	Super::BeginPlay();

	InitPawn();

}
void AGridPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


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
	if (useDemoMode && demo)
	{
		demo->StartDemo(1);
		DisableInput(FPC);
	}

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

