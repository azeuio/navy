/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** ll
*/

#ifndef LL_H_
#define LL_H_

struct ll {
    struct ll *next;
    int element;
};

typedef struct ll ll_t;

ll_t *ll_create(int element);
ll_t *ll_create_from_int_arr(int const *, int size);
int *ll_to_int_arr(ll_t *);
int get_ll_len(ll_t const *);
ll_t *ll_append(ll_t *ll, int element);
ll_t *ll_insert(ll_t *ll, int element, int index);
int ll_remove(ll_t *ll, int index);
int ll_cmp(ll_t *ll1, ll_t *ll2);
int ll_destroy(ll_t *ll);
void ll_print(ll_t *ll);
void print_exit_msg(void);

#endif
