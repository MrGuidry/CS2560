#include <stdio.h>
#include <stdbool.h>

int main(){
	int rows,columns;
	bool valid = false;
	while(!valid){
		printf("How many rows/columns would you like to have?");
		fflush(stdout);
		scanf("%d", &rows);
		if(rows >=1){
			columns = rows;
			valid = true;
		}else{
			printf("Invalid size. Try again...");
		}
	}


	int row[rows];
	int column[columns];
	for(int x = 0; x < rows; x++){
		row[x] = (x+1);
		column[x] = (x+1);
	}

	int table[rows][columns];

	for(int x = 0; x < rows; x++){
		for(int y = 0; y < columns; y++){
			table[x][y] = row[x] * column[y];
		}
	}

	for(int x = 0; x < rows; x++){
		printf("    %d",row[x]);
	}
	printf("\n+");
	for(int x = 0; x < rows; x++){
		printf("----");
	}
	printf("\n");
	for(int x = 0; x< rows; x++){
		printf("%d|  ", row[x]);
		for(int y = 0; y < columns; y++){
			printf("%d   ", table[x][y]);
		}
		printf("\n");
	}

	return 0;
}
