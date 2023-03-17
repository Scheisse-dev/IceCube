#include "Bud.h"


UBud::UBud()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UBud::MoveBud()
{
	targetPosition =  PAWN->GetActorLocation() + PAWN->GetActorUpVector() * 50;
}

void UBud::LookAt()
{
	FRotator _rotate = UKismetMathLibrary::FindLookAtRotation(GetOwner()->GetActorLocation(), targetPosition);
	GetOwner()->SetActorRotation(_rotate);
}

void UBud::BeginPlay()
{
	Super::BeginPlay();
	targetPosition = PAWN->GetActorLocation() + PAWN->GetActorUpVector() * 50;
}

void UBud::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//GetOwner()->GetWorld()->GetFirstPlayerController()->InputComponent->BindAction("Call", EInputEvent::IE_Pressed, this, &UBud::MoveBud);
	GetOwner()->GetWorld()->GetFirstPlayerController()->InputComponent->BindAction("Call", EInputEvent::IE_Pressed, this, &UBud::MoveBud);
	GetOwner()->SetActorLocation(LERP(GetOwner()->GetActorLocation(), targetPosition, DELTATIME));
	LookAt();
}

