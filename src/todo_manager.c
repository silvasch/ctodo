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

void removeTodoFromManager(TodoManager *todoManager, char *name) {
    Todo **new_todos = malloc(sizeof(Todo));
    int new_num_of_todos = 0;
    int removed_todo = 0;

    for (int i = 0; i < todoManager->num_of_todos; i++) {
        if (!strcmp(todoManager->todos[i]->name, name)) {
            removed_todo = 1;
        } else {
            new_todos[new_num_of_todos] = malloc(sizeof(Todo));
            memcpy(new_todos[new_num_of_todos], todoManager->todos[i], sizeof(Todo));
            new_num_of_todos += 1;
        }
    }

    if (removed_todo) {
        memcpy(todoManager->todos, new_todos, sizeof(Todo) * new_num_of_todos);
        todoManager->num_of_todos = new_num_of_todos;
    }
}

void printTodoManager(TodoManager *todoManager) {
    for (int i = 0; i < todoManager->num_of_todos; i++) {
        printTodo(todoManager->todos[i]);
    }
}
