/*
** EPITECH PROJECT, 2022
** YAMS
** File description:
** YAMS
*/

#include "file.h"

int game_loop(game_t *game)
{
    wrefresh(game->window->RIGHT);
    wrefresh(game->window->LEFT);
    werase(game->window->RIGHT);
    werase(game->window->LEFT);
    
    attron(COLOR_PAIR(1));
    box(game->window->RIGHT, 0, 0);
    box(game->window->LEFT, 0, 0);
    my_put_yam(game->window->LEFT,game->text->YAMS);
    my_put_dice(game->window->LEFT,game->text->dices);
    my_put_tabw(game->window->RIGHT,game->text->SCORE);
    my_put_score_tab(game->window->RIGHT,game->text->SCORE_TAB);
    char message[] = "Press space to roll the dices";

    box(game->window->RIGHT, 0, 0);
    box(game->window->LEFT, 0, 0);
    mvwprintw(game->window->LEFT, 0, 2, "%s", "YAMS");
    mvwprintw(game->window->RIGHT, 0, 2, "%s", "SCOREBOARD");
    mvwprintw(game->window->LEFT, 30, 20, "%s", message);


    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;

    int i = 0;
    int j = 0;
    int k = 0;


    if (getch() == ' ') {
        i = get_random(6) + 1;
        j = get_random(6) + 1;
        a = get_random(6) + 1;
        b = get_random(6) + 1;
        c = get_random(6) + 1;
        d = get_random(6) + 1;
        e = get_random(6) + 1;
    }
    game->text->dices[3][6] = a + 48;
    game->text->dices[3][21] = b + 48;
    game->text->dices[3][36] = c + 48;
    game->text->dices[3][51] = d + 48;
    game->text->dices[3][66] = e + 48;
    
    i++;
    
    if (i >= 9) {
        j++;
        i = 0;
    }      
    
    napms(5);
    // if(getch() != 410)
    //    break;
}