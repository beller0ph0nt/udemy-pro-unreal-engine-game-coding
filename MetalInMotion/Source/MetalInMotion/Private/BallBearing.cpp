#include "BallBearing.h"

#include "Components/StaticMeshComponent.h"

ABallBearing::ABallBearing()
{
	PrimaryActorTick.bCanEverTick = true;

	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
	BallMesh->SetSimulatePhysics(true);
	SetRootComponent(BallMesh);
}

void ABallBearing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABallBearing::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ABallBearing::BeginPlay()
{
	Super::BeginPlay();	
}
