#include "MyFirstPawn.h"
#include "Utils.h"

AMyFirstPawn::AMyFirstPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("mesh");
	movement = CreateDefaultSubobject<UFloatingPawnMovement>("Movement");
	camera = CreateDefaultSubobject<UCameraComponent>("camera");
	springArm = CreateDefaultSubobject<USpringArmComponent>("springArm");
	RootComponent = mesh;
	mesh->SetStaticMesh(LoadObject<UStaticMesh>(this, TEXT("'/Engine/BasicShapes/Sphere.Sphere'")));
	springArm->SetupAttachment(RootComponent);
	camera->SetupAttachment(springArm);

	AddOwnedComponent(movement);
	bUseControllerRotationYaw = true;

}

void AMyFirstPawn::BeginPlay()
{
	Super::BeginPlay();
	WORLD->GetFirstPlayerController()->SetViewTarget(this);
}

void AMyFirstPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyFirstPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(VERTICAL, this, &AMyFirstPawn::MoveForward);
	PlayerInputComponent->BindAxis(HORIZONTAL, this, &AMyFirstPawn::MoveHorizontal);
	PlayerInputComponent->BindAxis(ROTATE, this, &AMyFirstPawn::RotateYaw);
}

void AMyFirstPawn::MoveForward(float _axis)
{
	AddMovementInput(GetActorForwardVector(), _axis);
}

void AMyFirstPawn::MoveHorizontal(float _axis)
{
	AddMovementInput(GetActorRightVector(), _axis);
}

void AMyFirstPawn::RotateYaw(float _axis)
{
	AddControllerYawInput(_axis * DELTATIME * 5);
}

