CFLAGS=-W -Wall
SRC=$(wildcard *.c)

all: main

main: $(SRC:.c=.o)
	@echo "Criando arquivo executável: $@"
	@gcc -o $@ $^

%.o: %.c
	@echo "Compilando arquivo objeto: $@"
	@gcc -c $< $(CFLAGS) -o $@

clean:
	@echo "Limpando arquivos"
	-@rm -f *.o main *~

remade:
	$(MAKE) clean
	$(MAKE)

-include $(SRC:.c=.d)

%.d: %.c
	@gcc $< -MM -MT '$*.o $*.d ' -MD $(CFLAGS)