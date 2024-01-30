#include <stdio.h>
#include <string.h>


int main() {
    //board size input
    int n;
    scanf("%d",&n);

    //declare board
    char board[n][n];

    //initialize board
    for(int i = 0; i < n ; i++){
        for (int j = 0; j < n ; j++){
            board[i][j]='.';
        }
    }
    //number of words
    int words;
    scanf("%d",&words);

    for(int i = 0; i < words; i++){
        //initialize and scan words input
        int x; int y;
        char d;
        char s[50];
        scanf("%d %d %c %s",&x,&y,&d,s);

        //if horizontal word placement
        if(d=='H'){
            int charCount = 0;
            //move horizontally and place each character separately
            for(int j = x; j<x+strlen(s); j++){
                board[y][j]=s[charCount++];
            }
        }
        //if vertical word placement
        else if(d=='V'){
            int charCount = 0;
            //move vertically and place each character separately
            for(int j = y; j<y+strlen(s); j++){
                board[j][x]=s[charCount++];
            }
        }
    }
    int f;
    scanf("%d", &f);

    //output
    for(int i = 0; i < n ; i++){
        for (int j = 0; j < n ; j++){
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}
