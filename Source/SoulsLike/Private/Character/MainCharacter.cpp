

#include "Character/MainCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Animation/AnimMontage.h"
#include "Components/BoxComponent.h"

AMainCharacter::AMainCharacter()
{

	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0, 400, 0);
	GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;

	GetCharacterMovement()->SetJumpAllowed(true);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 400.f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetCharacterMovement()->MaxWalkSpeed = 250.f;
	Number = 0;
	Checker = true;

}


void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AMainCharacter::MoveForward(float Value)
{

	if (Controller)
	{

		const FRotator Controler = GetControlRotation();
		const FRotator YawRotation(0.f, Controler.Yaw, 0.f);
		FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);


	}

}




void AMainCharacter::Right(float Value)
{
	if (Controller)
	{

		const FRotator Controler = GetControlRotation();
		const FRotator YawRotation(0.f, Controler.Yaw, 0.f);
		FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}

}

void AMainCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}


void AMainCharacter::Rotate(float Value)
{
	AddControllerYawInput(Value);
}

void AMainCharacter::Sprint()
{


	if (CharacterPose == ECharacterPose::ECP_Equip)
	{
		CharacterPose = ECharacterPose::ECP_EquipSprint;
	}

	if (CharacterPose == ECharacterPose::ECP_Unequip)
	{
		CharacterPose = ECharacterPose::ECP_UnequipSprint;
	}

	GetCharacterMovement()->MaxWalkSpeed = 600.f;

}

void AMainCharacter::StopSprint()
{


	GetCharacterMovement()->MaxWalkSpeed = 250.f;



}

void AMainCharacter::CrouchPressed()
{

	GetCharacterMovement()->MaxWalkSpeedCrouched = 200.f;
	Crouch();

}

void AMainCharacter::CrouchUnpressed()
{

	GetCharacterMovement()->MaxWalkSpeed = 250.f;
	UnCrouch();
}

void AMainCharacter::Equip()
{
	if (Checker)
	{
		CharacterPose = ECharacterPose::ECP_Equip;
		Number = 1;
		EquipUnequipMontage(Number);
		Checker = false;

	}




}

void AMainCharacter::Unequip()
{
	if (!Checker)
	{
		CharacterPose = ECharacterPose::ECP_Unequip;
		Number = 2;
		EquipUnequipMontage(Number);
		Checker = true;
	}


}

void AMainCharacter::EquipUnequipMontage(int32 Value)
{
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();

	if (AnimInstance && WeaponStateMontage)
	{
		AnimInstance->Montage_Play(WeaponStateMontage);
		FName SectionName = FName();

		switch (Value)
		{
		case 1:
			SectionName = FName("Equip");
			CharacterPose = ECharacterPose::ECP_Equip;
			break;

		case 2:
			SectionName = FName("Unequip");
			break;
			CharacterPose = ECharacterPose::ECP_Idle;

		default:
			break;
		}

		AnimInstance->Montage_JumpToSection(SectionName, WeaponStateMontage);
	}

}







void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &AMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis(FName("Right"), this, &AMainCharacter::Right);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &AMainCharacter::LookUp);
	PlayerInputComponent->BindAxis(FName("Rotate"), this, &AMainCharacter::Rotate);

	PlayerInputComponent->BindAction(FName("Jump"), IE_Pressed, this, &AMainCharacter::Jump);

	PlayerInputComponent->BindAction(FName("Sprint"), IE_Pressed, this, &AMainCharacter::Sprint);
	PlayerInputComponent->BindAction(FName("Sprint"), IE_Released, this, &AMainCharacter::StopSprint);

	PlayerInputComponent->BindAction(FName("CrouchKey"), IE_Pressed, this, &AMainCharacter::CrouchPressed);
	PlayerInputComponent->BindAction(FName("CrouchKey"), IE_Released, this, &AMainCharacter::CrouchUnpressed);


	PlayerInputComponent->BindAction(FName("Equip"), IE_Pressed, this, &AMainCharacter::Equip);


	PlayerInputComponent->BindAction(FName("Unequip"), IE_Pressed, this, &AMainCharacter::Unequip);


}

