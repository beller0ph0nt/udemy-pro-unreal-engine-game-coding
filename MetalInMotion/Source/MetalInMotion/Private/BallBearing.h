#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "BallBearing.generated.h"

class UStaticMeshComponent;

UCLASS()

class ABallBearing : public APawn {
    GENERATED_BODY()

public:
    ABallBearing();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* BallMesh = nullptr;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BallBearing")
    float Magnitized = true;

    friend class ABallBearingHUD;
};
