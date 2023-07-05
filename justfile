build:
    -mkdir bin
    gcc -Wall -std=c99 -o bin/ctodo src/*

run: build
    @echo ""
    @bin/ctodo
