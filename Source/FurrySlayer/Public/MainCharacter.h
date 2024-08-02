// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

UCLASS()
class FURRYSLAYER_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	AMainCharacter();

	//electricy manipulations
	float GetElectricyProcent();
	float GetElectricyPower();
	void AddElectricyPower(float add_electricy);
	void DecreaseElectricyPower(float decrease_electricy);
	void SetMaxElectricyPower(float new_max_electricy);
	float GetMaxElectricyPower();

	//health manipulations
	float GetHealthProcent();
	float GetHealth();
	void AddHealth(float add_health);
	void DecreaseHealth(float decrease_health);
	bool CheckDeath();

private:

	//electricy variables
	float electricy;
	UPROPERTY(EditDefaultsOnly, Category = "Electricy")
	float max_electricy;
	UPROPERTY(EditDefaultsOnly, Category = "Electricy")
	float warning_electricy_procent = 10.0f;
	//USoundBase* electycy_warning_sound;

	//health variables
	float health;
	UPROPERTY(EditDefaultsOnly, Category = "Health")
	float max_health;
	bool is_death;
	UPROPERTY(EditDefaultsOnly, Category = "Health")
	USoundBase* death_sound;

	//UAnimMontage* death;
};
