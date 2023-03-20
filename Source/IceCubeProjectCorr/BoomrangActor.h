// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoomrangActor.generated.h"

UCLASS()
class ICECUBEPROJECTCORR_API ABoomrangActor : public AActor
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;
public:	
	ABoomrangActor();
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void Rotate();
	void LocationSwitch();
};
