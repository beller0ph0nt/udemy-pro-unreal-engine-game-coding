#include "PlayerBallBearing.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

static void InitializedDefaultPawnInputBindings()
{
    static bool bindingsAdded = false;

    if (bindingsAdded == false) {
        bindingsAdded = true;

        UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping(
            "BallBearing_MoveLongitudinally", EKeys::W, 1.0f));
        UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping(
            "BallBearing_MoveLongitudinally", EKeys::S, -1.0f));
        UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping(
            "BallBearing_MoveLongitudinally", EKeys::Up, 1.0f));
        UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping(
            "BallBearing_MoveLongitudinally", EKeys::Down, -1.0f));
        UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping(
            "BallBearing_MoveLongitudinally", EKeys::Gamepad_LeftY, 1.0f));

        UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping(
            "BallBearing_MoveLaterally", EKeys::A, -1.0f));
        UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping(
            "BallBearing_MoveLaterally", EKeys::D, 1.0f));
        UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping(
            "BallBearing_MoveLaterally", EKeys::Left, -1.0f));
        UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping(
            "BallBearing_MoveLaterally", EKeys::Right, 1.0f));
        UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping(
            "BallBearing_MoveLaterally", EKeys::Gamepad_LeftX, 1.0f));

        UPlayerInput::AddEngineDefinedActionMapping(
            FInputActionKeyMapping("BallBearing_Jump", EKeys::Enter));
        UPlayerInput::AddEngineDefinedActionMapping(
            FInputActionKeyMapping("BallBearing_Dash", EKeys::SpaceBar));
    }
}

APlayerBallBearing::APlayerBallBearing()
{
    SpringArm
        = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->bDoCollisionTest = false;
    SpringArm->SetUsingAbsoluteRotation(true);
    SpringArm->SetRelativeRotation(FRotator(-45.0, 0.0, 0.0));
    SpringArm->TargetArmLength = 1000.0f;
    SpringArm->bEnableCameraLag = false;
    SpringArm->CameraLagSpeed = 5.0f;
    SpringArm->SetupAttachment(BallMesh);

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->bUsePawnControlRotation = false;
    Camera->SetupAttachment(SpringArm);

    Magnitized = false;
}

void APlayerBallBearing::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    const FVector Direction(InputLongitude, InputLatitude, 0.0);
    const float Mass = BallMesh->GetMass();
    BallMesh->AddForce(Direction * ControllerForce * Mass);
}

void APlayerBallBearing::SetupPlayerInputComponent(
    UInputComponent* PlayerInputComponent)
{
    check(PlayerInputComponent != nullptr);
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    InitializedDefaultPawnInputBindings();

    PlayerInputComponent->BindAxis("BallBearing_MoveLongitudinally", this,
        &ThisClass::MoveLongitudinally);
    PlayerInputComponent->BindAxis(
        "BallBearing_MoveLaterally", this, &ThisClass::MoveLaterally);

    PlayerInputComponent->BindAction(
        "BallBearing_Jump", EInputEvent::IE_Pressed, this, &ThisClass::Jump);
    PlayerInputComponent->BindAction(
        "BallBearing_Dash", EInputEvent::IE_Pressed, this, &ThisClass::Dash);
}

void APlayerBallBearing::MoveLongitudinally(float DeviceDependentAxisValue)
{
    InputLongitude = DeviceDependentAxisValue;
}

void APlayerBallBearing::MoveLaterally(float DeviceDependentAxisValue)
{
    InputLatitude = DeviceDependentAxisValue;
}

void APlayerBallBearing::Jump() { }

void APlayerBallBearing::Dash() { }