typedef int VElementType;

enum VisitMode{Visited, NotVisited};

typedef struct tagVertex {
	VElementType Data;
	int Visited;
	int Index;

	struct tagVertex* Next;
	struct tagEdge* AdjacencyList;
}Vertex;

typedef struct tagEdge {
	int Weight;
	struct tagEdge* Next;
	Vertex* From;
	Vertex* Target;
}Edge;

typedef struct tagGraph
{
	Vertex* Vertices;
	int VertexCount;
}Graph;