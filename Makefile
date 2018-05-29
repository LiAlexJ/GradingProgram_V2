

all: apps/computeSquaresApp apps/myGradingApp apps/countWordsApp

apps/countWordsApp : bin/countWords.o
	g++ bin/countWords.o -o apps/countWordsApp

apps/computeSquaresApp : bin/computeSquares.o
	g++ bin/computeSquares.o -o apps/computeSquaresApp

apps/myGradingApp : bin/gradeCalculator.o bin/grade.o bin/median.o bin/Student_info.o
	g++ bin/gradeCalculator.o bin/grade.o bin/median.o bin/Student_info.o -o apps/myGradingApp

bin/gradeCalculator.o : src/gradeCalculator.cpp
	g++ -o bin/gradeCalculator.o -c src/gradeCalculator.cpp

bin/grade.o : src/grade.cpp
	g++ -o bin/grade.o -c src/grade.cpp

bin/median.o : src/median.cpp
	g++ -o bin/median.o -c src/median.cpp

bin/Student_info.o : src/Student_info.cpp
	g++ -o bin/Student_info.o -c src/Student_info.cpp

bin/computeSquares.o : src/computeSquares.cpp
	g++ -o bin/computeSquares.o -c src/computeSquares.cpp

bin/countWords.o : src/readInput.cpp
	g++ -o bin/countWords.o -c src/readInput.cpp

clean:
	rm bin/* apps/*
