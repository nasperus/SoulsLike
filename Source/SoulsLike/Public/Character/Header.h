#pragma once

UENUM(BlueprintType)
enum class ECharacterPose :uint8
{
	ECP_Unequip UMETA(DisplayName = "Unequip"),
	ECP_Equip UMETA(DisplayName = "Equip"),
	ECP_Idle UMETA(DisplayName = "Idle"),
	ECP_EquipSprint UMETA(DisplayName = "Equip Sprint"),
	ECP_UnequipSprint UMETA(DisplayName = "Unequip Sprint"),
	ECP_EquipWalk UMETA(DisplayName = "Equip Walk"),
	ECP_UnequipWalk UMETA(DisplayName = "UnequipWalk"),
	ECP_EquipJump UMETA(DisplayName = "Equip Jump"),
	ECP_EquipFall UMETA(DisplayName = "Equip Fall"),
	ECP_NormalJump UMETA(DisplayName = "Normal Jump"),
	ECP_NormalFall UMETA(DisplayName = "Normal Fall")
};