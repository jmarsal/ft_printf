mkdir diff_output
cd .. && clear
make re && sleep 1 && clear
# gcc -Wall -Wextra -Werror test/test1.c -o ft_printf_test -I./includes -L./ -lftprintf -I./libft/includes -L./libft -lft
# echo "\n\033[34mDebut de test \n\n\033[0m"
# ./ft_printf_test
# rm ft_printf_test
# echo "\n\033[31mFin de test \n\n\033[0m"
echo "<<<<<\t\ttest de conversions\t\t>>>>>\n"

# <<<< %s >>>>
clang -Wall -Wextra -Werror test/srcs/test_conversion_s.c -o t_conv_s
clang -Wall -Wextra -Werror test/srcs/ft_test_conversion_s.c -o ft_t_conv_s -I./includes -L./ -lftprintf -I./libft/includes -L./libft -lft
./t_conv_s > t_conv_s.txt
./ft_t_conv_s > ft_t_conv_s.txt
diff ./t_conv_s.txt ./ft_t_conv_s.txt | cat -e > test/diff_output/diff_conv_s.txt
rm t_conv_s ft_t_conv_s t_conv_s.txt ft_t_conv_s.txt

# <<<< %S >>>>
clang -Wall -Wextra -Werror test/srcs/test_conversion_S.c -o t_conv_S
clang -Wall -Wextra -Werror test/srcs/ft_test_conversion_S.c -o ft_t_conv_S -I./includes -L./ -lftprintf -I./libft/includes -L./libft -lft
./t_conv_S > t_conv_S.txt
./ft_t_conv_S > ft_t_conv_S.txt
diff ./t_conv_S.txt ./ft_t_conv_S.txt | cat -e > test/diff_output/diff_conv_S.txt
rm t_conv_S ft_t_conv_S t_conv_S.txt ft_t_conv_S.txt

# <<<< %p >>>>
clang -Wall -Wextra -Werror test/srcs/test_conversion_p.c -o t_conv_p
clang -Wall -Wextra -Werror test/srcs/ft_test_conversion_p.c -o ft_t_conv_p -I./includes -L./ -lftprintf -I./libft/includes -L./libft -lft
./t_conv_p > t_conv_p.txt
./ft_t_conv_p > ft_t_conv_p.txt
diff ./t_conv_p.txt ./ft_t_conv_p.txt | cat -e > test/diff_output/diff_conv_p.txt
rm t_conv_p ft_t_conv_p t_conv_p.txt ft_t_conv_p.txt

# <<<< %d %i >>>>
clang -Wall -Wextra -Werror test/srcs/test_conversion_d_i.c -o t_conv_d_i
clang -Wall -Wextra -Werror test/srcs/ft_test_conversion_d_i.c -o ft_t_conv_d_i -I./includes -L./ -lftprintf -I./libft/includes -L./libft -lft
./t_conv_d_i > t_conv_d_i.txt
./ft_t_conv_d_i > ft_t_conv_d_i.txt
diff ./t_conv_d_i.txt ./ft_t_conv_d_i.txt | cat -e > test/diff_output/diff_conv_d_i.txt
rm t_conv_d_i ft_t_conv_d_i t_conv_d_i.txt ft_t_conv_d_i.txt

# <<<< %D >>>>
clang -Wall -Wextra -Werror test/srcs/test_conversion_D.c -o t_conv_D
clang -Wall -Wextra -Werror test/srcs/ft_test_conversion_D.c -o ft_t_conv_D -I./includes -L./ -lftprintf -I./libft/includes -L./libft -lft
./t_conv_D > t_conv_D.txt
./ft_t_conv_D > ft_t_conv_D.txt
diff ./t_conv_D.txt ./ft_t_conv_D.txt | cat -e > test/diff_output/diff_conv_D.txt
rm t_conv_D ft_t_conv_D t_conv_D.txt ft_t_conv_D.txt

# <<<< %o >>>>
clang -Wall -Wextra -Werror test/srcs/test_conversion_o.c -o t_conv_o
clang -Wall -Wextra -Werror test/srcs/ft_test_conversion_o.c -o ft_t_conv_o -I./includes -L./ -lftprintf -I./libft/includes -L./libft -lft
./t_conv_o > t_conv_o.txt
./ft_t_conv_o > ft_t_conv_o.txt
diff ./t_conv_o.txt ./ft_t_conv_o.txt | cat -e > test/diff_output/diff_conv_o.txt
rm t_conv_o ft_t_conv_o t_conv_o.txt ft_t_conv_o.txt

