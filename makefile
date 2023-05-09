all:compile run

compile:
	gcc -I ./include/ -o ./lib/Tactic.o -c ./src/Tactic.c
	gcc -I ./include/ -o ./lib/TacticA.o -c ./src/TacticA.c
	gcc -I ./include/ -o ./bin/Program ./lib/Tactic.o ./lib/TacticA.o ./src/Test.c	

run:
	./bin/Program