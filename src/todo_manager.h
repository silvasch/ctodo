#include "todo.h"

typedef struct {
    char *name;

    Todo **todos;
    int num_of_todos;
} TodoManager;

TodoManager *createTodoManager(char *name);

void addTodoToManager(TodoManager *todoManager, Todo *todo);
void removeTodoFromManager(TodoManager *todoManager, char *name);

void printTodoManager(TodoManager *todoManager);
