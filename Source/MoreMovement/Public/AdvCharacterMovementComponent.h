#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AdvCharacterMovementComponent.generated.h"

UENUM(BlueprintType)
enum ECustomMovementMode
{
	CUSTOM_Sprint    UMETA(DisplayName = "Sprint")
};

/**
 * Custom movement component that includes additional functionality like sprinting
 */
UCLASS()
class MOREMOVEMENT_API UAdvCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:

	/** Returns whether the character is in the sprinting state */
	UFUNCTION(BlueprintCallable)
	bool IsSprinting() const;

	UFUNCTION(BlueprintCallable)
	void Sprint();

	UFUNCTION(BlueprintCallable)
	void StopSprint();

	virtual float GetMaxSpeed() const override;

	/** The maximum ground speed when walking. Also determines maximum lateral speed when falling. */
	UPROPERTY(Category="Character Movement: Walking", EditAnywhere, BlueprintReadWrite, meta=(ClampMin="0", UIMin="0"))
	float MaxSprintSpeed;

	/** Multiplier for the players max speed */
	UPROPERTY(Category="Character Movement: Walking", EditAnywhere, BlueprintReadWrite, meta=(ClampMin="0", UIMin="0"))
	float SpeedMultiplier = 1.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bWantsToSprint = false;
};

