
#include "IceCube.h"


AIceCube::AIceCube()
{
	PrimaryActorTick.bCanEverTick = true;
	//RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("mesh");
	camera = CreateDefaultSubobject<UCameraComponent>("camera");
	springArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	movement = CreateDefaultSubobject<UActorMovementComponent>("Movement");
	RootComponent = mesh;
	mesh->SetStaticMesh(LoadObject<UStaticMesh>(this, TEXT("'/Engine/BasicShapes/Cube.Cube'")));

	//mesh->SetupAttachment(RootComponent);
	springArm->SetupAttachment(RootComponent);
	camera->SetupAttachment(springArm);

	AddOwnedComponent(movement);
}
void AIceCube::BeginPlay()
{
	Super::BeginPlay();
	InitIceCube();
	BindInputs();
	
}
void AIceCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	settings.UpdateScaleTimer(WORLD);
	settings.UpdateScale(this);
	ScaleBehaviour();
	DRAW_BOX(GetActorLocation(), settings.TargetSize(), FColor::Red, 2);
	DRAW_BOX(GetActorLocation(), settings.initSize * 100, FColor::Red, 2);


}
#pragma region ICE
void AIceCube::InitIceCube()
{
	WORLD->GetFirstPlayerController()->SetViewTarget(this);
	settings.initSize = GetActorScale();
}
void AIceCube::BindInputs()
{
	BIND_AXIS(VERTICAL, movement.Get(), &UActorMovementComponent::MoveForward);
	BIND_AXIS(HORIZONTAL, movement.Get(), &UActorMovementComponent::MoveHorizontal);
	BIND_AXIS(ROTATE, movement.Get(), &UActorMovementComponent::Rotate);
	BIND_ACTION(RESET, EInputEvent::IE_Pressed, movement.Get(), &UActorMovementComponent::CallReset);
}
void AIceCube::ScaleBehaviour()
{
	if (!movement)
		return;
	movement->UpdateForwadWeight(1 - settings.ScaleRatio() + 0.1f);
	movement->UpdateHorizontalWeight(1 - settings.ScaleRatio() + 0.1f);
	movement->UpdateRotateWeight(1 - settings.ScaleRatio() + 0.1f);
}
#pragma endregion ICE
