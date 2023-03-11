#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "DebugHUD.generated.h"

UCLASS()

class ADebugHUD : public AHUD {
    GENERATED_BODY()
protected:
    ADebugHUD();

    void AddText(const TCHAR* Title, const FText& Value);
    void AddFloat(const TCHAR* Title, float Value);
    void AddInt(const TCHAR* Title, int32 Value);
    void AddBool(const TCHAR* Title, bool Value);

    virtual void DrawHUD() override;

    float HorizontalOffset = 150.0f;

private:
    void RenderStatistics(const TCHAR* Title, const FText& Text,
        const FLinearColor& Color = FLinearColor::White);

    FText CStringToText(const TCHAR* Text) const;
    FText BoolToText(bool Value) const;

    UPROPERTY()
    UFont* MainFont;

    float X = 50.0f;
    float Y = 50.0f;
    float LineHeight = 16.0f;
};
