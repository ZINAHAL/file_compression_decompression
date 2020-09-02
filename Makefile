SRC_FILES = $(filter-out lex.yy.c, $(wildcard *.c))
#SRC_FILES = $(wildcard *.c)
HEADER_FILES = $(wildcard *.h)
OBJ_FILES = $(SRC_FILES:.c=.o)

# first the "get_frequencies_of_chars" program will be built and then the "main_prog" program
#all: get_frequencies_of_chars main_prog

#get_frequencies_of_chars: lex.yy.o cJSON.o
#	cc $^ -lfl -o $@

#lex.yy.o: lex.yy.c
#	gcc -c $<

#cJSON.o: cJSON/cJSON.c cJSON/cJSON.h
#	gcc -c $<

#lex.yy.c: ASCII_frequency_calculator.l
#	flex ASCII_frequency_calculator.l

main_prog: $(OBJ_FILES)
	gcc $^ -o $@

main.o: main.c $(HEADER_FILES)
	gcc -c $<

program_input_handler.o: program_input_handler.c program_input_handler.h
	gcc -c $<

priority_queue.o: priority_queue.c priority_queue.h
	gcc -c $<

huff_and_unhuff.o: huff_and_unhuff.c huff_and_unhuff.h priority_queue.h
	gcc -c $<

clean:
	rm *.o main_prog

#%.o: %.c %.h
#	gcc -c $<