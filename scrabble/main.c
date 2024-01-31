#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
    //number of words input
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

            //determine validity
            bool valid = false;
            if(i>0){
                //find if word is valid to be placed
                for(int j = x; j<x+strlen(s); j++){
                    //check if character is same (are crossing each other)
                    if(board[y][j]!='.' && board[y][j]==s[charCount]){
                        valid = true;
                        break;
                    }
                    charCount++;
                }
            }else{
                valid = true;
            }

            //check if crossing edge
            if((x+strlen(s)-1)>=n || valid==0){
                printf("Invalid word placement: (%d,%d) %c, %s\n", x,y,d,s);
                continue;
            }
            //move horizontally and place each character separately
            charCount=0;
            for(int j = x; j<x+strlen(s); j++){
                board[y][j]=s[charCount++];
            }
        }
        //if vertical word placement
        else if(d=='V'){
            int charCount = 0;
            bool valid = false;
            if(i>0){
                //find if word is valid to be placed
                for(int j = y; j<y+strlen(s); j++){
                    //check if character is same (are crossing each other)
                    if(board[j][x]!='.' && board[j][x]==s[charCount]){
                        valid = true;
                        break;
                    }
                    charCount++;
                }

            }else{
                valid = true;
            }

            //check if crossing edge
            if((y+strlen(s)-1)>=n || valid == 0){
                printf("Invalid word placement: (%d,%d) %c, %s\n", x,y,d,s);
                continue;
            }
            charCount = 0;
            //move vertically and place each character separately
            for(int j = y; j<y+strlen(s); j++){
                board[j][x]=s[charCount++];
            }
        }
    }

    //output
    for(int i = 0; i < n ; i++){
        for (int j = 0; j < n ; j++){
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    int f;
    scanf("%d", &f);

    for(int i=0; i<f; i++){
        int B; int A;
        char L;

        scanf("%d %c %d", &B, &L ,&A );

        for(int j = 0; j < n ; j++){
            for (int k = 0; k < n ; k++) {
                if(board[j][k]==L){

                    //check vertical
                    if(j-B>=0 && j+A<=n){
                        bool canPlace = true;
                        for(int checker=j-B; checker<=j+A; checker++){
                            if(checker==j){
                                continue; //avoid checking where char is present
                            }
                            if(board[checker][k]!='.'){
                                canPlace = false; break;
                            }
                        }
                        //print
                        if(canPlace==1){
                            printf("Place vertically at (%d,%d)\n",k,j);
                        }
                    }

                    //check horizontal
                    if(k-B>=0 && k+A<=n){
                        bool canPlace = true;
                        for(int checker=k-B; checker<=k+A; checker++){
                            if(checker==k){
                                continue; //avoid checking where char is present
                            }
                            if(board[j][checker]!='.'){
                                canPlace=false; break;
                            }
                        }
                        //print
                        if(canPlace==1){
                            printf("Place horizontally at (%d,%d)\n", k, j);
                        }
                    }
                }
            }
        }

    }
    return 0;
}