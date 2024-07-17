#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define row 10
#define col 10

#define UP 'u'
#define LEFT 'l'
#define DOWN 'd'
#define RIGHT 'r'

#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define AQUA "\033[1;36m"
#define WHITE "\033[1;37m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[0;33m"
#define PURPLE "\033[1;35m"

static int points,ball_x=6,ball_y=6;
char table[row][col], check;

void up();
void down();
void left();
void right();
void board();
void user_input();
void print_board();
void move_snake(int new_row, int new_col);
void increase_snake_length(int tail_x, int tail_y);
void place_food();

typedef struct s {
    int x, y;
    struct s *next;
} s;

s *head, *tail;

int main() {
    // Allocate memory for the linked list nodes
    head = malloc(sizeof(s));
    tail = malloc(sizeof(s));
    s *body = malloc(sizeof(s));

    // Check if memory allocation was successful
    if (head == NULL || tail == NULL || body == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize the linked list nodes
    head->x = 1;
    head->y = 3;
    head->next = body;
    
    body->x = 1;
    body->y = 2;
    body->next = tail;

    tail->x = 1;
    tail->y = 1;
    tail->next = NULL;

    system("color 7");
    board();
    system("cls");
    place_food();
    board();
    print_board();
    while (1) {
        user_input();
        print_board();
    }

    // Free the allocated memory
    s *current = head;
    while (current != NULL) {
        s *next = current->next;
        free(current);
        current = next;
    }
    printf("\n\n\t\t\t%sYour Score : %d\n%s",GREEN,points,WHITE);

    return 0;
}

void board() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == 0 || i == row-1 || j == 0 || j == row-1)
                table[i][j] = '*';
            else if(i==ball_x && j==ball_y)
                table[i][j]= 'o';
            else
                table[i][j] = ' ';
        }
    }
    
    s *current = head;
    while (current != NULL) {
        table[current->x][current->y] = '+';
        current = current->next;
    }
}

void print_board() {
    system("cls");
    printf("\n\t%s     SNAKE GAME\n\n\t", BLUE);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == 0 || i == row-1 || j == 0 || j == row-1)
                printf("%s", PURPLE);
            if (table[i][j] == '+')
                printf("%s", GREEN);
            if(i==head->x &&j==head->y)
                printf("%s",WHITE);
            if (table[i][j] == 'o')
                printf("%s", RED);
            printf("%c ", table[i][j]);
        }
        printf("\n\t");
    }
    printf("%s\n\n", WHITE);
}

void user_input() {
    printf("\t   %sr - RIGHT\n\t   l - LEFT\n\t   u - UP\n\t   d - DOWN\n\n\t%sEnter the Option : ", AQUA, YELLOW);
    check = getch();
    switch (check) {
        case RIGHT:
            right();
            break;
        case LEFT:
            left();
            break;
        case UP:
            up();
            break;
        case DOWN:
            down();
            break;
        default:
            printf("\t%sEnter the correct value", RED);
            Sleep(3000);
    }
}

void move_snake(int new_row, int new_col) {
    // Check if new position is within bounds
    if (new_row < 1 || new_row >= row - 1 || new_col < 1 || new_col >= col - 1) {
        printf("\n\n\t%sYou hit the wall! Game Over.\n", RED);
        printf("\n\n\t   %sYour Score : %d\n%s",GREEN,points,WHITE);
        Sleep(3000);
        exit(0);
    }

    // Check if the new position collides with the snake's body
    s *current = head;
    while (current != NULL) {
        if (current->x == new_row && current->y == new_col) {
            printf("\n\n\t%sYou hit yourself! Game Over.\n", RED);
           printf("\n\n\t   %sYour Score : %d\n%s",GREEN,points,WHITE);
            Sleep(3000);
            exit(0);
        }
        current = current->next;
    }

    // Check if the new position has food
    int food_eaten = (table[new_row][new_col] == 'o');

    // Move the snake
    current = head;
    int prev_x = current->x, prev_y = current->y;
    current->x = new_row;
    current->y = new_col;
    current = current->next;

    while (current != NULL) {
        int temp_x = current->x, temp_y = current->y;
        current->x = prev_x;
        current->y = prev_y;
        prev_x = temp_x;
        prev_y = temp_y;
        current = current->next;
    }

    // Increase the snake length if food is eaten
    if (food_eaten) {
        points++;
        increase_snake_length(prev_x, prev_y);
        table[new_row][new_col] = ' ';  // Remove the food from the board
        place_food();  // Place new food on the board
    }

    // Update the board
    board();
}

void increase_snake_length(int tail_x, int tail_y) {
    s *new_tail = malloc(sizeof(s));
    if (new_tail == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    new_tail->x = tail_x;
    new_tail->y = tail_y;
    new_tail->next = NULL;

    tail->next = new_tail;
    tail = new_tail;
}

void place_food() {
    int empty_cells[row * col][2];
    int empty_count = 0;

    // Collect all empty cells
    for (int i = 1; i < row - 1; i++) {
        for (int j = 1; j < col - 1; j++) {
            if (table[i][j] == ' ') {
                empty_cells[empty_count][0] = i;
                empty_cells[empty_count][1] = j;
                empty_count++;
            }
        }
    }

    // Place food on a random empty cell
    if (empty_count > 0) {
        int random_index = rand() % empty_count;
        int food_x = empty_cells[random_index][0];
        int food_y = empty_cells[random_index][1];
        table[food_x][food_y] = 'o';
        ball_x=food_x;ball_y=food_y;
    } else {
        printf("\n\n\t%sNo more empty space for food! You win!\n", YELLOW);
        printf("\n\n\t   Your Score : %d\n",points);
    }
}

void right() {
    move_snake(head->x, head->y + 1);
}

void left() {
    move_snake(head->x, head->y - 1);
}

void up() {
    move_snake(head->x - 1, head->y);
}

void down() {
    move_snake(head->x + 1, head->y);
}
