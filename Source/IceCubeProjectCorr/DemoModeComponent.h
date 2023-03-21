#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DemoModeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ICECUBEPROJECTCORR_API UDemoModeComponent : public UActorComponent
{
	GENERATED_BODY()
		DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDemoAction);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDemoStart);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDemoStop);

		FTimerHandle demoTimer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess, UIMin = 0, ClampMin = 0))
		float demoRate = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess, UIMin = 0, ClampMin = 0, UIMax = 100, ClampMax = 100))
		float demoCallPlayerRange = 80;
	UPROPERTY(BlueprintAssignable, BlueprintCallable, meta = (AllowPrivateAccess))
		FOnDemoAction onDemoAction;
	UPROPERTY(BlueprintAssignable, BlueprintCallable, meta = (AllowPrivateAccess))
	FOnDemoStart onDemoStart;
	UPROPERTY(BlueprintAssignable, BlueprintCallable, meta = (AllowPrivateAccess))
	FOnDemoStop onDemoStop;
public:	
	UDemoModeComponent();
	FORCEINLINE FOnDemoAction& OnDemoAction() { return onDemoAction; }
	FORCEINLINE FOnDemoStart& OnDemoStart() { return onDemoStart; }
	FORCEINLINE FOnDemoStop& OnDemoStop() { return onDemoStop; }
	UFUNCTION(BlueprintCallable) void StartDemo(float _delay);
	void DemoAction();
	UFUNCTION(BlueprintCallable) void RunDemo();
	void StopDemo();
private:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
};
