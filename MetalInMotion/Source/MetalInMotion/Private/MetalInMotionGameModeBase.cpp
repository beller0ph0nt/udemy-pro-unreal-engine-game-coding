#include "MetalInMotionGameModeBase.h"

#include "BallBearingHUD.h"

AMetalInMotionGameModeBase::AMetalInMotionGameModeBase()
{
    PrimaryActorTick.bCanEverTick = true;

    HUDClass = ABallBearingHUD::StaticClass();
}
