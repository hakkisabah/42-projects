// C++ program to solve Rat in a Maze problem using
// backtracking
#include <stdio.h>
#include <stdbool.h>
// #include "so_long.h"
// Maze size
#define HEIGHT 6
#define WIDTH 14

bool solveMazeUtil(int maze[HEIGHT][WIDTH], int x, int y,int sol[HEIGHT][WIDTH]);

// A utility function to print solution matrix sol[HEIGHT][WIDTH]
void printSolution(int sol[HEIGHT][WIDTH])
{
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++)
			printf(" %d ", sol[i][j]);
		printf("\n");
	}
}

// A utility function to check if x, y is valid index for
// N*N maze
bool isSafe(int maze[HEIGHT][WIDTH], int x, int y)
{
	// if (x, y outside maze) return false
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && maze[x][y] == '0')
		return true;
	return false;
}

// This function solves the Maze problem using Backtracking.
// It mainly uses solveMazeUtil() to solve the problem. It
// returns false if no path is possible, otherwise return
// true and prints the path in the form of 1s. Please note
// that there may be more than one solutions, this function
// prints one of the feasible solutions.
bool solveMaze(int maze[HEIGHT][WIDTH])
{
	int sol[HEIGHT][WIDTH] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
	if (solveMazeUtil(maze, 1, 1, sol) == false) {
		printf("Solution doesn't exist");
		return false;
	}
	printSolution(sol);
	return true;
}

// A recursive utility function to solve Maze problem
bool solveMazeUtil(int maze[HEIGHT][WIDTH], int x, int y, int sol[HEIGHT][WIDTH])
{
	// if (x, y is goal) return true
	if (x == WIDTH - 1 && y == HEIGHT - 1 && maze[x][y] == 2) {
		sol[x][y] = 1;
		return true;
	}
	// Check if maze[x][y] is valid
	if (isSafe(maze, x, y) == true) {
		// Check if the current block is already part of
		// solution path.
		if (sol[x][y] == 1)
			return false;
		// mark x, y as part of solution path
		sol[x][y] = 1;
		/* Move forward in x direction */
		if (solveMazeUtil(maze, x + 1, y, sol) == true)
			return true;
		// If moving in x direction doesn't give solution
		// then Move down in y direction
		if (solveMazeUtil(maze, x, y + 1, sol) == true)
			return true;
		// If none of the above movements work then
		// BACKTRACK: unmark x, y as part of solution path
		sol[x][y] = 0;
		return false;
	}
	return false;
}

// void	find_path(char **map, int x, int y)
// {
// 	// 	int maze[HEIGHT][WIDTH] = { { 1, 0, 0, 0 },
// 	// 				{ 1, 1, 0, 1 },
// 	// 				{ 0, 1, 0, 0 },
// 	// 				{ 1, 1, 1, 2 } };
// 	// solveMaze(maze);
// 	solveMaze(map);
// 	return 0;
// }

// driver program to test above function
// int main()
// {
// 	int maze[HEIGHT][WIDTH] = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
// 								{ 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 2 },
// 								{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
// 								{ 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
// 								{ 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 } };
// 	solveMaze(maze);
// 	return 0;
// }

// This code is contributed by Aditya Kumar (adityakumar129)

