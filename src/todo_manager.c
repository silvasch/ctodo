#include <stdlib.h>
#include <string.h>

#include "todo.h"
#include "todo_manager.h"

TodoManager *createTodoManager(char *name) {
    TodoManager *todoManager = malloc(sizeof(TodoManager));
    
    todoManager->name = malloc(strlen(name));
    strcpy(todoManager->name, name);

    todoManager->todos = malloc(sizeof(Todo));
    todoManager->num_of_todos = 0;

    return todoManager;
}

void addTodoToManager(TodoManager *todoManager, Todo *todo) {
     todoManager->todos[todoManager->num_of_todos] = malloc(sizeof(Todo));
     memcpy(todoManager->todos[todoManager->num_of_todos], todo, sizeof(Todo));
     todoManager->num_of_todos += 1;
}

void printTodoManager(TodoManager *todoManager) {
    for (int i = 0; i < todoManager->num_of_todos; i++) {
        printTodo(todoManager->todos[i]);
    }
}
