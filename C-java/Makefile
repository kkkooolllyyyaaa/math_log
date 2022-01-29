all: build

build: grammar/*.java ExpressionParser.java AxiomChecker.java Main.java
	mkdir build
	javac -d build $^
run:
	java -classpath ./build Main
clean:
	rm -rf build
