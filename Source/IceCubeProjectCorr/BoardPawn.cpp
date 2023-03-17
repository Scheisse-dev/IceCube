#include "BoardPawn.h"
#include "Utils.h"


ABoardPawn::ABoardPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CREATE(UStaticMeshComponent, "mesh");

	
	camera = CREATE(UCameraComponent, "camera");
	springArm = CREATE(USpringArmComponent, "springArm");
	movement = CREATE(UFloatingPawnMovement, "movement");

	RootComponent = mesh;

	springArm->SetupAttachment(RootComponent);
	camera->SetupAttachment(springArm);

	AddOwnedComponent(movement);
}

void ABoardPawn::BeginPlay()
{
	Super::BeginPlay();
	//SetActorLocation();
	initialLocation = GetActorLocation();
	// TODO, set at -> board origin point
}

void ABoardPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateTimer();
}

void ABoardPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(VERTICAL, this, &ABoardPawn::MoveForward);
	PlayerInputComponent->BindAxis(HORIZONTAL, this, &ABoardPawn::MoveRight);

}

void ABoardPawn::MoveForward(float _axis)
{
	if (!canMove)
		return;
	//AddActorWorldOffset(FVector(_axis * 100,0,0));
	FVector _targetVerticalLocation = GetActorLocation() + FVector(_axis * settings.gap, 0, 0);
	_targetVerticalLocation.X = FMath::Clamp(_targetVerticalLocation.X, initialLocation.X , initialLocation.X + (settings.gap * (settings.pointNumber - 1)));
	SetActorLocation(_targetVerticalLocation);
	if (_axis != 0)
		canMove = false;
}

void ABoardPawn::MoveRight(float _axis)
{
	if (!canMove)
		return;
	//AddActorWorldOffset(FVector(0, _axis * 100, 0));
	FVector _targetVerticalLocation = GetActorLocation() + FVector(0,_axis * settings.gap, 0);
	_targetVerticalLocation.Y = FMath::Clamp(_targetVerticalLocation.Y, initialLocation.Y, initialLocation.Y + (settings.gap * (settings.pointNumber - 1)));
	SetActorLocation(_targetVerticalLocation);
	if (_axis != 0)
		canMove = false;
}

void ABoardPawn::UpdateTimer()
{
	if (!canMove)
	{
		timer += DELTATIME;
		if (timer > maxTimer)
		{
			canMove = true;
			timer = 0;
		}
	}
}

