all: hello

hello: hello.s
	gcc hello.s -o hello

hello.s: hello.bc
	llc hello.bc -o hello.s

hello.bc: hello.cpp
	clang -O0 -emit-llvm hello.cpp -c -o hello.bc
	llvm-dis < hello.bc > hello.ll

clean:
	rm hello hello.s hello.bc hello.ll
