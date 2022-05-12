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

    typedef struct text_s {
        char *YAMS;
        char **dices;
    } text_t;

    typedef struct game_s {
        text_t *text;

    }game_t;

    char *load(char *file);
    void my_put_tab(char **tab);
    void my_put_tabw(char **tab);
    int get_y(char *buf);
    int line_size(char *line, int index);
    char **my_str_to_word_array(char *buff);
    char **load_dices(void);
    int my_strlen(char *str);


#endif
