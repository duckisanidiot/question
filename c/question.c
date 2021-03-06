#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// initial character array size 
size_t INITIAL_ARRAY_SIZE = 2000;

// simple join-string-by-delimiter utility function in c
char* join(char **sarr, int sarr_count, char *delim) {

  char *result = "";
  char *result_tmp = "";
  size_t delimsize = sizeof(delim);

  for (int i = 0; i < sarr_count; i++) {

    result_tmp = malloc(sizeof(result));
    strcpy(result_tmp, result);
    
    if (i == sarr_count-1) {

      result = malloc(sizeof(result) + sizeof(sarr[i]));
      strcpy(result, result_tmp);
      strcat(result, sarr[i]);

    } else {

      result = malloc(sizeof(result) + sizeof(sarr[i]) + delimsize);
      strcpy(result, result_tmp);
      strcat(result, sarr[i]);
      strcat(result, delim);
      
    }

    free(result_tmp);

  }

  return result;

}

// implementation of the question function in c
char* question(char *prompt, char **valid, int valid_count) {

  char *input = malloc(INITIAL_ARRAY_SIZE * sizeof(char)); 
  ssize_t read = 0;
  char *joined_valid;
  if (valid_count != 0) {

    joined_valid = join(valid, valid_count, ", ");

  }
 
  for (;;) {

    printf("%s\n", prompt);
    if (valid_count != 0) {

      printf("(%s): ", joined_valid);

    } else {

      printf(": ");

    }
    read = getline(&input, &INITIAL_ARRAY_SIZE, stdin);
    input[read-1] = '\0';

    if (read == 0) {

      return input;

    }

    for (int i = 0; i < valid_count; i++) {

      if (strcmp(valid[i], input) == 0) {

        return input;

      }

    }

    printf("\"%s\" is not a valid answer\n", input);

  }

  free(input);
  free(&read);
  free(joined_valid);

}

int main() {

  question("foo", (char*[]){"bar", "baz"}, 2);
  return 0;

}
