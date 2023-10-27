#include <stdio.h>
#include <string.h>

int compare(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    int flag = -1;
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if(j==m){
            printf("Pattern found at index %d\n",i);
            flag = 1;
        }
    }
    return flag;
}

int main(int argc, char **argv) {
    char s[100], p[100];
    int status;

    printf("*** Naive String Matching Algorithm ***\n");
    printf("Enter the String.\n");
    scanf("%s",s);
    printf("Enter the pattern to match.\n");
    scanf("%s",p);
    
    int ans = compare(s, p);
      if(ans == -1){
        printf("String match not found \n");
      }
    return 0;
}