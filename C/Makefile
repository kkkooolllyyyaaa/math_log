all: build

build: string_util/string_util.cpp grammar/operation.cpp parser/Tree.cpp util/util.cpp parser/parser.cpp axiom/axiom.cpp deduction_theorem/deduction_processor.cpp main.cpp
	g++ -std=c++14 -O2 $^ -O2 -o solve
run:
	./solve
clean:
	rm solve
