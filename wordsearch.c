#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Declarations of the two functions you will implement
// Feel free to declare any helper functions or global variables
void printPuzzle(char** arr);
void searchPuzzle(char** arr, char* word);
void firstElement(char** arr, char* word,int size);
void nextElement(char** arr, int** mat, char* word, int x, int y, int length, int index);
void cont(char** arr, int** mat, char* word, int x, int y, int length, int index);
int bSize;
int **answers;

// Main function, DO NOT MODIFY 	
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
        return 2;
    }
    int i, j;
    FILE *fptr;

    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }

    // Read the size of the puzzle block
    fscanf(fptr, "%d\n", &bSize);
    
    // Allocate space for the puzzle block and the word to be searched
    char **block = (char**)malloc(bSize * sizeof(char*));
    char *word = (char*)malloc(20 * sizeof(char));

    // Read puzzle block into 2D arrays
    for(i = 0; i < bSize; i++) {
        *(block + i) = (char*)malloc(bSize * sizeof(char));
        for (j = 0; j < bSize - 1; ++j) {
            fscanf(fptr, "%c ", *(block + i) + j);            
        }
        fscanf(fptr, "%c \n", *(block + i) + j);
    }
    fclose(fptr);

    printf("Enter the word to search: ");
    scanf("%s", word);
    
    // Print out original puzzle grid

    // need to uncomment this 
    // printf("\nPrinting puzzle before search:\n");
    // printPuzzle(block);
    
    // Call searchPuzzle to the word in the puzzle
    searchPuzzle(block, word);
    
    return 0;
}

void printPuzzle(char** arr) {
	// This function will print out the complete puzzle grid (arr). 
    // It must produce the output in the SAME format as the samples 
    // in the instructions.
    // Your implementation here...

}


void cleanUp(int** answers, int size){
    for(int i = 0; i < size; i++){
        *(answers + i) = (int*)malloc(size * sizeof(int));
		for(int j = 0; j < size; j++){
			*(*(answers + i) + j) = 0;
		}
	}
}

void printAnswers(int** answers, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%d ", *(*(answers + i) + j));
        }
        printf("\n");
    }
}

void upperCase(char* word){
    int x = 0;
    while(*(word + x) != 0){
        *(word + x) = toupper(*(word + x));
        x++;
    }
}


// need to take in the array // and need to take in the word // and also the size
// take the char of the array 
// size of the array

// takes in new matrix that is the answers 
void firstElement(char** arr, char* word,int size){
    answers = (int**)malloc(bSize * sizeof(int*));
    cleanUp(answers, bSize);
    char look = *(word);
    char check;

    for(int i = 0; i < bSize; i++){
        for(int j = 0; j < bSize; j++){
            check = *(*(arr + i) + j);
            if(check == look){
                *(*(answers + i) + j) = 1;
                // call next element 
                // change this to one so add 1 /*done */
                nextElement(arr,answers,word, i, j, 5, 1);
                // give x and y value for second element function
            }
        }
        if(check == look){
            break;
        }
    }
}

void cont(char** arr, int** mat, char* word, int x, int y, int length, int index){
    if(index + 1 < length){
            nextElement(arr, mat, word, x, y, length, index + 1);
        }
};

void nextElement(char** arr, int** mat, char* word, int x, int y, int length, int index){
    if(*(word + index) == *(*(arr + x + 1) + y)){
        *(*(mat + x + 1) + y) = index + 1;
        x++;
        cont(arr, mat, word, x, y, length, index);
    } else if (*(word + index) == *(*(arr + x - 1) + y)){
        *(*(mat + x - 1) + y) = index + 1;
        x--;
        cont(arr, mat, word, x, y, length, index);
    } else if (*(word + index) == *(*(arr + x) + y + 1)){
        *(*(mat + x) + y + 1) = index + 1;
        y++;
        cont(arr, mat, word, x, y, length, index);
    } else if (*(word + index) == *(*(arr + x) + y - 1)){
        *(*(mat + x) + y - 1) = index + 1;
        y--;
        cont(arr, mat, word, x, y, length, index);
    } else if (*(word + index) == *(*(arr + x - 1) + y + 1)){
        *(*(mat + x - 1) + y + 1) = index + 1;
        x--;
        y++;
        cont(arr, mat, word, x, y, length, index);
    } else if (*(word + index) == *(*(arr + x + 1) + y + 1)){
        *(*(mat + x + 1) + y + 1) = index + 1;
        x++;
        y++;
        cont(arr, mat, word, x, y, length, index);
    } else if (*(word + index) == *(*(arr + x + 1) + y - 1)){
        *(*(mat + x + 1) + y - 1) = index + 1;
        x++;
        y--;
        cont(arr, mat, word, x, y, length, index);
    } else if (*(word + index) == *(*(arr + x - 1) + y - 1)){
        *(*(mat + x - 1) + y - 1) = index + 1;
        x--;
        y--;
        cont(arr, mat, word, x, y, length, index);
    } else{
        firstElement(arr, word, bSize);
    }   
}

void searchPuzzle(char** arr, char* word) {
    // This function checks if arr contains the search word. If the 
    // word appears in arr, it will print out a message and the path 
    // as shown in the sample runs. If not found, it will print a 
    // different message as shown in the sample runs.
    // Your implementation here...

    // int **answers = (int**)malloc(bSize * sizeof(int*));
    upperCase(word);
    firstElement(arr, word, bSize);
    printAnswers(answers,bSize);



}



// 2 functions first to find the first letter
// the other one to find the other letters 
