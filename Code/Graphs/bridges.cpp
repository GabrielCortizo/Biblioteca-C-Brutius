/*Encontra arestas que quando removidas, desconectam as componentes conexas de um grafo*/
vector<int> g[ms];
int tin[ms], low[ms], cont, n;
void is_bridge(int u, int v){}

void dfs(int v, int p = -1){
	tin[v] = low[v] = cont++;
	
	for(auto &to:g[v]){
		if(to == p) continue;
		if(tin[to] == -1){
			dfs(to, v);
			low[v] = min(low[v], low[to]);
			if(low[to] > tin[v])
				is_bridge(v,to);
		}else{
			low[v] = min(low[v], tin[to]);
		}
	}
}

void find_bridges(){
	memset(tin, -1, sizeof tin);
	memset(low, -1, sizeof low);
	cont = 1;
	
	for(int i = 0;i<n;i++){
		if(tin[i] == -1)
			dfs(i);
	}
}


