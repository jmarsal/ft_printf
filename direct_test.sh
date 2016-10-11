# clear && make debug
make debug
# clear
clang -o main main.c -I./includes -L./ -lftprintf
./main