# <<<< %O >>>>
clang -Wall -Wextra -Werror test/srcs/test_conversion_O.c -o t_conv_O
clang -Wall -Wextra -Werror test/srcs/ft_test_conversion_O.c -o ft_t_conv_O -I./includes -L./ -lftprintf -I./libft/includes -L./libft -lft
./t_conv_O > t_conv_O.txt
./ft_t_conv_O > ft_t_conv_O.txt
diff ./t_conv_O.txt ./ft_t_conv_O.txt | cat -e > test/diff_output/diff_conv_O.txt
rm t_conv_O ft_t_conv_O t_conv_O.txt ft_t_conv_O.txt

# <<<< %u >>>>
clang -Wall -Wextra -Werror test/srcs/test_conversion_u.c -o t_conv_u
clang -Wall -Wextra -Werror test/srcs/ft_test_conversion_u.c -o ft_t_conv_u -I./includes -L./ -lftprintf -I./libft/includes -L./libft -lft
./t_conv_u > t_conv_u.txt
./ft_t_conv_u > ft_t_conv_u.txt
diff ./t_conv_u.txt ./ft_t_conv_u.txt | cat -e > test/diff_output/diff_conv_u.txt
rm t_conv_u ft_t_conv_u t_conv_u.txt ft_t_conv_u.txt

# <<<< %U >>>>
clang -Wall -Wextra -Werror test/srcs/test_conversion_U.c -o t_conv_U
clang -Wall -Wextra -Werror test/srcs/ft_test_conversion_U.c -o ft_t_conv_U -I./includes -L./ -lftprintf -I./libft/includes -L./libft -lft
./t_conv_U > t_conv_U.txt
./ft_t_conv_U > ft_t_conv_U.txt
diff ./t_conv_U.txt ./ft_t_conv_U.txt | cat -e > test/diff_output/diff_conv_U.txt
rm t_conv_U ft_t_conv_U t_conv_U.txt ft_t_conv_U.txt

# <<<< %x ou %X >>>>
clang -Wall -Wextra -Werror test/srcs/test_conversion_x_X.c -o t_conv_x_X
clang -Wall -Wextra -Werror test/srcs/ft_test_conversion_x_X.c -o ft_t_conv_x_X -I./includes -L./ -lftprintf -I./libft/includes -L./libft -lft
./t_conv_x_X > t_conv_x_X.txt
./ft_t_conv_x_X > ft_t_conv_x_X.txt
diff ./t_conv_x_X.txt ./ft_t_conv_x_X.txt | cat -e > test/diff_output/diff_conv_x_X.txt
rm t_conv_x_X ft_t_conv_x_X t_conv_x_X.txt ft_t_conv_x_X.txt

# <<<< %c >>>>
clang -Wall -Wextra -Werror test/srcs/test_conversion_c.c -o t_conv_c
clang -Wall -Wextra -Werror test/srcs/ft_test_conversion_c.c -o ft_t_conv_c -I./includes -L./ -lftprintf -I./libft/includes -L./libft -lft
./t_conv_c > t_conv_c.txt
./ft_t_conv_c > ft_t_conv_c.txt
diff ./t_conv_c.txt ./ft_t_conv_c.txt | cat -e > test/diff_output/diff_conv_c.txt
rm t_conv_c ft_t_conv_c t_conv_c.txt ft_t_conv_c.txt

# <<<< %C >>>>
clang -Wall -Wextra -Werror test/srcs/test_conversion_C.c -o t_conv_C
clang -Wall -Wextra -Werror test/srcs/ft_test_conversion_C.c -o ft_t_conv_C -I./includes -L./ -lftprintf -I./libft/includes -L./libft -lft
./t_conv_C > t_conv_C.txt
./ft_t_conv_C > ft_t_conv_C.txt
diff ./t_conv_C.txt ./ft_t_conv_C.txt | cat -e > test/diff_output/diff_conv_C.txt
rm t_conv_C ft_t_conv_C t_conv_C.txt ft_t_conv_C.txt

# <<<< %b >>>>
clang -Wall -Wextra -Werror test/srcs/test_conversion_b.c -o t_conv_b
clang -Wall -Wextra -Werror test/srcs/ft_test_conversion_b.c -o ft_t_conv_b -I./includes -L./ -lftprintf -I./libft/includes -L./libft -lft
./t_conv_b > t_conv_b.txt
./ft_t_conv_b > ft_t_conv_b.txt
diff ./t_conv_b.txt ./ft_t_conv_b.txt | cat -e > test/diff_output/diff_conv_b.txt
rm t_conv_b ft_t_conv_b t_conv_b.txt ft_t_conv_b.txt

echo "Differences entre les deux fonctions testes sur les conversions...\n"
clang -Wall -Wextra -Werror test/srcs/diff.c -o diff -I./includes -L./ -lftprintf -I./libft/includes -L./libft -lft
./diff
rm diff
cd test
