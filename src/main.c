/*
** EPITECH PROJECT, 2022
** YAMS     
** YAMS
*/

#include "file.h"

int main(int ac, char **av)
{
    if (ac != 1)
        return 84;


    
    initscr();
    noecho();
    curs_set(0);

    game_t *game = malloc(sizeof(game_t));
    game->text = malloc(sizeof(text_t));
    game->window = malloc(sizeof(window_t));
    game->text->dices = my_str_to_word_array(load("dices/dice_0.txt"));
    game->text->YAMS = my_str_to_word_array(load("dices/YAMS.txt"));
    game->text->SCORE = my_str_to_word_array(load("dices/SCORE.txt"));
    game->text->SCORE_TAB = my_str_to_word_array(load("dices/SCORE_TAB.txt"));
    int Ymax, Xmax;

    game->window->LEFT = newwin(LINES, COLS / 2, 0, 0);
    game->window->RIGHT = newwin(LINES, COLS / 2, 0, COLS / 2);



    srand (time(NULL));

    int i = 0;
    int j = 0;
    //keypad(stdscr, true);


    start_color();

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);

    attron(COLOR_PAIR(1));

    mvwprintw(game->window->RIGHT, 0, 1, "YAMS");
    mvwprintw(game->window->LEFT, 0, 1, "SCOREBOARD");

    wrefresh(game->window->RIGHT);
    wrefresh(game->window->LEFT);

    getch();

    while (1) {
        game_loop(game);
    }
    endwin();
    return 0;
}

void my_put_yam(WINDOW *win, char **yam)
{   
    int x = 0;
    int y = 0;
    getmaxyx(win, y, x);
    for (int i = 0; yam[i] != NULL; i++) {
        mvwprintw(win, i + 1, x / 2 - my_strlen(yam[i]) / 2, yam[i]);
    }
}

void my_put_score_tab(WINDOW *win, char **yam)
{   
    int x = 0;
    int y = 0;
    getmaxyx(win, y, x);
    for (int i = 0; yam[i] != NULL; i++) {
        mvwprintw(win, i + 20, x / 2 - my_strlen(yam[i]) / 2, yam[i]);
    }
}

void my_put_dice(WINDOW *win, char **dice)
{
    int x = 0;
    int y = 0;
    getmaxyx(win, y, x);
    for (int i = 0; dice[i] != NULL; i++) {
        mvwprintw(win, i + 20, x / 2 - my_strlen(dice[i]) / 2, dice[i]);
    }
}

void my_put_tabw(WINDOW *win, char **tab)
{
    int x = 0;
    int y = 0;

    getmaxyx(win, y, x);
    for (int i = 0; tab[i] != NULL; i++) {
        mvwprintw(win, i + 1, x / 2 - my_strlen(tab[i]) / 2, "%s\n", tab[i]);
    }
}

void my_put_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        printf("%s\n", tab[i]);
}
