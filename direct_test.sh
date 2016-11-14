# clear && make debug
make debug
echo "Suppression du repertoire test_direct"
rm -rf test_direct
echo "Creation du repertoire test_direct"
mkdir test_direct
echo "Go dans le repertoire"
pwd
cd test_direct
pwd


# clear
clang -o ret_ft_printf ../main_ft_printf.c -I../includes -L../ -lftprintf
./ret_ft_printf && clear
cat ft_printf.txt | od -Ax > ft_printf.hex
cat printf.txt | od -Ax > printf.hex
diff ./ft_printf.hex ./printf.hex > diff.hex
cat -e diff.hex
diff ./ft_printf.txt ./printf.txt > diff.txt
cat -e diff.txt
# cd .. && rm -rf test_direct

