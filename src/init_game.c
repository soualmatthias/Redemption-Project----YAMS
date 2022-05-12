/*
** EPITECH PROJECT, 2022
** YAMS
** File description:
** YAMS
*/

#include "file.h"

int my_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

char *load(char *file)
{
    int fd = open(file, O_RDONLY);
    struct stat st;
    stat(file, &st);
    char *buffer = malloc(sizeof(char) * st.st_size + 1);
    read(fd, buffer, st.st_size);
    buffer[st.st_size] = '\0';
    close(fd);
    return buffer;
}

int get_y(char *buf)
{
    int index = 0;
    int y = 0;

    while (buf[index] != '\0')
    {
        if (buf[index] == '\n')
            y += 1;
        index += 1;
    }
    return y;
}

char **my_str_to_word_array(char *buff)
{
    int nbr_line = get_y(buff);
    char **tab = malloc(sizeof(char *) * (nbr_line + 1));
    int buf_index = 0;
    int line_index = 0;
    int char_index = 0;

    tab[line_index] = malloc(line_size(buff, buf_index));
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '\n') {
            line_index += 1;
            char_index = 0;
            i++;
            tab[line_index] = malloc(line_size(buff, i));
        }
        tab[line_index][char_index] = buff[i];
        char_index += 1;
    }
    tab[line_index] = NULL;
    return tab;
}

int line_size(char *line, int index)
{
    int size = 0;
    while (line[index] != '\n' && line[index] != '\0') {
        index += 1;
        size += 1;
    }
    return size;
}
    
