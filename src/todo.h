typedef struct {
    char *name;
    int status; /* 0 = todo, 1 = in proress, 2 = done */

    char **tags;
    int num_of_tags;
} Todo;

Todo *createTodo(char *name);

void addTagToTodo(Todo *todo, char *tag);
void removeTagFromTodo(Todo *todo, char *tag);

void printTodo(Todo *todo);
