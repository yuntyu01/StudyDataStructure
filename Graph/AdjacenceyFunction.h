#include<stdlib.h>
#include<stdio.h>
#include "AdjacenceyListNode.h"

Graph* CreateGraph() {
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->VertexCount = 0;
	graph->Vertices = NULL;

	return graph;
}

Vertex* CreateVertex(VElementType Data) {
	Vertex* V = (Vertex*)malloc(sizeof(Vertex));

	V->Data = Data;
	V->AdjacencyList = NULL;
	V->Index = - 1;
	V->Next = NULL;
	V->Visited = NotVisited;
}

Edge* CreateEdge(Vertex* From, Vertex* Target, int Weight){
	Edge * E = (Edge*)malloc(sizeof(Edge));
	E->From = From;
	E->Target = Target;
	E->Next = NULL;
	E->Weight = Weight;
	
	return E;
}

void AddVertex(Graph* G, Vertex* V) {
	Vertex* VertexList = G->Vertices;

	if (VertexList == NULL) {
		G->Vertices = V;
	}
	else {
		while (VertexList->Next != NULL) {
			VertexList = VertexList->Next;
		}
		VertexList->Next = V;
	}

	V->Index = G->VertexCount++;
}

void AddEdge(Vertex* V, Edge* E) {
	if (V->AdjacencyList == NULL) {
		V->AdjacencyList = E;
	}
	else {
		Edge* AdJacencyList = V->AdjacencyList;
		while (AdJacencyList->Next != NULL) {
			AdJacencyList = AdJacencyList->Next;
		}

		AdJacencyList->Next = E;
	}
}

void PrintGraph(Graph* G) {
	Vertex* V = NULL;
	Edge* E = NULL;

	if ((V = G->Vertices) == NULL)
		return;

	while (V != NULL) {
		printf("%c : ", V->Data);
	
		if ((E = V->AdjacencyList) == NULL) {
			V = V->Next;
			printf("\n");
			continue;
		}

		while (E != NULL) {
			printf("%c[%d]", E->Target->Data, E->Weight);
			E = E->Next;
		}

		printf("\n");

		V = V->Next;
	}

	printf("\n");
}


