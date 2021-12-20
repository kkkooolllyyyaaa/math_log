all: build

build: string_util/string_util.cpp grammar/operation.cpp parser/Tree.cpp util/util.cpp parser/parser.cpp main.cpp
	g++ $^ -o solve
run:
	./solve
clean:
	rm solve
