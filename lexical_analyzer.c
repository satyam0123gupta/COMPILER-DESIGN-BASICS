#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char keywords[32][10] = {
    "auto","break","case","char","const","continue","default","do","double",
    "else","enum","extern","float","for","goto","if","int","long","register",
    "return","short","signed","sizeof","static","struct","switch","typedef",
    "union","unsigned","void","volatile","while"
};

int isKeyword(char* word) {
	int i; // declare i here
    for(i = 0; i < 32; i++) {
        if(strcmp(keywords[i], word) == 0) {
		            return 1;
	    }
    }
    return 0;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '<' || ch == '>');
}

int main() {
    FILE *fp;
    char ch, buffer[100];
    int i, j = 0;

    fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Error: File not found!\n");
        return 1;
    }

    printf("Lexical Analysis Output:\n\n");

    while ((ch = fgetc(fp)) != EOF) {
        // For identifiers/keywords
        if (isalnum(ch)) {
            buffer[j++] = ch;
        } else if ((ch == ' ' || ch == '\n' || ch == ';' || isOperator(ch)) && j > 0) {
            buffer[j] = '\0';
            j = 0;

            if (isKeyword(buffer))
                printf("[Keyword: %s]\n", buffer);
            else
                printf("[Identifier: %s]\n", buffer);
        }

        // For operators
        if (isOperator(ch)) {
            printf("[Operator: %c]\n", ch);
        }
    }

    fclose(fp);
    return 0;
}
