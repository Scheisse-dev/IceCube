#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>
#include <GameFramework/FloatingPawnMovement.h>
#include "PawnCorr.generated.h"

USTRUCT()
struct FShipControlsSettings
{
	GENERATED_BODY()


		UPROPERTY(EditAnywhere, meta = (UIMin = 0, ClamMin = 0))
		float forwardWeight = 1;
		UPROPERTY(EditAnywhere, meta = (UIMin = 0, ClamMin = 0))
			float rollWeight = 1;
		UPROPERTY(EditAnywhere, meta = (UIMin = 0, ClamMin = 0))
			float yawWeight = 1;
		UPROPERTY(EditAnywhere, meta = (UIMin = -65, ClamMin = -65, UIMax = 65, ClamMax = 65))
			float maxAngle = 60;

		float forwardAxis, rollAxis, yawAxis;
};


UCLASS()
class ICECUBEPROJECTCORR_API APawnCorr : public APawn
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


	FShipControlsSettings settings;
public:
	APawnCorr();

private:	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveFoward(float _axis);
	void Yaw(float _axis);
	void RollMovement(float _axis);

};
