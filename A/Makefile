all: build

build: grammar/operation.cpp parser/parser.cpp string_util/string_util.cpp util/util.cpp main.cpp
	g++ $^ -o solve
run:
	./solve
clean:
	rm solve
