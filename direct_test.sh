clear && make re
clear
clang -o main main.c -I./includes -L./ -lftprintf -I./libft/includes -L./libft -lft
./main | cat -e
