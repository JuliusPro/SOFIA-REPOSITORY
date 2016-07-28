#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < (int) (n); i++)
#define dforn(i, n) for(int i = (n) - 1; i >= 0; i--)
#define ok(x, n) ( (x) >= 0 && (x) < n )
#define maxn 5005

struct dot {
	int x, y;
	dot(int xx, int yy) {
		x = xx;
		y = yy;
	}
};

int df[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int n, A[maxn][maxn];

void bfs(int x, int y){
	dot inicial(x, y);
	
	queue<dot> Q;
	Q.push(inicial);
	
	while( !Q.empty() ){
		dot actual = Q.front();
		Q.pop();
		
		forn(i, 4){
			int new_x = actual.x + df[i];
			int new_y = actual.y + dc[i];
			
			if( !ok(new_x, n) ) continue;
			if( !ok(new_y, n) ) continue;
			
			if( A[new_x][new_y] == 1 ) continue;
			if( A[new_x][new_y] == 3 ) continue;
			
			A[new_x][new_y] = 3;
			
			dot nuevo(new_x, new_y);
			Q.push(nuevo);
			
		}
		
	}
}

int main(){
	scanf("%d", &n);
	forn(i, n){
		forn(j, n){
			scanf("%d", &A[i][j]);
		}
	}
	bfs(0, 0);
	forn(i, n){
		forn(j, n){
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	return 0;
}
