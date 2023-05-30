
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Header.h"
#include "MainCharacter.generated.h"


class USpringArmComponent;
class UCameraComponent;
class UAnimMontage;
UCLASS()
class SOULSLIKE_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	AMainCharacter();
	virtual void Tick(float DeltaTime) override;

	int32 Number;
	bool Checker;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE ECharacterPose GetCharacterState() { return CharacterPose; }

	UPROPERTY(EditDefaultsOnly)
		UAnimMontage* WeaponStateMontage;
	UPROPERTY(EditDefaultsOnly)
		UAnimMontage* JumpMontage;

	ECharacterPose CharacterPose = ECharacterPose::ECP_Idle;

protected:

	virtual void BeginPlay() override;

	void MoveForward(float Value);
	void Right(float Value);
	void LookUp(float Value);
	void Rotate(float Value);
	void Sprint();
	void StopSprint();
	void CrouchPressed();
	void CrouchUnpressed();
	void Equip();
	void Unequip();
	void EquipUnequipMontage(int32 Value);




private:

	UPROPERTY(VisibleAnywhere)
		USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
		UCameraComponent* Camera;


};
