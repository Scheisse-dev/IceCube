#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Grid.h"
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>
#include "GridPawn.generated.h"

UCLASS()
class ICECUBEPROJECTCORR_API AGridPawn : public APawn
{



	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UCameraComponent> camera = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<USpringArmComponent> spring = nullptr;
	UPROPERTY(VisibleAnywhere)
		TObjectPtr<AGrid> grid = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
		bool testMod = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
		float timerGap = 1.5f;



	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	float timer;


	bool startTimer = false;
	float timerLoop = 0;
	float moveNumber = 0;
	TArray<float> randomList;
public:
	AGridPawn();
private:
	void InitPawn();
	TObjectPtr<AGrid> GetGrid() const;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void UpMove();
	void DownMove();
	void LeftMove();
	void RightMove();
	void SelectGridCell();
	void SetRandom();
	void Timer(); 
	void AutoPlay();
	void ResetTimer();
};
