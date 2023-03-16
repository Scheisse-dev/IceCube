#pragma once


#include <Kismet/KismetMathLibrary.h>

#define LOG(cat, msg, ...) UE_LOG(cat, Display, TEXT(msg), __VA_ARGS__);

#define LOG_W(cat ,msg, ...) UE_LOG(cat, Warning, TEXT(msg), __VA_ARGS__);

#define LOG_E(cat, msg, ...) UE_LOG(cat, Error, TEXT(msg), __VA_ARGS__);

//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString::Printf(TEXT("%s %s %s"), *originLocation.ToString(), *GetActorLocation().ToString(), *GetName()));


#define WORLD GetWorld()
#define DELTATIME WORLD->DeltaTimeSeconds

#define USE_DEBUG 1



#define DRAW_SPHERE( from, radius, color, size )\
	if (USE_DEBUG) DrawDebugSphere(WORLD, from , radius, 20 , color, false, -1, 0, size);

#define DRAW_SPHERE_DEF( from, radius, def, color, size )\
	if (USE_DEBUG) DrawDebugSphere(WORLD, from , radius, def , color, false, -1, 0, size);

#define DRAW_BOX( from, extents, color, size)\
	if (USE_DEBUG) DrawDebugBox(WORLD, from, extents, color, false, -1, 0, size);

#define DRAW_LINE( from, to, color, size )\
	if (USE_DEBUG) DrawDebugLine(WORLD, from , to, color, false, -1, 0, size);

#define DRAW_TEXT( from, text, color, size )\
 if (USE_DEBUG) DrawDebugString(WORLD, from , text, nullptr, color, DELTATIME, false, size);


#define LOG_SCREEN(time, color, msg, ...) GEngine->AddOnScreenDebugMessage(-1, time, color, FString::Printf(TEXT(msg), __VA_ARGS__));

//GetFirstPlayerController()->InputComponent->BindAxis("Horizontal", this, &AInputActor::SetHorizonal)

//#define LOG_SCREEN(...) GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, FString::Printf(__VA_AGRS__));
#define LERP_COLOR(from, to, t) UKismetMathLibrary::LinearColorLerp(from.ReinterpretAsLinear(), to.ReinterpretAsLinear(), t).ToFColor(true);

#define COLOR(c) FColor::c; 

#define BIND_AXIS(name, owner, methods) WORLD->GetFirstPlayerController()->InputComponent->BindAxis(name, owner, methods);

#define BIND_ACTION(name, eventType, owner, methods) WORLD->GetFirstPlayerController()->InputComponent->BindAction(name,eventType, owner, methods); 

#define Bind_Action_Params(del, name, eventType, owner, methods, ...)\
	GetWorld()->GetFirstPlayerController()->InputComponent->BindAction<del>(name, eventType, owner, methods, __VA_AGRS__);

#define INVOKE(action) action.Broadcast()

//#define BIND();


#define RESET "Reset"
#define HORIZONTAL "Horizontal"
#define VERTICAL "Vertical"
#define ROTATE "Rotate"
#define SIZE "Size"
#define RESPAWN "Respawn"
#define INTERACT "Interact"
#define ACTORSCALE GetActorScale()

#define PAWN GetWorld()->GetFirstPlayerController()->GetPawn()
#define LERP(value, targetValue, t) FMath::Lerp(value, targetValue, t)
//#define TO_CHAR(string) *string
//#define TO_STRING(notString) notStyring.ToString()
//#define TO_CHAR_STR(text) TO_CHAR(TO_STRING(text))