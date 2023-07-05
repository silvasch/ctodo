#include "todo.h"

int main() {
    Todo *todo = createTodo("Learn maths");
    addTagToTodo(todo, "school");
    addTagToTodo(todo, "maths");
    addTagToTodo(todo, "important");
    removeTagFromTodo(todo, "maths");

    printTodo(todo);

    return 0;
}
