#include "Follower.h"
#include "Utils.h"

UFollower::UFollower()
{
	PrimaryComponentTick.bCanEverTick = true;
}
void UFollower::BeginPlay()
{
	Super::BeginPlay();
	SetTarget(PAWN);
}
void UFollower::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	DRAW_SPHERE(GetTargetLocation(), 50, FColor::Green, 2);
	DRAW_LINE(GetTargetLocation(), GetActorLocation(), FColor::Green, 2);
	DRAW_BOX(GetFinalLocation(), FVector(10), FColor::Red, 2);
	DRAW_LINE(GetFinalLocation(), GetActorLocation(), FColor::Red, 2);
	FollowTarget();
	ReplicateRoll();
	LookAtTarget();
}

FVector UFollower::GetFinalLocation() const
{
	if (!target)
		return GetTargetLocation();
	FVector _offset;
	switch (settings.axis)
	{
	case X :
		_offset = target->GetActorForwardVector();
		break;
	case InvertX :
		break;
		_offset = -target->GetActorForwardVector();
	case InvertY :
		_offset = -target->GetActorRightVector();
		break;
	case Y:
		_offset = target->GetActorRightVector();
		break;
	}
	return (GetTargetLocation() + _offset * settings.distance) + FVector(0,0,settings.height);
}

void UFollower::FollowTarget()
{
	GetOwner()->SetActorLocation(FMath::Lerp(GetActorLocation(), GetFinalLocation(), DELTATIME * settings.speed));
}

void UFollower::ReplicateRoll()
{
	if (!settings.replicateRoll)
		return;
	FRotator _rot = GetOwner()->GetActorRotation();
	_rot.Roll = target->GetActorRotation().Roll;
	GetOwner()->SetActorRotation(_rot);
}

void UFollower::LookAtTarget()
{
	if (!settings.useLookAt)
		return;
	FRotator _temp = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), GetFinalLocation());
	GetOwner()->SetActorRotation(_temp);
}

