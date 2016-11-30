# clear && make debug
make debug
rm -rf test_direct
mkdir test_direct
cd test_direct

# clear
clang -o ret_ft_printf ../main_ft_printf.c -I../includes -L../ -lftprintf
clang -o ret_ft_asprintf ../main_ft_asprintf.c -I../includes -L../ -lftprintf
clang -o ret_ft_sprintf ../main_ft_sprintf.c -I../includes -L../ -lftprintf
clang -o ret_ft_dprintf ../main_ft_dprintf.c -I../includes -L../ -lftprintf
./ret_ft_printf
./ret_ft_asprintf
./ret_ft_sprintf
./ret_ft_dprintf
# cat ft_printf.txt | od -Ax > ft_printf.hex
cat printf.txt
# diff ./ft_printf.hex ./printf.hex > diff.hex
# echo "\033[34m< ft_printf\033[0m\n\033[31m> printf\033[0m\n"
# cat -e diff.hex
# echo "\n\033[34moutput ft_printf\033[0m"
# cat -e ft_printf.txt
# echo "\033[31moutput printf\033[0m"
# cat -e printf.txt
# echo "\n"

