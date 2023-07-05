#include "todo.h"
#include "todo_manager.h"

int main() {
    Todo *todoOne = createTodo("Learn maths");
    addTagToTodo(todoOne, "school");
    addTagToTodo(todoOne, "maths");

    Todo *todoTwo = createTodo("Learn english");
    addTagToTodo(todoTwo, "school");
    addTagToTodo(todoTwo, "english");

    Todo *todoThree = createTodo("Learn french");
    addTagToTodo(todoThree, "school");
    addTagToTodo(todoThree, "french");

    TodoManager *todoManager = createTodoManager("Todos");
    addTodoToManager(todoManager, todoOne);
    addTodoToManager(todoManager, todoTwo);
    addTodoToManager(todoManager, todoThree);

    printTodoManager(todoManager);
  
    return 0;
}
