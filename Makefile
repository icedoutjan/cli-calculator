# Makefile für das Kompilieren von calc.cpp und main.cpp

# Compiler und Compiler-Flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -o3

# Ziel: tr (das ausführbare Programm)
tr: main.o calc.o
	$(CXX) $(CXXFLAGS) $^ -o $@

# Kompiliere main.cpp zu main.o
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Kompiliere calc.cpp zu calc.o
calc.o: calc.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Lösche alle erzeugten Dateien
clean: tr
	rm -f *.o
install: tr
	mkdir -p $(HOME)/.local/bin
	cp tr $(HOME)/.local/bin
