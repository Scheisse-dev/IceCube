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
}

void Aspaceship::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//BIND_AXIS(HORIZONTAL, this, &Aspaceship::Rotate);
}

void Aspaceship::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(VERTICAL, this, &Aspaceship::MoveForward);
	PlayerInputComponent->BindAxis(HORIZONTAL, this, &Aspaceship::Rotate);
	
}

void Aspaceship::MoveForward(float _axis)
{
	forwardVelocity = FMath::Lerp(forwardVelocity, FMath::Abs(_axis), DELTATIME * fwdWeight);
	shipVelocity = GetActorForwardVector() * forwardVelocity;
	AddActorWorldOffset(shipVelocity * 100);
}

void Aspaceship::Rotate(float _axis)
{
	rotateAxis = FMath::Lerp(rotateAxis, _axis, DELTATIME * rotateWeight);
	AddActorLocalRotation(FRotator(0, rotateAxis * 10 * DELTATIME, 0));
	const FRotator _bank = FMath::Lerp(GetActorRotation(), FRotator(maxPitchAngle * pitchAxis, GetActorRotation().Yaw, bankAngle * rotateAxis), DELTATIME);
	SetActorRotation(_bank);

	//AddControllerYawInput(_axis * DELTATIME * 10);

	//LOG_W(LogTemp, "%f", rotateAxis);
}

