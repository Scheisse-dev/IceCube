#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BPLink.generated.h"

UCLASS()
class ICECUBEPROJECTCORR_API ABPLink : public AActor
{
	GENERATED_BODY()
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTest);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTestPram, float, _value);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
		float life = 0;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, meta = (AllowPrivateAccess))
	FOnTest onTest;
	UPROPERTY(BlueprintAssignable, BlueprintCallable, meta = (AllowPrivateAccess))
	FOnTestPram onTestParam;
public:	
	ABPLink();
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable) void Test();
	UFUNCTION(BlueprintCallable) void TestParam(float _value);
};
