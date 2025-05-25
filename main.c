#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

int create_menu(char title[], char options[][50], int, int);

int main(){
    char options[][50] = {
        "Tic-Tac-Toe", "Hangman", "Scissor-Paper-Rock"
    };
    int i = create_menu("Main Menu", options, 3, 2);
    char selected_game[50];

    strcpy(selected_game, options[i]);
    printf("%s", selected_game);
    return 0;
}

int create_menu(char title[30], char options[][50], int n, int spacing){
    int cursor = 0;
    char input = ' ';
    while (1){
        system("cls");
        int i, j;
        printf("%s\n\n", title);
        for (i = 0; i < n; i++){
            printf("%d. %s", i + 1, options[i]);
            if (cursor == i) printf("   < < <");
            for (j = 0; j < spacing; j++) printf("\n");
        }
        input = getch();

        if (input == 's'){
            cursor += 1;
        } 
        else if (input == 'w'){
            cursor -= 1;
        }
        else if (input == 13){
            return cursor;
        }

        if (cursor < 0) cursor = 0;
        if (cursor > n - 1) cursor = n - 1;
        
    }
}