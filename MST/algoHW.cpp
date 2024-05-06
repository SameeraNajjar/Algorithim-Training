#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

class MinimumSpanningTree {
    int numVertices;
    vector<Edge> edges;

public:
    /* Constructor */
    MinimumSpanningTree(int numVertices) {
        this->numVertices = numVertices;
    }

    /* Add an edge to the graph */
    void addEdge(int src, int dest, int weight) {
        Edge edge = { src, dest, weight };
        edges.push_back(edge);
    }

    /* Find the parent of a vertex */
    int find(int parent[], int i) {
        while (parent[i] != i)
            i = parent[i];
        return i;
    }

    /* Union two sets by rank */
    void unionSets(int parent[], int rank[], int x, int y) {
        int xRoot = find(parent, x);
        int yRoot = find(parent, y);

        if (rank[xRoot] < rank[yRoot])
            parent[xRoot] = yRoot;
        else if (rank[xRoot] > rank[yRoot])
            parent[yRoot] = xRoot;
        else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }

    /* Find the Minimum Spanning Tree */
    void findMinimumSpanningTree() {
        vector<Edge> mst;
        int* parent = new int[numVertices];
        int* rank = new int[numVertices];

        sort(edges.begin(), edges.end(), compareEdges);

        for (int i = 0; i < numVertices; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        int count = 0;
        int i = 0;
        while (count < numVertices - 1 && i < edges.size()) {
            Edge nextEdge = edges[i];

            int x = find(parent, nextEdge.src);
            int y = find(parent, nextEdge.dest);

            if (x != y) {
                mst.push_back(nextEdge);
                unionSets(parent, rank, x, y);
                count++;
            }

            i++;
        }

        cout << "Edges in MST:" << endl;
        int totalWeight = 0;
        for (const auto& edge : mst) {
            cout << edge.src + 1 << " - " << edge.dest + 1 << ", Weight-> " << edge.weight << endl;
            totalWeight += edge.weight;
        }

        cout << "Total Weight of MST: " << totalWeight << endl;

        delete[] parent;
        delete[] rank;
    }
};
int main() {
    int numVertices, numEdges;
    cout << "# of vertices: ";
    cin >> numVertices;
    cout << "# of edges: ";
    cin >> numEdges;
    MinimumSpanningTree mst(numVertices);
    cout << "Insert the source, destination, and weight of each edge:" << endl;
    for (int i = 0; i < numEdges; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        src--;
        dest--;
        mst.addEdge(src, dest, weight);
    }
    mst.findMinimumSpanningTree();
    return 0;
}