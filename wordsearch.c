#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Declarations of the two functions you will implement
// Feel free to declare any helper functions or global variables
void printPuzzle(char** arr);
void searchPuzzle(char** arr, char* word);
void firstElement(char** arr, char* word, int x, int y);
void nextElement(char** arr, int** mat, char* word, int x, int y, int length, int index);
void continueSearch(char** arr, int** mat, char* word, int x, int y, int length, int index);
int bSize;
int count = 0;
int **answers;
int **path;

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
    printf("\n");
    printf("Printing puzzle before search:\n");
    for(int i = 0; i < bSize; i++){
        for(int j = 0; j < bSize; j++){
            printf("%c ", *(*(arr + i) + j));
        }
        printf("\n");
    }
    printf("\n");
	// This function will print out the complete puzzle grid (arr). 
    // It must produce the output in the SAME format as the samples 
    // in the instructions.
    // Your implementation here...

}

void printAnswers(int** answers, int size){
	int find = 0;
    int last = -1;
    int change = -1;

    int found = -1;

    for(int i = 0; i < bSize; i++){
        for(int j = 0; j < bSize; j++){
            last = *(*(answers + i) + j);

            if(last > 9){
                if(found == 1){
                    find = 1;
                    break;
                }

                change = last;
                while(change != 0){
                    int lastDigit = change % 10;

                    if(lastDigit == bSize){
                        found = 1;
                        break;
                    }
                    change /= 10;
                }



            } else {
                if(last == bSize){
                    find = 1;
                    break;
                }
            }


        }

        if(find == 1){
            printf("Word found!\n");
            printf("Printing the search path:\n");
            for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                    printf("%d\t", *(*(answers + i) + j));
                }
                printf("\n");
            }
            printf("\n");
            break;
        } 
    }

    if(find == 0){
        printf("Word not found!\n");
    }
}

void copy(int **answers, int **path){
    for(int i = 0; i < bSize; i++){
		for(int j = 0; j < bSize; j++){
            if (*(*(answers + i) + j) != 0){
                *(*(path + i) + j) = *(*(answers + i) + j);
            }
		}
	}

    // for(int i = 0; i < bSize; i++){
    //             for(int j = 0; j < bSize; j++){
    //                 printf("%d\t", *(*(path + i) + j));
    //             }
    //             printf("\n");
    //         }
            // printf("\n");
}

void cleanUp(int** answers, int size){
    for(int i = 0; i < size; i++){
        //*(answers + i) = (int*)malloc(size * sizeof(int));
		for(int j = 0; j < size; j++){
			*(*(answers + i) + j) = 0;
		}
	}
}


void upperCase(char* word){
    int x = 0;
    while(*(word + x) != 0){
    //     *(word + x) = toupper(*(word + x));
    //     x++;
    // }

        if(*(word + x) == 'a'){
            *(word + x) = 'A';
            x++;
        } else if(*(word + x) == 'b'){
            *(word + x) = 'B';
            x++;
        } else if(*(word + x) == 'c'){
            *(word + x) = 'C';
            x++;
        } else if(*(word + x) == 'd'){
            *(word + x) = 'D';
            x++;
        } else if(*(word + x) == 'e'){
            *(word + x) = 'E';
            x++;
        } else if(*(word + x) == 'f'){
            *(word + x) = 'F';
            x++;
        } else if (*(word + x) == 'g'){
            *(word + x) = 'G';
            x++;
        } else if(*(word + x) == 'h'){
            *(word + x) = 'H';
            x++;
        } else if(*(word + x) == 'i'){
            *(word + x) = 'I';
            x++;
        } else if(*(word + x) == 'j'){
            *(word + x) = 'J';
            x++;
        } else if (*(word + x) == 'k'){
            *(word + x) = 'K';
            x++;
        } else if (*(word + x) == 'l'){
            *(word + x) = 'L';
            x++;
        } else if(*(word + x) == 'm'){
            *(word + x) = 'M';
            x++;
        } else if(*(word + x) == 'n'){
            *(word + x) = 'N';
            x++;
        } else if (*(word + x) == 'o'){
            *(word + x) = 'O';
            x++;
        } else if(*(word + x) == 'p'){
            *(word + x) = 'P';
            x++;
        } else if(*(word + x) == 'q'){
            *(word + x) = 'Q';
            x++;
        } else if(*(word + x) == 'r'){
            *(word + x) = 'R';
            x++;
        } else if(*(word + x) == 's'){
            *(word + x) = 'S';
            x++;
        } else if(*(word + x) == 't'){
            *(word + x) = 'T';
            x++;
        } else if(*(word + x) == 'u'){
            *(word + x) = 'U';
            x++;
        } else if(*(word + x) == 'v'){
            *(word + x) = 'V';
            x++;
        } else if(*(word + x) == 'w'){
            *(word + x) = 'W';
            x++;
        } else if(*(word + x) == 'x'){
            *(word + x) = 'X';
            x++;
        } else if(*(word + x) == 'y'){
            *(word + x) = 'Y';
            x++;
        } else if(*(word + x) == 'z'){
            *(word + x) = 'Z';
            x++;
        } else {
            x++;
        }
    }
}


// need to take in the array // and need to take in the word // and also the size
// take the char of the array 
// size of the array

