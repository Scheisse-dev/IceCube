#include "PawnCorr.h"
#include "Utils.h"

APawnCorr::APawnCorr()
{
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>("mesh");
	springArm = CreateDefaultSubobject<USpringArmComponent>("springArm");
	camera = CreateDefaultSubobject<UCameraComponent>("camera");

	RootComponent = mesh;
	springArm->SetupAttachment(RootComponent);
	camera->SetupAttachment(springArm);

	movement = CreateDefaultSubobject<UFloatingPawnMovement>("movement");
	AddOwnedComponent(movement);

	bUseControllerRotationYaw = true;
}

void APawnCorr::BeginPlay()
{
	Super::BeginPlay();
}

void APawnCorr::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DRAW_SPHERE((GetActorLocation() + GetVelocity().GetClampedToMaxSize(100)), 5, FColor::Yellow, 2);
	DRAW_LINE(GetActorLocation(), (GetActorLocation() + GetVelocity().GetClampedToMaxSize(100)), FColor::Yellow, 2);
}

void APawnCorr::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(VERTICAL, this, &APawnCorr::MoveFoward);
	PlayerInputComponent->BindAxis(HORIZONTAL, this, &APawnCorr::Yaw);
	PlayerInputComponent->BindAxis(HORIZONTAL, this, &APawnCorr::RollMovement);
}

void APawnCorr::MoveFoward(float _axis)
{
	if (_axis < 0)
		return;
	settings.forwardAxis = FMath::Lerp(settings.forwardAxis, _axis, DELTATIME * (1 / settings.forwardWeight));
	AddMovementInput(GetActorForwardVector(), settings.forwardAxis);
}
void APawnCorr::RollMovement(float _axis)
{
	settings.rollAxis = FMath::Lerp(settings.rollAxis, _axis, DELTATIME * (1 / settings.rollWeight));
	SetActorRotation(FRotator(0,0, settings.maxAngle * settings.rollAxis));
}

void APawnCorr::Yaw(float _axis)
{
	settings.yawAxis = FMath::Lerp(settings.yawAxis, _axis, DELTATIME * (1 / settings.yawWeight));
	AddControllerYawInput(settings.yawAxis);
}


