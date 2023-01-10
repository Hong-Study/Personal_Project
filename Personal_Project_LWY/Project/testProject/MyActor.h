// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class TESTPROJ_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();
	bool bPressedKey;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitProperties() override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = "Move")
		void InputSpaceKey(bool Pressed);
	UFUNCTION(BlueprintCallable, Category = "Move")
		void MoveUp(float DeltaTime);
};
