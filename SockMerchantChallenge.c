#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** SplitString(char*);

// Complete the sockMerchant function below.
int sockMerchant(int NumberOfSocksInTheArray, int* ArrayOfSocks) {
    return 0;
}

int GetTheCurrentNumberOfSocksInTheArray(FILE* TestFile) {
	char* EndOfLongInteger;
	char* CurrentLine = readline();
	int BaseTen = 10;
	int CurrentNumberOfSocks = strtol(CurrentLine, &EndOfLongInteger, BaseTen);
	
	char Zero = '\0';
	/* What does the following code do?
	
	Does it check to see what the end of the long integer is, and make
	sure it's zero? Why do this?
	
	 */
	if (EndOfLongInteger == CurrentLine || *EndOfLongInteger != Zero) {
		exit(EXIT_FAILURE);
	}
	
	return CurrentNumberOfSocks;
}

int main()
{
    FILE* TestFile = fopen(getenv("OUTPUT_PATH"), "w");

    int CurrentNumberOfSocks = GetTheCurrentNumberOfSocksInTheArray(TestFile);


    char** ar_temp = SplitString(readline());

    int* ar = malloc(CurrentNumberOfSocks * sizeof(int));

    for (int i = 0; i < CurrentNumberOfSocks; i++) {
        char* ar_item_endptr;
        char* ar_item_str = *(ar_temp + i);
        int ar_item = strtol(ar_item_str, &ar_item_endptr, 10);

        if (ar_item_endptr == ar_item_str || *ar_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(ar + i) = ar_item;
    }


    int NumberOfMatchingPairsOfSocks = sockMerchant(CurrentNumberOfSocks, ar);

    fprintf(TestFile, "%d\n", NumberOfMatchingPairsOfSocks);

    fclose(TestFile);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

/* Oh jeez, let's see what this does

	Looks like it splits the inputstring into an array of strings called splits
	
	First thing, let's rename that garbage name
 */
char** SplitString(char* InputString) {
    char** ArrayOfStrings = NULL;
	
    char* token = strtok(InputString, " "); 
	/* So we split the input string into tokens, delimited by spaces
	
	But why?
	*/
    int spaces = 0;

    while (token) {
        // So that we can realloc?
        
		ArrayOfStrings = realloc(ArrayOfStrings, sizeof(char*) * ++spaces);
		// sizeof(char*) == 4
		
		if (!ArrayOfStrings) {
            return ArrayOfStrings;
        }

        ArrayOfStrings[spaces - 1] = token;

		// What is this?
        token = strtok(NULL, " ");
    }

    return ArrayOfStrings;
}
