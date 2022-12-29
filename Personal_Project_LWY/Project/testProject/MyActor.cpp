// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Log, TEXT("Construct"));
	
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("Begin Play"));
}

void AMyActor::PostInitProperties()
{
	Super::PostInitProperties();
}

void AMyActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{

	Super::PostEditChangeProperty(PropertyChangedEvent);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Log, TEXT("Tick"));
}

void AMyActor::InputSpaceKey(bool Pressed)
{
	bPressedKey = Pressed;
}

void AMyActor::MoveUp(float DeltaTime)
{
	if (bPressedKey) {
		FVector Location = GetActorLocation();
		Location += FVector::UpVector * 980.0f * DeltaTime;
		SetActorLocation(Location);
	}
	
}
