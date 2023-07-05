build:
    -mkdir bin
    gcc -Wall -std=c99 -o bin/ctodo src/*.c

run: build
    @echo ""
    @bin/ctodo
