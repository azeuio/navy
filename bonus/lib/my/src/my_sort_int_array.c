/*
** EPITECH PROJECT, 2021
** sort int array
** File description:
** bubble sort
*/

#include "my.h"

void my_sort_int_array(int *array, int size)
{
    int temp;
    int has_changed;
    
    for (int i = 0; i < size; i++) {
        has_changed = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                has_changed = 1;
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
        if (!has_changed)
            break;
    }
}
