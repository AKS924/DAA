#include <stdio.h>
#include<conio.h>
#define MAX 10

struct edge {
    int u, v, w;
};

struct edge_list {
    struct edge data[MAX];
    int n;
} elist, spanlist;

int graph[MAX][MAX], n;
int belongs[MAX];

int find(int vertex) {
    return belongs[vertex];
}

void union1(int c1, int c2) {
    int i;
    for(i = 0; i < n; i++) {
	if(belongs[i] == c2)
	    belongs[i] = c1;
    }
}

void sort() {
    int i, j;
    struct edge temp;

    for(i = 0; i < elist.n - 1; i++) {
	for(j = 0; j < elist.n - i - 1; j++) {
	    if(elist.data[j].w > elist.data[j+1].w) {
		temp = elist.data[j];
		elist.data[j] = elist.data[j+1];
		elist.data[j+1] = temp;
	    }
	}
    }
}

void kruskal() {
    int i, j, cno1, cno2;

    elist.n = 0;

    for(i = 0; i < n; i++) {
	for(j = 0; j < n; j++) {
	    if(graph[i][j] != 0) {
		elist.data[elist.n].u = i;
		elist.data[elist.n].v = j;
		elist.data[elist.n].w = graph[i][j];
		elist.n++;
	    }
	}
    }

    sort();

    for(i = 0; i < n; i++)
	belongs[i] = i;

    spanlist.n = 0;

    for(i = 0; i < elist.n; i++) {
	cno1 = find(elist.data[i].u);
	cno2 = find(elist.data[i].v);

	if(cno1 != cno2) {
	    spanlist.data[spanlist.n] = elist.data[i];
	    spanlist.n++;
	    union1(cno1, cno2);
	}
    }
}

void display() {
    int i, cost = 0;

    printf("\nEdges in MST:\n");
    for(i = 0; i < spanlist.n; i++) {
	printf("%d -> %d : %d\n",
	       spanlist.data[i].u,
	       spanlist.data[i].v,
	       spanlist.data[i].w);
	cost += spanlist.data[i].w;
    }

    printf("Total cost of MST = %d\n", cost);
}

void main() {
    int i, j;
    clrscr();
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
	for(j = 0; j < n; j++) {
	    scanf("%d", &graph[i][j]);
	}
    }

    kruskal();
    display();

    getch();
}