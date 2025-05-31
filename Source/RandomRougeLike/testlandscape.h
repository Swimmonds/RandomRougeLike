// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "testlandscape.generated.h"

class UProceduralMeshComponent;
class UMaterialInterface;

UCLASS()
class RANDOMROUGELIKE_API Atestlandscape : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	Atestlandscape();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(EditAnywhere)
	UMaterialInterface* Material;

	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0))
	int Xsize = 0; //Number of grid cells along X axis
	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0))
	int Ysize = 0; //Number of grid cells along y axis
	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0))
	float Zscale = 1.0f; 
	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0))
	float NoiseScale = 1.0f;

	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0.000001))
	float Scale = 0;
	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0.000001))
	float UVScale = 0;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UProceduralMeshComponent* ProceduralMesh;

	TArray<FVector> Vertices;
	TArray<int> Triangles;
	TArray<FVector2D> UV0;
	TArray<FVector> Normals;
	TArray<struct FProcMeshTangent> Tangents;

	void CreateVertices();

	void CreateTriangles();
};
