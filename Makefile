CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

.PHONY: test
test:
	mkdir -p build
	$(CXX) $(CXXFLAGS) src/valve.cpp test/test_valve.cpp -o build/test_valve
	./build/test_valve
