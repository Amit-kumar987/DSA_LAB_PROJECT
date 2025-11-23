#include <stdio.h>

#define MAX 10

int adj[MAX][MAX];
int n = 0;   // number of vertices

void createGraph() {
    int edges, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // initialize matrix
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter edges (u v):\n");
    for(int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;   // undirected
    }
}

void insertEdge() {
    int u, v;
    printf("Enter edge to insert (u v): ");
    scanf("%d %d", &u, &v);
    adj[u][v] = 1;
    adj[v][u] = 1;
    printf("Edge inserted.\n");
}

void printMatrix() {
    printf("\nAdjacency Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
}

void listAdjacent() {
    int v;
    printf("Enter vertex: ");
    scanf("%d", &v);

    printf("Adjacent vertices of %d: ", v);
    for(int i = 0; i < n; i++) {
        if(adj[v][i] == 1)
            printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n===== GRAPH MENU =====\n");
        printf("1. Create Graph\n");
        printf("2. Insert Edge\n");
        printf("3. Print Adjacency Matrix\n");
        printf("4. List Adjacent Vertices\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: createGraph(); break;
            case 2: insertEdge(); break;
            case 3: printMatrix(); break;
            case 4: listAdjacent(); break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}
4