#pragma once

#include "BallBearing.h"
#include "CoreMinimal.h"

#include "PlayerBallBearing.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()

class APlayerBallBearing : public ABallBearing {
    GENERATED_BODY()

public:
    APlayerBallBearing();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    USpringArmComponent* SpringArm = nullptr;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UCameraComponent* Camera = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BallBearing")
    float ControllerForce = 250.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BallBearing")
    float JumpForce = 50.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BallBearing")
    float DashForce = 150.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BallBearing")
    float MaximumSpeed = 4.0f;

protected:
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(
        class UInputComponent* PlayerInputComponent) override;

private:
    void MoveLongitudinally(float DeviceDependentAxisValue);
    void MoveLaterally(float DeviceDependentAxisValue);
    void Jump();
    void Dash();

    float InputLongitude = 0.0f;
    float InputLatitude = 0.0f;
    float DashTimer = 0.0f;
};
