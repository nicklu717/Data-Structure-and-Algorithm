main.out: main.cpp
	g++ --std=c++17 main.cpp -o main.out

clean:
	rm main.out