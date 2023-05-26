#include <bits/stdc++.h>
void print(int board[4][4]){
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			printf(" %d ", board[i][j]);
		printf("\n");
	}}
bool isSafe(int board[4][4], int row, int col){
	int i, j;
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;
	for (i = row, j = col; j >= 0 && i < 4; i++, j--)
		if (board[i][j])
			return false;
	return true;
}
bool Nqueen(int board[4][4], int col){
          if (col >= 4)
		return true;
	for (int i = 0; i < 4; i++) {
	
		if (isSafe(board, i, col)) {
    		board[i][col] = 1;
			if (Nqueen(board, col + 1))
				return true;
			board[i][col] = 0;}
    }
	return false;
}
bool solveNQ(){
    int board[4][4] = { { 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 } };
	if (Nqueen(board, 0) == false) {
		printf("Solution does not exist");
		return false;
	}
	print(board);
    	return true;}
int main(){
	solveNQ();
	return 0;
}
