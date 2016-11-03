mkdir diff_output
cd .. && clear
make debug && sleep 1 && clear
echo "<<<<<\t\ttest de conversions\t\t>>>>>\n"
echo "sortie avec printf    = <\n"
echo "sortie avec ft_printf = >\n"

# <<<< %s >>>>
clang -Wall -Wextra -Werror test/srcs/test_conversion_s.c -o t_conv_s
clang -Wall -Wextra -Werror test/srcs/ft_test_conversion_s.c -o ft_t_conv_s -I./includes -L./ -lftprintf
./t_conv_s > t_conv_s.txt
./ft_t_conv_s > ft_t_conv_s.txt
diff ./t_conv_s.txt ./ft_t_conv_s.txt | cat -e > test/diff_output/diff_conv_s.txt
rm t_conv_s ft_t_conv_s t_conv_s.txt ft_t_conv_s.txt

# <<<< %S >>>>
clang -Wall -Wextra -Werror test/srcs/test_conversion_ls.c -o t_conv_ls
clang -Wall -Wextra -Werror test/srcs/ft_test_conversion_ls.c -o ft_t_conv_ls -I./includes -L./ -lftprintf
./t_conv_ls > t_conv_ls.txt
./ft_t_conv_ls > ft_t_conv_ls.txt
diff ./t_conv_ls.txt ./ft_t_conv_ls.txt > test/diff_output/diff_conv_ls.txt
rm t_conv_ls ft_t_conv_ls t_conv_ls.txt ft_t_conv_ls.txt

# <<<< %p >>>>

# <<<< %d %i >>>>
clang -Wall -Wextra -Werror test/srcs/test_conversion_d_i.c -o t_conv_d_i
clang -Wall -Wextra -Werror test/srcs/ft_test_conversion_d_i.c -o ft_t_conv_d_i -I./includes -L./ -lftprintf
./t_conv_d_i > t_conv_d_i.txt
./ft_t_conv_d_i > ft_t_conv_d_i.txt
diff ./t_conv_d_i.txt ./ft_t_conv_d_i.txt | cat -e > test/diff_output/diff_conv_d_i.txt
rm t_conv_d_i ft_t_conv_d_i t_conv_d_i.txt ft_t_conv_d_i.txt

# <<<< %D >>>>
clang -Wall -Wextra -Werror test/srcs/test_conversion_D.c -o t_conv_D
clang -Wall -Wextra -Werror test/srcs/ft_test_conversion_D.c -o ft_t_conv_D -I./includes -L./ -lftprintf
./t_conv_D > t_conv_D.txt
./ft_t_conv_D > ft_t_conv_D.txt
diff ./t_conv_D.txt ./ft_t_conv_D.txt | cat -e > test/diff_output/diff_conv_D.txt
rm t_conv_D ft_t_conv_D t_conv_D.txt ft_t_conv_D.txt

# <<<< %o >>>>
clang -Wall -Wextra -Werror test/srcs/test_conversion_o.c -o t_conv_o
clang -Wall -Wextra -Werror test/srcs/ft_test_conversion_o.c -o ft_t_conv_o -I./includes -L./ -lftprintf
./t_conv_o > t_conv_o.txt
./ft_t_conv_o > ft_t_conv_o.txt
diff ./t_conv_o.txt ./ft_t_conv_o.txt | cat -e > test/diff_output/diff_conv_o.txt
rm t_conv_o ft_t_conv_o t_conv_o.txt ft_t_conv_o.txt

# <<<< %O >>>>
clang -Wall -Wextra -Werror test/srcs/test_conversion_lo.c -o t_conv_lo
clang -Wall -Wextra -Werror test/srcs/ft_test_conversion_lo.c -o ft_t_conv_lo -I./includes -L./ -lftprintf
./t_conv_lo > t_conv_lo.txt
./ft_t_conv_lo > ft_t_conv_lo.txt
diff ./t_conv_lo.txt ./ft_t_conv_lo.txt | cat -e > test/diff_output/diff_conv_lo.txt
rm t_conv_lo ft_t_conv_lo t_conv_lo.txt ft_t_conv_lo.txt

