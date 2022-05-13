/*
** EPITECH PROJECT, 2022
** YAMS
** File description:
** YAMS
*/

#include "file.h"

int main(int ac, char **av)
{
    if (ac != 1)
        return 84;
    game_t *game = malloc(sizeof(game_t));
    game->text = malloc(sizeof(text_t));
    game->text->YAMS = load("YAMS");
    char **dice = my_str_to_word_array(load("dices/dice_0.txt"));
    char **YAMS = my_str_to_word_array(game->text->YAMS);


    int i = 0;
    initscr();
    curs_set(0);
    noecho();
    keypad(stdscr, true);
    while (1) {
        refresh();
        erase();
        
        dice[3][6] = i + 48;
        dice[3][21] = i + 48;
        dice[3][36] = i + 48;
        dice[3][51] = i + 48;
        dice[3][66] = i + 48;
        my_put_yams(YAMS);
        my_put_tabw(dice);
        my_put_tabw(dice);
        my_put_tabw(dice);
        my_put_tabw(dice);
        my_put_tabw(dice);
        

        i++;
        
        if (i >= 9)
            i = 0;
        
        napms(100);
        //if(getch() != 410)
        //    break;
    }
    endwin();
    return 0;
}

void my_put_tabw(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; j != COLS / 2 - 37; j++) {
            printw(" ");
        }
        printw("%s\n", tab[i]);
    }
}

void my_put_yams(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; j != COLS / 2 - 41; j++) {
            printw(" ");
        }
        printw("%s\n", tab[i]);
    }
}

void my_put_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        printf("%s\n", tab[i]);
}
