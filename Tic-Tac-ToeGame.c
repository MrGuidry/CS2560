/*
 * Tic-Tac-ToeGame.c
 *
 *  Created on: February 18, 2019
 *      Author: Ryan Guidry
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define ROWS 3
#define COLUMNS 3

void displayContents(char board[ROWS][COLUMNS]);
int checkWin(char board[ROWS][COLUMNS], char playerSymbol);

int TicTacToeGame(){
	char board[3][3] =
	{
		"***",
		"***",
		"***"
	};
	char playerSymbol = ' ';
	int row, column;

	int turn = 0;
	int win = 0;

	while(win == 0){
		displayContents(board);
		if(turn == 0){
			printf("Player 1's turn\n");
			playerSymbol = 'X';
		}else{
			printf("Player 2's turn\n");
			playerSymbol = 'O';
		}

		bool valid = false;
		while(!valid){
			printf("Which row?");
			fflush(stdout);
			scanf("%d", &row);
			printf("Which column?");
			fflush(stdout);
			scanf("%d", &column);
			if(board[row][column] == '*'){
				board[row][column] = playerSymbol;
				valid = true;
			}else{
				printf("Invalid Move. Try Again.\n");
			}
		}
		win = checkWin(board, playerSymbol);
		if(win == 0){
			if(turn == 0){
				turn = 1;
			}else{
				turn = 0;
			}
		}
	}
	displayContents(board);
	if(win == -1){
		printf("The game ended in a tie!");
	}else{
		if(turn == 0){
			printf("Player 1 has won the game!");
		}else{
			printf("Player 2 has won the game!");
		}
	}

	return 0;
}

void displayContents(char board[ROWS][COLUMNS]){
	printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
	printf("---+---+---\n");
	printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
	printf("---+---+---\n");
	printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int checkWin(char board[ROWS][COLUMNS], char playerSymbol){
	if(board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] == playerSymbol){
		return 1;
	}else if(board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] == playerSymbol){
		return 1;
	}else if(board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == playerSymbol){
		return 1;
	}else if(board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] == playerSymbol){
		return 1;
	}else if(board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] == playerSymbol){
		return 1;
	}else if(board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] == playerSymbol){
		return 1;
	}else if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == playerSymbol){
		return 1;
	}else if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == playerSymbol){
		return 1;
	}else if((board[0][0] != '*')&&(board[0][1] != '*')&&(board[0][2] != '*')
			&&(board[1][0] != '*')&&(board[1][1] != '*')&&(board[1][2] != '*')
			&&(board[2][0] != '*')&&(board[2][1] != '*')&&(board[2][2] != '*')){
		return -1; //Draw
	}// 1 = win
	return 0; //Still playable
}
