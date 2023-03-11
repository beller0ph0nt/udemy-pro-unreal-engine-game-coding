#include "BallBearingHUD.h"

#include "PlayerBallBearing.h"

void ABallBearingHUD::DrawHUD()
{
    Super::DrawHUD();

    APlayerBallBearing* BallBearing
        = Cast<APlayerBallBearing>(GetOwningPawn());
    if (BallBearing)
    {
        const float MetersInCentimeter = 1 / 100.0f;
        AddFloat(L"Speed", BallBearing->GetVelocity().Size() * MetersInCentimeter);
        AddFloat(L"Dash timer", BallBearing->DashTimer);
        AddFloat(L"Input latitude", BallBearing->InputLatitude);
        AddFloat(L"Input longitude", BallBearing->InputLongitude);
    }
}
