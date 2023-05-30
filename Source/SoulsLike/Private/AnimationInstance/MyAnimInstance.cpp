


#include "AnimationInstance/MyAnimInstance.h"
#include "Character/MainCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Character/MainCharacter.h"
#include "Kismet/KismetMathLibrary.h"

void UMyAnimInstance::NativeInitializeAnimation()
{
	MainCharacter = Cast<AMainCharacter>(TryGetPawnOwner());

	if (MainCharacter)
	{
		MainCharacterMovement = MainCharacter->GetCharacterMovement();
	}
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaTime)
{


	if (MainCharacterMovement)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(MainCharacterMovement->Velocity);


		Falling = MainCharacterMovement->IsFalling();
		Crouch = MainCharacterMovement->IsCrouching();
		CharacterPose = MainCharacter->GetCharacterState();



	}
}
