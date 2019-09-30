#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int src,dest;
	long double weight;
};
struct Graph{
	int V,E;
	struct Edge* edge;
};
struct Graph* createGraph(int V, int E){
	struct Graph* graph = new Graph;
	graph->V=V;
	graph->E = E;
	graph->edge = new Edge[graph->E];
	return graph;
}
bool neg(struct Graph* graph, int src){
	int V=graph->V;
	int E=graph->E;
	long double dist[V];
	for(int i=0;i<V;i++) dist[i]=DBL_MAX;
	dist[src]=0;
	for(int i=1;i<=V-1;i++){
		for(int j=0;j<E;j++){
			int u=graph->edge[j].src;
			int v=graph->edge[j].dest;
			long double weight=graph->edge[j].weight;
			if(dist[u]!=DBL_MAX && dist[u]+weight<dist[v]) dist[v]=dist[u]+weight;
		}
	}
	for(int i=0;i<E;i++){
		int u=graph->edge[i].src;
		int v=graph->edge[i].dest;
		long double weight=graph->edge[i].weight;
		if(dist[u]!=DBL_MAX && dist[u]+weight<dist[v]) return true;
	}
	return false;
}
long double x;
int n, m,k=0;
 
int main(){
	int a, b;
	scanf("%d %d",&n,&m);
	struct Graph* graph=createGraph(n,m);
	for(int i =0;i<m;i++){
		scanf("%d %d",&a,&b);
		a--;
		b--;
		scanf("%Lf",&x);
		x=-log(x);
		graph->edge[k].src=a;
		graph->edge[k].dest=b;
		graph->edge[k].weight=x;
		k++;
	}
	if(neg(graph,0)) cout << "inadmissible" << endl;
	else cout << "admissible" << endl;
}