// takes in new matrix that is the answers 
void firstElement(char** arr, char* word, int x, int y){
    char look = *(word);
    char check = '0';
    int length = strlen(word);

    for(int i = 0; i < bSize; i++){
        for(int j = 0; j < bSize; j++){
            if (x + i >= bSize || count >= pow(bSize,2)){
                break;
            } else if(x + i < bSize && y + j < bSize){
                check = *(*(arr + x + i) + y + j);
                if(check == look){
                    *(*(answers + x + i) + y + j) = 1;
                // call next element 
                // change this to one so add 1 /*done */
                    if (length > 1){
                        nextElement(arr,answers,word, x + i, y + j, length, 1);
                    }
                    //break;
                // give x and y value for second element function
                }
            } else if (x + i + 1 < bSize && y + j >= bSize){
                check = *(*(arr + x + i + 1) + y + j -bSize);
                if(check == look){
                    *(*(answers + x + i + 1) + y + j-bSize) = 1;
                // call next element 
                // change this to one so add 1 /*done */
                    if (length > 1){                    
                        nextElement(arr,answers,word, x + i + 1, y + j - bSize, length, 1);
                    }
                }    
            }

            if(check == look){
                break;
            }
        }
        if (x + i >= bSize || count >= pow(bSize,2)){
            break;
        }
        if(check == look){
            break;
        }
    }
}

void continueSearch(char** arr, int** mat, char* word, int x, int y, int length, int index){
    index++;
    if(*(*(mat + x) + y) == 0){
        *(*(mat + x) + y) = index;
    } else if (*(*(mat + x) + y) != 0) {
        int n = 1;
        int temp = *(*(mat + x) + y);
        while (temp >= 10){
            temp /= 10;
            n++;
        }
        int power = pow(10, n);
        *(*(mat + x) + y) += ((index)*power);
    }

    if(index < length){
        count++;
        nextElement(arr, mat, word, x, y, length, index);
    } else if (x < bSize & count < pow(bSize, 2)){
        copy(mat, path);
        for(int i = 0; i < bSize; i++){
            for(int j = 0; j < bSize; j++){
                if(*(*(mat + i) + j) == 1){
                    if(j + 1 < bSize){
                        cleanUp(mat, bSize);
                        count = i * bSize + j + 1; 
                        firstElement(arr, word, i, j + 1);
                    } else {
                        cleanUp(mat, bSize);
                        count = i * bSize + 1 + j - bSize + 1; 
                        firstElement(arr, word, i + 1, j - bSize + 1);
                    }
                }
            }
        }
    }

};

void nextElement(char** arr, int** mat, char* word, int x, int y, int length, int index){
    if(x < bSize - 1 && *(word + index) == *(*(arr + x + 1) + y)){
        x++;
        continueSearch(arr, mat, word, x, y, length, index);
    } else if (x > 0 && *(word + index) == *(*(arr + x - 1) + y)){
        x--;
        continueSearch(arr, mat, word, x, y, length, index);
    } else if (y < bSize -1 && *(word + index) == *(*(arr + x) + y + 1)){
        y++;
        continueSearch(arr, mat, word, x, y, length, index);
    } else if (y > 0 && *(word + index) == *(*(arr + x) + y - 1)){
        y--;
        continueSearch(arr, mat, word, x, y, length, index);
    } else if (y < bSize - 1 && x > 0 && *(word + index) == *(*(arr + x - 1) + y + 1)){
        x--;
        y++;
        continueSearch(arr, mat, word, x, y, length, index);
    } else if (y < bSize - 1 && x < bSize - 1 && *(word + index) == *(*(arr + x + 1) + y + 1)){
        printf("%c", *(*(arr + x + 1) + y + 1));
        x++;
        y++;
        continueSearch(arr, mat, word, x, y, length, index);
    } else if (x < bSize - 1 && y > 0 && *(word + index) == *(*(arr + x + 1) + y - 1)){
        x++;
        y--;
        continueSearch(arr, mat, word, x, y, length, index);
    } else if (x > 0 && x > 0 && *(word + index) == *(*(arr + x - 1) + y - 1)){
        x--;
        y--;
        continueSearch(arr, mat, word, x, y, length, index);
    } else{
        if(y + 1 < bSize){
            cleanUp(answers, bSize);
            firstElement(arr, word, x, y + 1);
        } else {
            cleanUp(answers, bSize);
            firstElement(arr, word, x + 1, y - bSize + 1);
        }
    }   
}

void searchPuzzle(char** arr, char* word) {
    // This function checks if arr continueSearchains the search word. If the 
    // word appears in arr, it will print out a message and the path 
    // as shown in the sample runs. If not found, it will print a 
    // different message as shown in the sample runs.
    // Your implementation here...

    // int **answers = (int**)malloc(bSize * sizeof(int*));
    answers = (int**)malloc(bSize * sizeof(int*));
    for(int i = 0; i < bSize; i++){
        *(answers + i) = (int*)calloc(bSize, sizeof(int));
    }
    path = (int**)malloc(bSize * sizeof(int*));
    for(int i = 0; i < bSize; i++){
        *(path + i) = (int*)calloc(bSize, sizeof(int));
    }
    upperCase(word);
    firstElement(arr, word, 0, 0);
    printPuzzle(arr);
    printAnswers(path,bSize);



}



// 2 functions first to find the first letter
// the other one to find the other letters 
