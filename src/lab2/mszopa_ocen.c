#define MOVE_LOST 0
#define MOVE_DECREASE_A 1
#define GAME_TYPE_USER 4

#include <stdio.h>
#include "gra.h"

typedef enum
{
    A = 0,
    B = 1
} Player;

void swap(int *a, int *b)
{
    int *c = a;
    a = b;
    b = c;
}

int nwd(int a, int b)
{
    if (a == 0 || b == 0)
    {
        return -1;
    }

    if (a < b)
    {
        swap(&a, &b);
    }
    do
    {

        int r = a % b;
        a = b;
        b = r;
    } while (b);

    return a;
}

int get_user_input(const char *message, int min, int max)
{
    int userInput = min - 1;
    do
    {
        printf("%s", message);
        scanf("%d", &userInput);
        printf("\33[2K\r");
    } while (userInput < min || userInput > max);

    return userInput;
}

int make_relative_primes(int *a, int *b)
{
    int d = nwd(*a, *b);
    if (d == -1)
    {
        return 0;
    }

    *a /= d;
    *b /= d;
    return 1;
}

void finalise_move(int *a, int *b, int moveType)
{
    if (moveType != MOVE_LOST)
    {
        if (moveType == MOVE_DECREASE_A)
        {
            --*a;
        }
        else
        {
            --*b;
        }

        make_relative_primes(a, b);
    }
}

int move_auto(int *a, int *b)
{
    int moveType = graj(*a, *b);
    finalise_move(a, b, moveType);
    return moveType;
}

int move_user(int *a, int *b)
{
    int moveType = get_user_input("Make a move (1 - decrease A, 2 - B): ", 1, 2);
    finalise_move(a, b, moveType);
    return moveType;
}

Player next_player(Player currentPlayer)
{
    if (currentPlayer == A)
    {
        return B;
    }
    return A;
}

char get_letter_for_player(Player player)
{
    return (char)(((int)player) + 'A');
}

Player play_auto(int a, int b)
{
    Player currentPlayer = A;
    while (move_auto(&a, &b))
    {
        if (currentPlayer == A)
        {
            printf("A");
        }
        else
        {
            printf("B");
        }
        printf(": (%d, %d)\n", a, b);

        currentPlayer = next_player(currentPlayer);
    }
    char loser = get_letter_for_player(currentPlayer);
    printf("\n%c lost :(\n", loser);

    Player winner = next_player(currentPlayer);
    return winner;
}

void play_with_user(int a, int b)
{
    Player currentPlayer = A;
    while (a > 1 || b > 1)
    {
        if (currentPlayer == A)
        {
            move_auto(&a, &b);
            printf("Computer");
        }
        else
        {
            if (a == 1 || b == 1)
            {
                move_auto(&a, &b);
                printf("You (auto)");
            }
            else
            {
                move_user(&a, &b);
                printf("You");
            }
        }
        printf(": (%d, %d)\n", a, b);

        currentPlayer = next_player(currentPlayer);
    }
    
    if(currentPlayer == A){
        printf("You won!\n");
    }
    else{
        printf("You lost :(\n");
    }
}

int main()
{
    int a;
    a = get_user_input("Enter first integer (> 1): ", 2, __INT_MAX__);

    int b;
    b = get_user_input("Enter second integer (> 1): ", 2, __INT_MAX__);

    int gameType = get_user_input("Choose desired game type (3 - auto, 4 - with your input): ", 3, 4);
    printf("The game starts now!\n");

    if (gameType == GAME_TYPE_USER)
    {
        play_with_user(a, b);
    }
    else
    {
        play_auto(a, b);
    }

    return 0;
}