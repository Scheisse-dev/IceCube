#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Follower.generated.h"

UENUM()
enum EFollowAxis
{
	X,
	InvertX,
	Y,
	InvertY
};


USTRUCT()
struct FFollowSettings
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		TEnumAsByte<EFollowAxis> axis;

	UPROPERTY(EditAnywhere, meta = (UIMin = 0, ClampMin = 0))
		float speed = .5f;
	UPROPERTY(EditAnywhere, meta = (UIMin = 0, ClampMin = 0))
		float height = 20;
	UPROPERTY(EditAnywhere, meta = (UIMin = 0, ClampMin = 0))
		float distance = 150;
	UPROPERTY(EditAnywhere)
		bool replicateRoll = true;
	UPROPERTY(EditAnywhere)
		bool useLookAt = true;

};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ICECUBEPROJECTCORR_API UFollower : public UActorComponent
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		TObjectPtr<AActor> target = nullptr;

	UPROPERTY(EditAnywhere)
	FFollowSettings settings;

public:	
	UFollower();
	FORCEINLINE void SetTarget(TObjectPtr<AActor> _target) { target = _target; }
	FORCEINLINE FVector GetTargetLocation() const {
		return target ? target->GetActorLocation() : FVector(0);
	}
	FORCEINLINE FVector GetActorLocation() const {
		return GetOwner()->GetActorLocation();
	}
protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	FVector GetFinalLocation() const;
	void FollowTarget();
	void ReplicateRoll();
	void LookAtTarget();
};
