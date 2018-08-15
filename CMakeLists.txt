cmake_minimum_required(VERSION 3.10)
project(Sudoku-Software-Project C)

set(CMAKE_C_STANDARD 90)
set(GCC_COVERAGE_COMPILE_FLAGS "-c -fmessage-length=0 –ansi -Wall -Wextra -Werror -pedantic-errors")

add_executable(sudoku main.c Solver.c Solver.h Game.c Game.h Parser.c Parser.h mainAux.c mainAux.h List.c List.h Exceptions.c Exceptions.h IO.c IO.h ParserTester.c ParserTester.h)