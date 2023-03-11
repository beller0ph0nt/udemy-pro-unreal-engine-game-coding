#pragma once

#include "CoreMinimal.h"
#include "DebugHUD.h"

#include "BallBearingHUD.generated.h"

UCLASS()

class ABallBearingHUD : public ADebugHUD {
    GENERATED_BODY()

protected:
    virtual void DrawHUD() override;
};
