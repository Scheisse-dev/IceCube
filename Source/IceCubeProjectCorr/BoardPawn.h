// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <Camera/CameraComponent.h>
#include <GameFramework/SpringArmComponent.h>
#include <GameFramework/FloatingPawnMovement.h>
#include "BoardSettings.h"
#include "BoardPawn.generated.h"




UCLASS()
class ICECUBEPROJECTCORR_API ABoardPawn : public APawn
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UCameraComponent> camera = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<USpringArmComponent> springArm = nullptr;

	UPROPERTY(EditAnywhere)
		TObjectPtr<UFloatingPawnMovement> movement = nullptr;
	UPROPERTY(EditAnywhere)
		float maxTimer = 0.5;


	FVector initialLocation;
	float timer = 0;
	bool canMove = false;

	FBoardParams settings;

	//Get gab + numer -> get max size 
public:
	ABoardPawn();
private:	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveForward(float _axis);
	void MoveRight(float _axis);
	void UpdateTimer(); 

};