# <<<< %u >>>>
clang -Wall -Wextra -Werror test/srcs/test_conversion_u.c -o t_conv_u
clang -Wall -Wextra -Werror test/srcs/ft_test_conversion_u.c -o ft_t_conv_u -I./includes -L./ -lftprintf
./t_conv_u > t_conv_u.txt
./ft_t_conv_u > ft_t_conv_u.txt
diff ./t_conv_u.txt ./ft_t_conv_u.txt | cat -e > test/diff_output/diff_conv_u.txt
rm t_conv_u ft_t_conv_u t_conv_u.txt ft_t_conv_u.txt

# <<<< %U >>>>
clang -Wall -Wextra -Werror test/srcs/test_conversion_lu.c -o t_conv_lu
clang -Wall -Wextra -Werror test/srcs/ft_test_conversion_lu.c -o ft_t_conv_lu -I./includes -L./ -lftprintf
./t_conv_lu > t_conv_lu.txt
./ft_t_conv_lu > ft_t_conv_lu.txt
diff ./t_conv_lu.txt ./ft_t_conv_lu.txt | cat -e > test/diff_output/diff_conv_lu.txt
rm t_conv_lu ft_t_conv_lu t_conv_lu.txt ft_t_conv_lu.txt

# <<<< %x ou %X >>>>
clang -Wall -Wextra -Werror test/srcs/test_conversion_x_X.c -o t_conv_x_X
clang -Wall -Wextra -Werror test/srcs/ft_test_conversion_x_X.c -o ft_t_conv_x_X -I./includes -L./ -lftprintf
./t_conv_x_X > t_conv_x_X.txt
./ft_t_conv_x_X > ft_t_conv_x_X.txt
diff ./t_conv_x_X.txt ./ft_t_conv_x_X.txt | cat -e > test/diff_output/diff_conv_x_X.txt
rm t_conv_x_X ft_t_conv_x_X t_conv_x_X.txt ft_t_conv_x_X.txt

# <<<< %c >>>>
clang -Wall -Wextra -Werror test/srcs/test_conversion_c.c -o t_conv_c
clang -Wall -Wextra -Werror test/srcs/ft_test_conversion_c.c -o ft_t_conv_c -I./includes -L./ -lftprintf
./t_conv_c > t_conv_c.txt
./ft_t_conv_c > ft_t_conv_c.txt
diff ./t_conv_c.txt ./ft_t_conv_c.txt | cat -e > test/diff_output/diff_conv_c.txt
rm t_conv_c ft_t_conv_c t_conv_c.txt ft_t_conv_c.txt

# <<<< %C >>>>
clang -Wall -Wextra -Werror test/srcs/test_conversion_wC.c -o t_conv_wC
clang -Wall -Wextra -Werror test/srcs/ft_test_conversion_wC.c -o ft_t_conv_wC -I./includes -L./ -lftprintf
./t_conv_wC > t_conv_wC.txt
./ft_t_conv_wC > ft_t_conv_wC.txt
diff ./t_conv_wC.txt ./ft_t_conv_wC.txt > test/diff_output/diff_conv_wC.txt
rm t_conv_wC ft_t_conv_wC t_conv_wC.txt ft_t_conv_wC.txt

# <<<< %b >>>>
clang -Wall -Wextra -Werror test/srcs/test_conversion_b.c -o t_conv_b
clang -Wall -Wextra -Werror test/srcs/ft_test_conversion_b.c -o ft_t_conv_b -I./includes -L./ -lftprintf
./t_conv_b > t_conv_b.txt
./ft_t_conv_b > ft_t_conv_b.txt
diff ./t_conv_b.txt ./ft_t_conv_b.txt | cat -e > test/diff_output/diff_conv_b.txt
rm t_conv_b ft_t_conv_b t_conv_b.txt ft_t_conv_b.txt

echo "Differences entre les deux fonctions testes sur les conversions...\n"
clang -Wall -Wextra -Werror test/srcs/diff.c -o diff -I./includes -L./ -lftprintf
time ./diff
rm diff
cd test
