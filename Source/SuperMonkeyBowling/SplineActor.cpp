// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

// Fill out your copyright notice in the Description page of Project Settings.


#include "SplineActor.h"


// Sets default values
ASplineActor::ASplineActor()
{

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialize Spline Component and Set it as Root Component
	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
	SplineComponent->bDrawDebug = true;

	// If valid DefaultSubobject, set as RootComponent.
	// Note: Eliminates warnings in UE5 about missing RootComponent. Just good practice.
	//if (SplineComponent) {
	//	SetRootComponent(SplineComponent);
	//}

	SplineComponent->SetupAttachment(RootComponent);

}

void ASplineActor::OnConstruction(const FTransform& Transform)
{
	/*
	* OnConstruction, we want to iterate over the SplinePoints and instantiate the provided Mesh in the correct orientation.
	*/

	// Iterate through all the Spline Points in our SplineComponent.
	for (int i = 0; i < SplineComponent->GetNumberOfSplinePoints() - 1; i++) {

		// Now generate the mesh (NewObject of type USplineMeshComponent) and attach to each Spline Point. Will need to use USplineMeshComponent.
		/*
		* Need to pass our current object (this), as well as the class definition in order to use the convenience template NewObject<>()
		*/
		USplineMeshComponent* SplineMeshComponent = NewObject<USplineMeshComponent>(this, USplineMeshComponent::StaticClass());

		MeshComponents.Add(SplineMeshComponent);
		// Set the Static Mesh.
		SplineMeshComponent->SetStaticMesh(Mesh);

		// Set how often this component is able to move at runtime
		SplineMeshComponent->SetMobility(EComponentMobility::Movable);

		// Set the creation method, meaning we are deferring construction to the Bluepring Construction Scripts.
		SplineMeshComponent->CreationMethod = EComponentCreationMethod::UserConstructionScript;

		// Register this Component in the World.
		SplineMeshComponent->RegisterComponentWithWorld(GetWorld());

		// Attach to the RootComponent, Relative to RootComponent. 
		SplineMeshComponent->AttachToComponent(SplineComponent, FAttachmentTransformRules::KeepRelativeTransform);

		/*
		* Every Spline Point, we want to generate the given Mesh in between the current SplinePoint, and the next one.
		* Therefore, we must grab the respective references to each SplinePoint Vectors and Tangents
		*/

		const FVector StartPoint = SplineComponent->GetLocationAtSplinePoint(i, ESplineCoordinateSpace::Local);
		const FVector EndPoint = SplineComponent->GetLocationAtSplinePoint(i + 1, ESplineCoordinateSpace::Local);
		const FVector StartTangent = SplineComponent->GetTangentAtSplinePoint(i, ESplineCoordinateSpace::Local);
		const FVector EndTangent = SplineComponent->GetTangentAtSplinePoint(i + 1, ESplineCoordinateSpace::Local);

		// Now set all the necessary variables needed for the SplineMeshComponent, in local space.
		SplineMeshComponent->SetStartAndEnd(StartPoint, StartTangent, EndPoint, EndTangent, true);

		/*
		* IMPORTANT: Set the collision to interact with it in the World.
		* QueryAndPhysics: Can be used for both spatial queries (raycasts, sweeps, overlaps) and simulation (rigid body, constraints).
		*/
		SplineMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

		// Because we have the given forwardAxis from In-Editor, we can set the Given Mesh's forwardAxis as well.
		SplineMeshComponent->SetForwardAxis(forwardAxis);

	}

}

// Called when the game starts or when spawned
void ASplineActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASplineActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

