cd ..
make re
gcc -Wall -Wextra -Werror test/test1.c -o ft_printf_test -I./includes libftprintf.a
echo "\n\033[34mDebut de test \n\n\033[0m"
./ft_printf_test
rm ft_printf_test
echo "\n\033[31mFin de test \n\n\033[0m"
cd test
