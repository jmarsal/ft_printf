mkdir diff_output
cd .. && clear
make re && sleep 2 && clear
# gcc -Wall -Wextra -Werror test/test1.c -o ft_printf_test -I./libft/includes libft/libft.a -I./includes libftprintf.a
# echo "\n\033[34mDebut de test \n\n\033[0m"
# ./ft_printf_test
# rm ft_printf_test
# echo "\n\033[31mFin de test \n\n\033[0m"
echo "<<<<<\t\ttest de conversions\t\t>>>>>\n"

# <<<< %s >>>>
clang -Wall -Wextra -Werror test/srcs/test_conversion_s.c -o t_conv_s
clang -Wall -Wextra -Werror test/srcs/ft_test_conversion_s.c -o ft_t_conv_s -I./libft/includes libft/libft.a -I./includes libftprintf.a
./t_conv_s > t_conv_s.txt
./ft_t_conv_s > ft_t_conv_s.txt
diff ./t_conv_s.txt ./ft_t_conv_s.txt | cat -e > test/diff_output/diff_conv_s.txt
rm t_conv_s ft_t_conv_s t_conv_s.txt ft_t_conv_s.txt

# <<<< %S >>>>
clang -Wall -Wextra -Werror test/srcs/test_conversion_S.c -o t_conv_S
clang -Wall -Wextra -Werror test/srcs/ft_test_conversion_S.c -o ft_t_conv_S -I./libft/includes libft/libft.a -I./includes libftprintf.a
./t_conv_S > t_conv_S.txt
./ft_t_conv_S > ft_t_conv_S.txt
diff ./t_conv_S.txt ./ft_t_conv_S.txt | cat -e > test/diff_output/diff_conv_S.txt
rm t_conv_S ft_t_conv_S t_conv_S.txt ft_t_conv_S.txt

# <<<< %p >>>>
clang -Wall -Wextra -Werror test/srcs/test_conversion_p.c -o t_conv_p
clang -Wall -Wextra -Werror test/srcs/ft_test_conversion_p.c -o ft_t_conv_p -I./libft/includes libft/libft.a -I./includes libftprintf.a
./t_conv_p > t_conv_p.txt
./ft_t_conv_p > ft_t_conv_p.txt
diff ./t_conv_p.txt ./ft_t_conv_p.txt | cat -e > test/diff_output/diff_conv_p.txt
rm t_conv_p ft_t_conv_p t_conv_p.txt ft_t_conv_p.txt



cd test
echo "Differences entre les deux fonctions testes sur les conversions...\n"
clang -Wall -Wextra -Werror srcs/diff.c -o diff
./diff
rm diff
