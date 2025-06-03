#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>

char words[][15] = {
    "apple", "banana", "cherry", "dragon", "eagle", "falcon", "guitar", "hockey", "island", "jungle",
    "kitten", "lemon", "monkey", "nachos", "ocean", "python", "quartz", "rocket", "sunset", "turtle",
    "unicorn", "violet", "walrus", "xenon", "yellow", "zebra", "amber", "blaze", "cactus", "daisy",
    "ember", "frost", "glide", "hazel", "ivory", "jewel", "karma", "lunar", "mango", "noble",
    "olive", "pearl", "quest", "raven", "spike", "thief", "urban", "vivid", "whale", "xylem",
    "yacht", "zeal", "actor", "brave", "cabin", "depot", "elite", "fable", "giant", "habit",
    "ideal", "jaunt", "kneel", "latch", "mirth", "nudge", "orbit", "pride", "quail", "realm",
    "sheep", "tower", "ultra", "vixen", "woven", "xerox", "yield", "zesty", "angel", "beach",
    "creek", "dodge", "envoy", "flame", "grape", "harpy", "inbox", "joust", "koala", "liver",
    "moose", "ninja", "oxide", "piano", "quake", "risky", "snail", "tribe", "umbra", "vista"
};


//UTILITY FUNCTIONS
int create_menu(char title[], char options[][50], int, int);

//FUNCTIONS FOR GAMES

//TIC TAC TOE
void tic_tac_toe();
void print_board(char board[], int);
int take_player_input(char board[], int);
int check_winner(char board[]);

//HANGMAN
void hangman();
void print_guessed_word(char guessed_word[], int length);

int main(){
    char options[][50] = {
        "Tic-Tac-Toe", "Hangman", "Scissor-Paper-Rock"
    };
    int i = create_menu("Main Menu", options, 3, 2);
    char selected_game[50];

    strcpy(selected_game, options[i]);

    switch(i){
        case 0: 
            tic_tac_toe();
            break;
        case 1:
            hangman();
            break;
    }
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

void tic_tac_toe(){
    int turn = 0;
    char board[9] = {'.', '.', '.', '.', '.', '.', '.', '.', '.'};

    while (1){
        print_board(board, 0);
        int move = take_player_input(board, turn);
    }
}

int check_winner(char board[]){
    int win_conditions[][3] = {
        {0, 1, 2}, {0, 3, 6}, {0, 4, 8}, {1, 4, 7}, {2, 4, 6}, {3, 4, 5}, {2, 5, 8}, {6, 7, 8}
    };

    int i, j;
    for (i = 0; i < 8; i++){
        if (1){}
    }
    
}


int take_player_input(char board[], int turn){
    
    int move, valid = 0;

    while (!valid){
        if (turn % 2 == 0){
            printf("\nPlayer X: ");
        }
        else{
            printf("\nPlayer O: ");
        }
        scanf("%d", &move);
        if (board[move - 1] == '.') valid = 1;
    }
    
}

void print_board(char board[], int cursor){
    system("cls");

    printf("            Tic Tac Toe\n\n");
    printf("  %c              %c             %c\n\n\n", board[0], board[1], board[2]);
    printf("  %c              %c             %c\n\n\n", board[3], board[4], board[5]);
    printf("  %c              %c             %c\n", board[6], board[7], board[8]);
}

void hangman(){
    system("cls");
    printf("            Hangman\n\n");
    srand(time(NULL));
    char current_word[15];
    strcpy(current_word, words[rand() % 100]);

    int word_length = strlen(current_word);
    char guessed_word[word_length];

    for (int i = 0; i < word_length; i++) guessed_word[i] = '_';

    print_guessed_word(guessed_word, word_length);

}

void print_guessed_word(char guessed_word[], int length){
    for (int i = 0; i < length; i++){
        printf("%c ", guessed_word[i]);
    }
}