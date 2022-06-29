#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <vector>
using namespace std;

int **Griglia;

int SchemaColonne(int N, int M){
	
	return ((N*M) - (M/3)*N); 
	
}

int SchemaRighe(int N, int M){
	
		
	return ((N*M) - (N/3)*M); 
	
}

int cella(int a, int N, int b, int M){
	
	if (b-2>=0){
		//Celeste
		if (Griglia[a][b-1] == 1 && Griglia[a][b-2] == 1){
			Griglia[a][b] = 0;
			return 0;
		}
}
	if (a>=2 && b>=2){
		//Rosso
		if (Griglia[a-1][b-1] == 1 && Griglia[a-2][b-2] == 1){
			Griglia[a][b] = 0;
			return 0;
		}
	
		//verde
		if (Griglia[a-1][b] == 1 && Griglia[a-2][b] == 1){
			Griglia[a][b] = 0;
			return 0;
		}
	}
	if (a>=2 && b+2<=M){	
		//Viola
		if (Griglia[a-1][b+1] == 1 && Griglia[a-2][b+2] == 1){
			Griglia[a][b] = 0;
			return 0;
		}
	}
	if (b+2<=M){	
		//Celeste
		if (Griglia[a][b+1] == 1 && Griglia[a][b+2] == 1){
			Griglia[a][b] = 0;
			return 0;
		}
	}
	if (a+2<=N && b+2<=M){
		//Rosso
		if (Griglia[a+1][b+1] == 1 && Griglia[a+2][b+2] == 1){
			Griglia[a][b] = 0;
			return 0;
		}
	}
	if (a+2<=N){	
		//Verde
		if (Griglia[a+1][b] == 1 && Griglia[a+2][b] == 1){
			Griglia[a][b] = 0;
			return 0;
		}
	}
	if (a+2<=N && b>=2){	
		//Viola
		if (Griglia[a+1][b] == 1 && Griglia[a+2][b] == 1){
			Griglia[a][b] = 0;
			return 0;
		}
	}
	Griglia[a][b] = 1;
	return 1;	
}

int SchemaRC(int N, int M){
	int j,ris = 0,c;
	
		 for (int i = 0; i < N; i++)
		 	for (j = 0; j < M; j++) {
		 		c = cella(i, N, j, M);
			
		 	 	ris = ris + c;
		 	 	
		 	} 
			 	
	return ris;
         
    }
	


int gioca(int NRighe, int MColonne) {
	
	if (NRighe<=2) return SchemaColonne(NRighe, MColonne);
	if (MColonne<=2) return SchemaRighe(NRighe, MColonne);
	
	// più di due colonne e/o 2 righe
    return SchemaRC(NRighe, MColonne);
}


int main() {
    FILE *fr, *fw;
    int N, M;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &M));

	Griglia= new int*[N];
	
	for (int i=0; i<N; i++)
		Griglia[i]=new int[M]; 

    fprintf(fw, "%d\n", gioca(N, M));
    fclose(fr);
    fclose(fw);

	for (int i=0; i<N; i++)
		delete[]Griglia[i];
	delete[]Griglia;
    
	return 0;
}
