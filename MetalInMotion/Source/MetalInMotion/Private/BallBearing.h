#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "BallBearing.generated.h"

class UStaticMeshComponent;

UCLASS()
class ABallBearing : public APawn
{
	GENERATED_BODY()

public:
	ABallBearing();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = BallBearing)
	UStaticMeshComponent* BallMesh;

protected:
	virtual void BeginPlay() override;
};
