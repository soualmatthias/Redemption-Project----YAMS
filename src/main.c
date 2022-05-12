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

    puts(load("YAMS"));

    my_put_tab(dice);
    initscr();
    curs_set(0);
    noecho();
    keypad(stdscr, true);
    while (1) {
        printw("%s", game->text->YAMS);
        my_put_tabw(dice);
        
        refresh();
        if(getch() != 410)
            break;
    }
    endwin();
    return 0;
}

void my_put_tabw(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        printw("%s\n", tab[i]);
}

void my_put_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        printf("%s\n", tab[i]);
}
