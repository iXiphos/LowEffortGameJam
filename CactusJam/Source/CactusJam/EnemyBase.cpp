// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"

// Sets default values
AEnemyBase::AEnemyBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector loc = GetActorTransform().GetLocation();

	FVector playerLoc = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

	loc.SetComponentForAxis(EAxis::Z, 0.0f);
	playerLoc.SetComponentForAxis(EAxis::Z, 0.0f);


	FVector dir = playerLoc - loc;
	dir.Normalize();

	SetActorLocation(GetActorTransform().GetLocation() + dir * mSpeed);
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Tick...");
	

}

