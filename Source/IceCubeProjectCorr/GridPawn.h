#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Grid.h"
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>
#include "DemoModeComponent.h"
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
	UPROPERTY(EditAnywhere)
	TObjectPtr<UDemoModeComponent> demo = nullptr;

	UPROPERTY(EditAnywhere)
		bool useDemoMode = false;

public:
	AGridPawn();
private:
	void InitPawn();
	TObjectPtr<AGrid> GetGrid() const;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
public:
	UFUNCTION(BlueprintCallable) void UpMove();
	UFUNCTION(BlueprintCallable) void DownMove();
	UFUNCTION(BlueprintCallable) void LeftMove();
	UFUNCTION(BlueprintCallable) void RightMove();
	UFUNCTION(BlueprintCallable) void SelectGridCell();

};
