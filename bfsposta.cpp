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
int n, A[maxn][maxn], F, C;
int padreX[maxn][maxn];
int padreY[maxn][maxn];
vector<int> ansX, ansY;

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
			padreX[new_x][new_y] = actual.x;
			padreY[new_x][new_y] = actual.y;
			
			dot nuevo(new_x, new_y);
			Q.push(nuevo);
			
		}
		
	}
}

int main(){
	scanf("%d %d %d", &n, &F, &C);
	--F; --C;
	forn(i, n){
		forn(j, n){
			scanf("%d", &A[i][j]);
		}
	}
	
	bfs(0, 0); 
	padreX[0][0] = -1; 
	padreY[0][0] = -1;
	
	forn(i, n){
		forn(j, n){
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	if(A[F][C] == 3){
		printf("LLEGUE\n");
		
		while( F != -1 ){
			// printf("(%d, %d)\n", F + 1, C + 1);
			ansX.push_back( F + 1 );
			ansY.push_back( C + 1 );
			
			int new_f, new_c;
			
			new_f = padreX[F][C];
			new_c = padreY[F][C];
			
			F = new_f;
			C = new_c;
			
		}
		
		reverse(ansX.begin(), ansX.end());
		reverse(ansY.begin(), ansY.end());
		
		forn(i, ansX.size()){
			// printf("(%d, %d)\n", ansX[i], ans
			cout << "(" << ansX[i] << ", " << ansY[i] << ")\n";
		}
	
	}
	else {
		printf("NO SE PUEDE\n");
	}
	return 0;
}
