#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>
#include <GameFramework/FloatingPawnMovement.h>
#include "Utils.h"
#include "spaceship.generated.h"

USTRUCT()
struct FSpaceMovement
{
	GENERATED_BODY()


public:
	UPROPERTY(EditAnywhere)
		float forwardWeight = 10;
	UPROPERTY(EditAnywhere)
		float rotate = 10;
	UPROPERTY(EditAnywhere)
		float speed = 10;


};

UCLASS()
class ICECUBEPROJECTCORR_API Aspaceship : public APawn
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
			TObjectPtr<UStaticMeshComponent> mesh = nullptr;
		UPROPERTY(EditAnywhere)
			TObjectPtr<USpringArmComponent> springArm = nullptr;
		UPROPERTY(EditAnywhere)
			TObjectPtr<UCameraComponent> camera = nullptr;
		UPROPERTY(EditAnywhere)
			TObjectPtr<UFloatingPawnMovement> movement = nullptr;


		UPROPERTY(EditAnywhere, category = Weight)
			float fwdWeight = 1;
		UPROPERTY(EditAnywhere, category = Weight)
			float rotateWeight = 1;
		UPROPERTY(EditAnywhere, category = Weight)
			float pitchWeight = 1;
		UPROPERTY(EditAnywhere)
			float bankAngle = 45;

		FVector shipVelocity;
		float forwardVelocity,
			rotateAxis,
			pitchAxis;
		FSpaceMovement settings;
		float maxPitchAngle = 45;

public:
	Aspaceship();
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveForward(float _axis);
	void Rotate(float _axis);
};
