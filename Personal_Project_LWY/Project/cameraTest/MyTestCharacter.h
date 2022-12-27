// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyCharacter.h"
#include "MyTestCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TESTPROJECT_API AMyTestCharacter : public AMyCharacter
{
	GENERATED_BODY()
	
public:
	AMyTestCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class UCameraComponent* FollowCamera;
};
