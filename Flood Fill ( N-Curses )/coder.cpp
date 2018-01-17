#include<iostream>
using namespace std;
	
// W,N,E,S
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
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

//c1 is the character to be replaced
//c2 is the character to be added
void floodFill(char mat[][50],int i,int j,char ch,char color){
	//cout<<"In flood fill"<<endl;

	if(i<0||j<0||i>=R||j>=C){
		return;
	}

	if(mat[i][j]!=ch){
		return;
	}

	printMat(mat);
	cout<<endl;

	mat[i][j] = color;

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

	printMat(input);


	return 0;
}