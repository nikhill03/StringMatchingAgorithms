
#include <stdio.h>
#include <string.h>


#define d 256


void search(char pat[], char txt[], int q)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int i, j;
	int p = 0; 
	int t = 0; 
	int h = 1;
    int shift=0;

	
	for (i = 0; i < M - 1; i++)
		h = (h * d) % q;

	
	for (i = 0; i < M; i++) {
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	}

	
     
	for (i = 0; i <= N - M; i++) {

		if (p == t) {
			
			for (j = 0; j < M; j++) {
				if (txt[i + j] != pat[j])
					break;
			}

			
			if (j == M)
				printf("\nPattern found at index %d \n", i);
                printf("Pattern found after %d shifts \n", shift);
		}

		
		if (i < N - M) {
			t = (d * (t - txt[i] * h) + txt[i + M]) % q;

			
			if (t < 0)
				t = (t + q);
		}
        shift++;
	}
}


int main()
{
	

    char text[100];
    char patterns[10][100]; 
    int numPatterns;

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strlen(text) - 1] = '\0';

    printf("Enter the number of patterns: ");
    scanf("%d", &numPatterns);
    getchar(); // Consume the newline character

    printf("Enter the patterns:\n");
    for (int i = 0; i < numPatterns; i++) {
        fgets(patterns[i], sizeof(patterns[i]), stdin);
        patterns[i][strlen(patterns[i]) - 1] = '\0';
    }
    int q = 101;

    printf("Occurrences of the patterns:\n");
    for (int i = 0; i < numPatterns; i++) {
       
        search(patterns[i], text, q);
    }

	return 0;
}
