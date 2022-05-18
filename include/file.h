/*
** EPITECH PROJECT, 2022
** file.h
** File description:
** .h of the project
*/

#ifndef H_
    #define H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <ncurses.h>
    #include <fcntl.h>
    #include <string.h>
    #include <time.h>

    typedef struct text_s {
        char **YAMS;
        char **SCORE;
        char **SCORE_TAB;
        char **dices;
    } text_t;

    typedef struct window_s {
        WINDOW *RIGHT;
        WINDOW *LEFT;
    } window_t;

    typedef struct game_s {
        text_t *text;
        window_t *window;

    }game_t;

    char *load(char *file);
    void my_put_tab(char **tab);
    void my_put_tabw(WINDOW *win, char **tab);
    void my_put_yams(char **tab);
    int get_y(char *buf);
    int line_size(char *line, int index);
    char **my_str_to_word_array(char *buff);
    char **load_dices(void);
    int my_strlen(char *str);
    int get_random(int max);
    int game_loop(game_t *game);

    void my_put_yam(WINDOW *win, char **yam);
    void my_put_dice(WINDOW *win, char **dice);
    void my_put_score_tab(WINDOW *win, char **yam);


#endif
