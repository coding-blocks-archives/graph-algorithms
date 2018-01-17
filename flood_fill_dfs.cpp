#include<iostream>
using namespace std;
	

int R;
int C;



void printMat(char input[][50]){

	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout<<input[i][j];
		}
		cout<<endl;
	}

}

// W,N,E,S
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

//ch is the character to be replaced
//color is the character to be added 
void floodFill(char mat[][50],int i,int j,char ch,char color){
	//Base Case - Matrix Bounds
	if(i<0||j<0 ||i>=R||j>=C){
		return;
	}
	// Figure Boundary Condition
	if(mat[i][j]!=ch){
		return;
	}
	//Recursive Call
	mat[i][j] = color;

	printMat(mat);
	cout<<endl;

	for(int k=0;k<4;k++){
		floodFill(mat,i+dx[k],j+dy[k],ch,color);
	}
}



int main(){

	cin>>R>>C;

	char input[15][50];
	
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin>>input[i][j];
		}
	}

	printMat(input);

	floodFill(input,8,13,'.','r');
	//floodFill(input,0,0,'.','!');

	printMat(input);

	


	return 0;
}