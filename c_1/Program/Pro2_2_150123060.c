//Arda Can Ergin 150123060

//An mxn matrix is taken from user as input in from of the number of rows, number of columns and the each entry
//two functions implemented to find the longest increasing path within the matrix (diagonal movement is not allowed)
#include<stdio.h>
#include<stdlib.h>

void findPath(int col, int row, int matrix[][col], int cellMatrix[][row*col+1]);

void longestPath(int col, int row, int cellMatrix[][row*col+1] );

int main(void) {
    // Create matrix
    printf("Enter number of rows:\n");
    int row;
    scanf("%d",&row);
    printf("Enter number of columns:\n");
    int col;
    scanf("%d",&col);
    int matrix[row][col];
    // every possible path will be kept in that matrix
    // +1 column added to keep the length of the path at the last row
    int cellMatrix[row * col][row * col + 1];
    // initialize cell matrix (stores paths)
    for (int i = 0; i < row * col; i++) {
        for (int k = 0; k < row * col; k++) {
            cellMatrix[i][k] = 0;
        }
    }
    printf("Enter input: matrix=\n");
    // take row*column input for matrix
    for (int i = 0; i < row; i++) {
        for (int k = 0; k < col; k++) {
            scanf("%d",&matrix[i][k]);
        }
    }

    findPath(col, row, matrix, cellMatrix);
    longestPath(col, row, cellMatrix);

}


void longestPath(int col, int row, int cellMatrix[][row*col+1] ) {
    // iterate through every last row of the cellMatrix to find longest path
    // possible

    int longest = cellMatrix[0][row * col];
    int longestRow = 0;
    for (int i = 0; i < col * row; i++) {
        if (cellMatrix[i][row * col] > longest) {
            longest = cellMatrix[i][row * col];
            longestRow = i;
        }
    }
    printf("The longest increasing path is [");
    // print the path
    for (int i = 0; i < longest; i++) {
        printf("%d ", cellMatrix[longestRow][i]);
    }
    printf("] with visiting %d cells", longest);
}

void findPath(int col, int row, int matrix[][col], int cellMatrix[][row*col+1]) {
    int current;
    int next;
    for (int i = 0; i < row; i++) {
        for (int k = 0; k < col; k++) {

            int rowIndex = i;
            int colIndex = k;
            current = matrix[i][k];
            cellMatrix[i * row + k][0] = current;
            next = 1;
            while (1) {
                // check the upper bottom left and right cell for current cell in the middle of
                // matrix
                if (rowIndex > 0 && rowIndex < row - 1 && colIndex > 0 && colIndex < col - 1) {
                    // check right cell
                    if (current < matrix[rowIndex][colIndex + 1]) {
                        current = matrix[rowIndex][colIndex + 1];
                        cellMatrix[i * row + k][next++] = current;
                        colIndex++;
                        continue;
                    }
                    // check left cell
                    if (current < matrix[rowIndex][colIndex - 1]) {
                        current = matrix[rowIndex][colIndex - 1];
                        cellMatrix[i * row + k][next++] = current;
                        colIndex--;
                        continue;
                    }
                    // check upper cell
                    if (current < matrix[rowIndex - 1][colIndex]) {
                        current = matrix[rowIndex - 1][colIndex];
                        cellMatrix[i * row + k][next++] = current;
                        rowIndex--;
                        continue;
                    }
                    // check bottom cell
                    if (current < matrix[rowIndex + 1][colIndex]) {
                        current = matrix[rowIndex + 1][colIndex];
                        cellMatrix[i * row + k][next++] = current;
                        rowIndex++;
                        continue;
                    }
                }
                // check if current matrix in the first column or last column
                if (colIndex == 0 || colIndex == row - 1) {
                    if(rowIndex==0) {
                        // check bottom cell
                        if (current < matrix[rowIndex + 1][colIndex]) {
                            current = matrix[rowIndex + 1][colIndex];
                            cellMatrix[i * row + k][next++] = current;
                            rowIndex++;
                            continue;
                        }
                    }
                    if(rowIndex==col-1) {
                        // check upper cell
                        if (current < matrix[rowIndex - 1][colIndex]) {
                            current = matrix[rowIndex - 1][colIndex];
                            cellMatrix[i * row + k][next++] = current;
                            rowIndex--;
                            continue;
                        }
                    }
                    if(rowIndex>0 && rowIndex<row-1) {
                        // check upper cell
                        if (current < matrix[rowIndex - 1][colIndex]) {
                            current = matrix[rowIndex - 1][colIndex];
                            cellMatrix[i * row + k][next++] = current;
                            rowIndex--;
                            continue;
                        }
                        // check bottom cell
                        if (current < matrix[rowIndex + 1][colIndex]) {
                            current = matrix[rowIndex + 1][colIndex];
                            cellMatrix[i * row + k][next++] = current;
                            rowIndex++;
                            continue;
                        }
                    }
                    if (colIndex == 0) {
                        // check right cell
                        if (current < matrix[rowIndex][colIndex + 1]) {
                            current = matrix[rowIndex][colIndex + 1];
                            cellMatrix[i * row + k][next++] = current;
                            colIndex++;
                            continue;
                        }
                    }
                    if (colIndex == col - 1) {
                        // check left cell
                        if (current < matrix[rowIndex][colIndex - 1]) {
                            current = matrix[rowIndex][colIndex - 1];
                            cellMatrix[i * row + k][next++] = current;
                            colIndex--;
                            continue;
                        }

                    }
                }
                // check if matrix in the first row or last row but not in the first column or
                // last column
                if (rowIndex == 0 || rowIndex == row - 1) {
                    if (colIndex > 0 && colIndex < col - 1) {
                        // check right cell
                        if (current < matrix[rowIndex][colIndex + 1]) {
                            current = matrix[rowIndex][colIndex + 1];
                            cellMatrix[i * row + k][next++] = current;
                            colIndex++;
                            continue;
                        }
                        // check left cell
                        if (current < matrix[rowIndex][colIndex - 1]) {
                            current = matrix[rowIndex][colIndex - 1];
                            cellMatrix[i * row + k][next++] = current;
                            colIndex--;
                            continue;
                        }
                    }
                    if (colIndex == 0) {
                        // check right cell
                        if (current < matrix[rowIndex][colIndex + 1]) {
                            current = matrix[rowIndex][colIndex + 1];
                            cellMatrix[i * row + k][next++] = current;
                            colIndex++;
                            continue;
                        }
                    }
                    if (colIndex == col - 1) {
                        // check left cell
                        if (current < matrix[rowIndex][colIndex - 1]) {
                            current = matrix[rowIndex][colIndex - 1];
                            cellMatrix[i * row + k][next++] = current;
                            colIndex--;
                            continue;
                        }
                    }
                    if (rowIndex == 0) {
                        // check bottom
                        if (current < matrix[rowIndex + 1][colIndex]) {
                            current = matrix[rowIndex + 1][colIndex];
                            cellMatrix[i * row + k][next++] = current;
                            rowIndex++;
                            continue;
                        }
                    }
                    if (rowIndex == row - 1) {
                        // check upper
                        if (current < matrix[rowIndex - 1][colIndex]) {
                            current = matrix[rowIndex - 1][colIndex];
                            cellMatrix[i * row + k][next++] = current;
                            rowIndex--;
                            continue;
                        }
                    }

                }

                cellMatrix[i * row + k][row * col] = next; // record length of the path to the last column
                // if non of the conditions are satisfied while loop will be terminated manually
                break;
            }
        }
    }
}
