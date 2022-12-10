#include "BallBearing.h"

#include "Components/StaticMeshComponent.h"

ABallBearing::ABallBearing()
{
    PrimaryActorTick.bCanEverTick = true;

    BallMesh
        = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
    BallMesh->SetSimulatePhysics(true);
    SetRootComponent(BallMesh);
}
