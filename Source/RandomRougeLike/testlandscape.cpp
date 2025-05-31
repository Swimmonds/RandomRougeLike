// Fill out your copyright notice in the Description page of Project Settings.


#include "testlandscape.h"
#include "ProceduralMeshComponent.h"
#include "KismetProceduralMeshLibrary.h"

// Sets default values
Atestlandscape::Atestlandscape()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ProceduralMesh = CreateDefaultSubobject<UProceduralMeshComponent>("ProceduralMesh");
	ProceduralMesh->SetupAttachment(GetRootComponent());
}

void Atestlandscape::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	Vertices.Reset();
	Triangles.Reset();
	UV0.Reset();

	CreateVertices();
	CreateTriangles();

	UKismetProceduralMeshLibrary::CalculateTangentsForMesh(Vertices, Triangles, UV0, Normals, Tangents);

	ProceduralMesh->CreateMeshSection(0, Vertices, Triangles, Normals, UV0, TArray<FColor>(), Tangents, true);
	ProceduralMesh->SetMaterial(0, Material);
}
	

// Called when the game starts or when spawned
void Atestlandscape::BeginPlay()
{
	Super::BeginPlay();


}

// Called every frame
void Atestlandscape::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void Atestlandscape::CreateVertices()
{
	for (int x = 0; x <= Xsize; x++)
	{
		for (int y = 0; y <= Ysize; y++)
		{
			float z = FMath::PerlinNoise2D(FVector2D(x * NoiseScale + 0.1 , y * NoiseScale + 0.1)) * Zscale;
			Vertices.Add(FVector(x * Scale, y * Scale, z));
			UV0.Add(FVector2D(x * UVScale, y * UVScale));

		}
	}
}

void Atestlandscape::CreateTriangles()
{
	int VertexIndex = 0;

	for (int x = 0; x < Xsize; x++)
	{
		for (int y = 0; y < Ysize; y++)
		{
			Triangles.Add(VertexIndex);
			Triangles.Add(VertexIndex + 1);
			Triangles.Add(VertexIndex + Ysize + 1);
			Triangles.Add(VertexIndex + 1);
			Triangles.Add(VertexIndex + Ysize + 2);
			Triangles.Add(VertexIndex + Ysize + 1);

			VertexIndex++;
		}
		VertexIndex++;
	}
	
}