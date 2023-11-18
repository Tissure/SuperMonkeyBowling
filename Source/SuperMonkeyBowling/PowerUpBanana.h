// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include <Components/BoxComponent.h>
#include "PowerUpBanana.generated.h"


UCLASS()
class SUPERMONKEYBOWLING_API APowerUpBanana : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APowerUpBanana();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = BoxComponent);
	UBoxComponent* BoxComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = MeshComponent);
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = CollisionSphere);
	USphereComponent* CollisionSphere;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnHit(AActor* MyOverlappedActor, AActor* OtherActor);
};
