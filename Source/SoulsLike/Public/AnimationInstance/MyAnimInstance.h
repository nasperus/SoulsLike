// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Character/Header.h"
#include "MyAnimInstance.generated.h"

/**
 *
 */
UCLASS()
class SOULSLIKE_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	void NativeInitializeAnimation() override;
	void NativeUpdateAnimation(float DeltaTime) override;


	UPROPERTY(BlueprintReadOnly)
		bool Falling;

	UPROPERTY(BlueprintReadOnly)
		bool Crouch;

	UPROPERTY(BlueprintReadOnly)
		class AMainCharacter* MainCharacter;

	UPROPERTY(BlueprintReadOnly)
		class UCharacterMovementComponent* MainCharacterMovement;
	UPROPERTY(BlueprintReadOnly)
		float GroundSpeed;

	UPROPERTY(BlueprintReadOnly)
		ECharacterPose CharacterPose;

};
