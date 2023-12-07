// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"
#include "SplineActor.generated.h"

UCLASS()
class SUPERMONKEYBOWLING_API ASplineActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASplineActor();

	// Actual Spline Component that will be the backbone of this Tool.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Spline");
	USplineComponent* SplineComponent;

	// Provide a Mesh to this component for it to generate along the Spline
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spline");
	UStaticMesh* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Spline")
	TArray<USplineMeshComponent*> MeshComponents;

	// Safely Store Enums in type-safe way.
	// User will set the forward axis In-Editor, which we will then use to set the given mesh's 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spline");
	TEnumAsByte<ESplineMeshAxis::Type> forwardAxis;

	/**
	 * Called when an instance of this class is placed (in editor) or spawned.
	 * @param	Transform			The transform the actor was constructed at.
	 */
	void OnConstruction(const FTransform& Transform) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
