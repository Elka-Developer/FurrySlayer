// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
//#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	max_electricy = 100.0f;
	max_health = 100.0f;
	electricy = max_electricy;
	health = max_health;


}

//electricy manipulations
float AMainCharacter::GetElectricyProcent()
{
	return max_electricy / 100 * electricy;
}

float AMainCharacter::GetElectricyPower()
{
	return electricy;
}

void AMainCharacter::AddElectricyPower(float add_electricy)
{
	electricy += add_electricy;
}

void AMainCharacter::DecreaseElectricyPower(float decrease_electricy)
{
	electricy -= decrease_electricy;
}

void AMainCharacter::SetMaxElectricyPower(float new_max_electricy)
{
	max_electricy = new_max_electricy;
}

float AMainCharacter::GetMaxElectricyPower()
{
	return max_electricy;
}

//health manipulations
float AMainCharacter::GetHealthProcent()
{
	return max_health / 100 * health;
}

float AMainCharacter::GetHealth()
{
	return health;
}

void AMainCharacter::AddHealth(float add_health)
{
	health += add_health;
}

void AMainCharacter::DecreaseHealth(float decrease_health)
{
	health -= decrease_health;
}

bool AMainCharacter::CheckDeath() 
{
	if (health <= 0) 
	{
		is_death = true;

		//GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		UGameplayStatics::SpawnSoundAtLocation(this, death_sound, GetActorLocation());
	}
	else 
	{
		is_death = false;
	}

	return is_death;
}

