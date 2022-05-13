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

    srand (time(NULL));
    game_t *game = malloc(sizeof(game_t));
    game->text = malloc(sizeof(text_t));
    game->text->dices = my_str_to_word_array(load("dices/dice_0.txt"));
    game->text->YAMS = my_str_to_word_array(load("dices/YAMS.txt"));

    int a = get_random(6) + 1;
    int b = get_random(6) + 1;
    int c = get_random(6) + 1;
    int d = get_random(6) + 1;
    int e = get_random(6) + 1;

    int i = 0;
    int j = 0;
    char message[] = "Press space to roll the dices";
    initscr();
    curs_set(0);
    noecho();
    keypad(stdscr, true);


    start_color();

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);

    

    while (1) {
        refresh();
        erase();
        
        //game->text->dices[3][6] = i + 48;
        //game->text->dices[3][21] = i + 48;
        //game->text->dices[3][36] = i + 48;
        //game->text->dices[3][51] = i + 48;
        //game->text->dices[3][66] = i + 48;
//
        //if (j > 5) {
        //    game->text->dices[3][6] = a + 48;
        //    game->text->dices[3][21] = b + 48;
        //    game->text->dices[3][36] = c + 48;
        //    game->text->dices[3][51] = d + 48;
        //    game->text->dices[3][66] = e + 48;
//
        //}
        //attron(COLOR_GREEN);
        attron(COLOR_PAIR(2));
        my_put_tabw(game->text->YAMS);
        attron(COLOR_PAIR(1));
        my_put_tabw(game->text->dices);
        printw(message);

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
        //if(getch() != 410)
        //    break;
    }
    endwin();
    return 0;
}

void my_put_tabw(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; j != COLS / 2 - (my_strlen(tab[0])) / 2; j++) {
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
