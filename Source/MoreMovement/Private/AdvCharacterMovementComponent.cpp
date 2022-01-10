#include "AdvCharacterMovementComponent.h"

bool UAdvCharacterMovementComponent::IsSprinting() const
{
	return bWantsToSprint && IsWalking() && !IsCrouching();
}

void UAdvCharacterMovementComponent::Sprint()
{
	bWantsToSprint = true;
}

void UAdvCharacterMovementComponent::StopSprint()
{
	bWantsToSprint = false;
}

float UAdvCharacterMovementComponent::GetMaxSpeed() const
{
	float MaxSpeed = Super::GetMaxSpeed();
	MaxSpeed = IsSprinting() ? MaxSprintSpeed : MaxSpeed;

	return MaxSpeed * SpeedMultiplier;
}

