// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com


// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUpBanana.h"

// Sets default values
APowerUpBanana::APowerUpBanana()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//OnActorHit.AddDynamic(this, &ABaseProjectile::OnHitActor);

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = BoxComponent;

	// Initialise all Components
	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));

	CollisionSphere->SetupAttachment(RootComponent);
	MeshComponent->SetupAttachment(RootComponent);

	CollisionSphere->BodyInstance.SetCollisionProfileName("BananaCollider");
	
}

// Called when the game starts or when spawned
void APowerUpBanana::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &APowerUpBanana::OnHit);

	//CollisionSphere->AttachToComponent(BoxComponent, FAttachmentTransformRules::KeepRelativeTransform);
	//MeshComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

}

// Called every frame
void APowerUpBanana::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APowerUpBanana::OnHit(AActor* MyOverlappedActor, AActor* OtherActor) {

	//if (GEngine)
	//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Black, FString::Printf(TEXT("FUCK")));

	// Destroy Banana
	Destroy();
}
 

