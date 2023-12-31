#include <stdio.h>
#include <string.h>

void computeLPS(char *pattern, int M, int lps[]) {
    int length = 0;
    lps[0] = 0; // lps[0] is always 0

    int i = 1;
    while (i < M) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

     printf("\nLPS Array : ");
     for(int i=0;i<strlen(pattern);i++)
     printf(" %d ,",lps[i]);
    
}

void KMPSearch(char *text, char *pattern) {
    int M = strlen(pattern);
    int N = strlen(text);

    int lps[M]; // Longest prefix suffix array for the pattern

    computeLPS(pattern, M, lps);

    int i = 0; // Index for text[]
    int j = 0; // Index for pattern[]

    while (i < N) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == M) {
            printf("\nPattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    } 
  
}

int main() {
    char text[1000];
    char pattern[100];

    printf("Enter the text: ");
    gets(text);

    printf("Enter the pattern: ");
    gets(pattern);

    printf("Pattern matching results:\n");
   KMPSearch(text, pattern);
}
