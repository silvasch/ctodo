#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "todo.h"

Todo *createTodo(char *name) {
    Todo *todo = malloc(sizeof(Todo));

    todo->status = 0;

    todo->name = malloc(strlen(name));
    strcpy(todo->name, name);
   
    todo->tags = malloc(sizeof(char*));
    todo->num_of_tags = 0;

    return todo;
}

void addTagToTodo(Todo *todo, char *tag) {
    todo->tags[todo->num_of_tags] = malloc(strlen(tag));
    strcpy(todo->tags[todo->num_of_tags], tag);
    todo->num_of_tags += 1;
}

void removeTagFromTodo(Todo *todo, char *tag) {
    char **new_tags = malloc(sizeof(char*));
    int new_num_of_tags = 0;
    int removed_tag = 0;

    for (int i = 0; i < todo->num_of_tags; i++) {
        if (!strcmp(todo->tags[i], tag)) { // If is tag to be removed
            removed_tag = 1;
        } else {
            new_tags[new_num_of_tags] = malloc(strlen(todo->tags[i]));
            strcpy(new_tags[new_num_of_tags], todo->tags[i]);
            new_num_of_tags += 1;
        }
    }
    
    if (removed_tag) {
        strcpy(*todo->tags, *new_tags);
        todo->num_of_tags = new_num_of_tags;
    }
}

void printTodo(Todo *todo) {
    char status[12];
    switch (todo->status) {
        case 0:
            strcpy(status, "todo");
            break;
        case 1:
            strcpy(status, "in progress");
            break;
        case 2:
            strcpy(status, "done");
            break;
        default:
            strcpy(status, "");
    }

    printf("%s: %s (", todo->name, status);
    for (int i = 0; i < todo->num_of_tags; i++) {
        printf("%s", todo->tags[i]);
        if (i != todo->num_of_tags - 1) {
            printf(", ");
        }
    }
    printf(")\n");
}
