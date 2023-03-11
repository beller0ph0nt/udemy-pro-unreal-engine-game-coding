#include "DebugHUD.h"

#include "CanvasItem.h"
#include "Engine/Canvas.h"

ADebugHUD::ADebugHUD()
{
    // TODO: Move hardcoded resource path into ini config
    static ConstructorHelpers::FObjectFinder<UFont> Font(
        TEXT("/Engine/EngineFonts/Roboto"));

    MainFont = Font.Object;
}

void ADebugHUD::AddText(const TCHAR* Title, const FText& Value)
{
    RenderStatistics(Title, Value);
}

void ADebugHUD::AddFloat(const TCHAR* Title, float Value)
{
    RenderStatistics(Title, FText::AsNumber(Value));
}

void ADebugHUD::AddInt(const TCHAR* Title, int32 Value)
{
    RenderStatistics(Title, FText::AsNumber(Value));
}

void ADebugHUD::AddBool(const TCHAR* Title, bool Value)
{
    RenderStatistics(Title, BoolToText(Value),
        Value ? FLinearColor::Green : FLinearColor::Red);
}

void ADebugHUD::DrawHUD() { X = Y = 50.0f; }

void ADebugHUD::RenderStatistics(
    const TCHAR* Title, const FText& Text, const FLinearColor& Color)
{
    FCanvasTextItem Item0(FVector2D(X, Y), CStringToText(Title), MainFont,
        FLinearColor::White);
    Item0.EnableShadow(FLinearColor(0.0f, 0.0f, 0.0f));
    Canvas->DrawItem(Item0);

    FCanvasTextItem Item1(
        FVector2D(X + HorizontalOffset, Y), Text, MainFont, Color);
    Item1.EnableShadow(FLinearColor(0.0f, 0.0f, 0.0f));
    Canvas->DrawItem(Item1);

    Y += LineHeight;
}

FText ADebugHUD::CStringToText(const TCHAR* Text) const
{
    return FText::FromString(Text);
}

FText ADebugHUD::BoolToText(bool Value) const
{
    return CStringToText((Value ? TEXT("true") : TEXT("false")));
}
