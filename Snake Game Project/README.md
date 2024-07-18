![snakegame](https://github.com/user-attachments/assets/9402ecb5-7d92-4c45-a114-c58037f98881)

## Snake Game Project

This project is a console-based implementation of the classic Snake game written in C. It involves a dynamically growing snake that the player controls to collect food items, which increases the snake's length. The game ends when the snake collides with itself or the walls. Below is an overview of the project's features, file structure, and usage instructions.

### Features

1. **Game Board**:
   - A 10x10 grid representing the game area.
   - Walls are denoted by '*', the snake's body by '+', the snake's head by a bright white '+', and food by 'o'.
  
2. **Snake Movement**:
   - The snake can move up, down, left, or right based on user input.
   - The movement is controlled using the keys 'u' (up), 'd' (down), 'l' (left), and 'r' (right).

3. **Food Placement**:
   - Food appears randomly on the game board.
   - When the snake eats food, it grows in length and new food is placed on the board.

4. **Collision Detection**:
   - The game ends if the snake collides with itself or the walls.
   - Displays the player's score when the game ends.

5. **Dynamic Snake Growth**:
   - The snake's length increases dynamically as it consumes food.

6. **Colorful Output**:
   - Uses ANSI escape codes to display colored text in the console, enhancing the user experience.

### File Structure and Functions

#### Main File

The main file contains the following key components:

- **Global Variables**:
  - `points`: Tracks the player's score.
  - `ball_x` and `ball_y`: Track the position of the food.
  - `table[row][col]`: The game board array.
  - `check`: Stores the user's input for snake movement.

- **Linked List Structure**:
  - `typedef struct s { int x, y; struct s *next; } s;`
  - Used to represent the snake's body as a linked list.
  - `head`: Points to the head of the snake.
  - `tail`: Points to the tail of the snake.

- **Main Function**:
  - Initializes the game, including the snake and the game board.
  - Runs the game loop, which continuously takes user input and updates the game board.

#### Functions

- **`void board()`**:
  - Initializes and updates the game board, including placing the snake and the food.

- **`void print_board()`**:
  - Displays the game board in the console.

- **`void user_input()`**:
  - Takes user input to control the snake's movement.

- **`void move_snake(int new_row, int new_col)`**:
  - Moves the snake to a new position based on user input.
  - Checks for collisions and food consumption.

- **`void increase_snake_length(int tail_x, int tail_y)`**:
  - Increases the length of the snake by adding a new segment at the tail.

- **`void place_food()`**:
  - Places food at a random empty location on the game board.

- **Movement Functions (`void up()`, `void down()`, `void left()`, `void right()`)**:
  - Move the snake in the specified direction.

### Usage

1. **Compile the Program**:
   - Use a C compiler like `gcc` to compile the program.
   ```
   gcc -o snake_game snake_game.c
   ```

2. **Run the Program**:
   - Execute the compiled binary to start the game.
   ```
   ./snake_game
   ```

3. **Play the Game**:
   - Use 'u' for UP, 'd' for DOWN, 'l' for LEFT, and 'r' for RIGHT to control the snake.
   - The game will display your score when it ends.

### Example

```
     SNAKE GAME

* * * * * * * * * * 
* + + +           * 
*                 * 
*                 * 
*                 * 
*                 * 
*       o         * 
*                 * 
*                 * 
* * * * * * * * * * 

   r - RIGHT
   l - LEFT
   u - UP
   d - DOWN

Enter the Option : 
```

### Dependencies

- **Windows.h**: Required for using Windows-specific functions like `Sleep()`.
- **Conio.h**: Used for console input/output functions like `getch()`.

### Future Enhancements

- Implementing different difficulty levels by adjusting the speed of the snake.
- Adding a high score feature to track the best scores.
- Enhancing the game board to support larger sizes.
- Adding more obstacles or power-ups to make the game more challenging.
