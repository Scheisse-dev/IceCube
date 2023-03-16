#include "spaceship.h"

// Sets default values
Aspaceship::Aspaceship()
{
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>("mesh");
	RootComponent = mesh;

	springArm = CreateDefaultSubobject<USpringArmComponent>("springArm");
	camera = CreateDefaultSubobject<UCameraComponent>("camera");
	movement = CreateDefaultSubobject<UFloatingPawnMovement>("movement");

	springArm->SetupAttachment(RootComponent);
	camera->SetupAttachment(springArm);

	AddOwnedComponent(movement);

}
void Aspaceship::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetFirstPlayerController()->SetViewTarget(this);
	settings.initialRotation = GetActorRotation(); 
}

void Aspaceship::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//minion.SetPosition(GetActorForwardVector() + FVector(10,0,0));

}

void Aspaceship::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(VERTICAL, this, &Aspaceship::MoveForward);
	PlayerInputComponent->BindAxis(HORIZONTAL, this, &Aspaceship::MoveHorizontal);
	PlayerInputComponent->BindAxis(ROTATE, this, &Aspaceship::Rotate);
}

void Aspaceship::MoveForward(float _axis)
{
	FVector samere = GetActorLocation() + (GetActorForwardVector() * _axis);
	FVector _targetPosition = LERP(GetActorLocation(), samere * 2, DELTATIME);
	SetActorLocation(GetActorLocation() + (GetActorForwardVector() * _axis) * 5);
}

void Aspaceship::MoveHorizontal(float _axis)
{
	AddControllerYawInput(_axis);
}

void Aspaceship::Rotate(float _axis)
{
	AddControllerPitchInput(_axis);
}
