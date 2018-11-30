# Compila o gerador.
gcc -o geraentrada -g geraentrada.c ext_sort.c util.c
# Executa o gerador.
./geraentrada
# Une dois arquivos de saída.
cat r0.txt r1.txt > ordtest_tmp.txt
# Ordena estes arquivos.
sort -n < ordtest_tmp.txt > ordtest.txt
# Remove o temporário.
rm ordtest_tmp.txt
# Compila o teste.
gcc -o main -g main.c ext_sort.c util.c
# Executa o teste.
./main
# Verifica se há diferenças.
DIFF=$(diff ordprog.txt ordtest.txt)
if [ "$DIFF" == "" ]; then
  echo "Os arquivos são iguais."
else
  echo "Os arquivos são diferentes."
fi
# Remove o teste.
rm ordtest.txt
