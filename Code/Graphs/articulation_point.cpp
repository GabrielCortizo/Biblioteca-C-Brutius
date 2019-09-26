/*Encontra vértices que quando removidos, desconectam as componentes conexas de um grafo*/

vector<int> g[ms];
int tin[ms], low[ms], cont, n;
void is_articulation(int v){}

void dfs(int v, int p = -1){
	tin[v] = low[v] = cont++;
	int ch = 0;
	for(auto &to:g[v]){
		if(to == p) continue;
		if(tin[to] == -1){
			dfs(to, v);
			low[v] = min(low[v], low[to]);
			if(low[to] >= tin[v] and p!=-1)
				is_articulation(v);
				
		ch++;
		}else{
			low[v] = min(low[v], tin[to]);
		}
	}
	if(p== -1 and ch > 1)
		is_articulation(v);
}

void find_articulation(){
	memset(tin, -1, sizeof tin);
	memset(low, -1, sizeof low);
	cont = 1;
	
	for(int i = 0;i<n;i++){
		if(tin[i] == -1)
			dfs(i);
	}
}

