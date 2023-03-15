#include "ActorMovementComponent.h"


#pragma region UE
UActorMovementComponent::UActorMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UActorMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	settings.initLocation = GetOwner()->GetActorLocation();
}

void UActorMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	UpdateMovement();
	UpdateRotation();
	ResetBehaviour();
	DRAW_SPHERE_DEF(GetOwner()->GetActorLocation() + GetVelocity() * 200, 10,5, FColor::Green, 2);
	DRAW_LINE(GetOwner()->GetActorLocation() + GetVelocity() * 200, GetOwner()->GetActorLocation(), FColor::Green, 2);

	DRAW_BOX(settings.initLocation, FVector(10), FColor::Cyan, 2);
	DRAW_LINE(GetOwner()->GetActorLocation(), settings.initLocation, FColor::Cyan, 2);

	
}
#pragma endregion 
#pragma region custom
void UActorMovementComponent::MoveForward(float _axis)
{
	if (isInResetStatus)
		return;
	settings.forwardAxis = FMath::Lerp(settings.forwardAxis, _axis, DELTATIME * settings.forwardWeight);
}

void UActorMovementComponent::MoveHorizontal(float _axis)
{
	if (isInResetStatus)
		return;
	settings.horizontalAxis = FMath::Lerp(settings.horizontalAxis, _axis, DELTATIME * settings.horizontalWeight);
}

void UActorMovementComponent::Rotate(float _axis)
{
	if (isInResetStatus)
		return;
	settings.rotateAxis = FMath::Lerp(settings.rotateAxis, _axis, DELTATIME * settings.rotateWeight);
}
void UActorMovementComponent::UpdateMovement()
{
	if (isInResetStatus)
		return;
	GetOwner()->AddActorWorldOffset(GetVelocity());
}
void UActorMovementComponent::UpdateRotation()
{
	if (isInResetStatus)
		return;
	GetOwner()->AddActorLocalRotation(GetRotationVelocity());
}
void UActorMovementComponent::ResetBehaviour()
{
	if (!isInResetStatus)
		return;
	if (settings.UpdateTimer(WORLD))
	{
		OnEndReset();
		return;
	}

	GetOwner()->SetActorLocation(FMath::Lerp(settings.currentLocation, settings.initLocation, settings.GetResterRatio()));
}
void UActorMovementComponent::CallReset()
{
	if (isInResetStatus)
		return;
	settings.currentLocation = GetOwner()->GetActorLocation();
	settings.ResetValue();
	isInResetStatus = true;
}
void UActorMovementComponent::OnEndReset()
{
	isInResetStatus = false;
}
#pragma endregion 