![sl1](https://github.com/user-attachments/assets/ca429a10-5e50-4c87-b516-e8b27e7438fb)
![sl2](https://github.com/user-attachments/assets/e84e5651-e8e0-4964-871e-ba98fa2f6603)
![sl3](https://github.com/user-attachments/assets/25d881b9-b857-4b3f-92a6-7838afd54d5c)

This project is a simple console-based login and signup system written in C. The program allows users to create an account (signup) and then log in using their credentials. It includes a variety of features such as input validation, user feedback, and a loading animation for better user experience. Here is a brief overview of the project's components:

## Project Overview

### Features

1. **Signup and Login Functionality**: 
   - Users can create an account by providing a username, password, hint, and key.
   - Users can log in with their username and password after signing up.

2. **Input Validation**:
   - Ensures that usernames and passwords are correctly entered.
   - Disallows certain characters in the password.
   - Validates non-empty inputs for username and password.

3. **User Feedback and Interaction**:
   - Displays messages to guide users through the signup and login processes.
   - Provides hints and keys for password recovery.

4. **Loading Animation**:
   - Displays a loading animation to enhance user experience.

5. **Colorful Output**:
   - Uses ANSI escape codes to display colored text in the console.

### Files and Functions

- **`main()`**: 
  - The entry point of the program. Displays the welcome message and provides options to either sign up or log in.

- **`welcome()`**: 
  - Displays a welcome message with a loading animation.

- **`signup()`**: 
  - Handles user registration. Collects username, password, hint, and key from the user.

- **`login()`**: 
  - Handles user login. Validates the entered username and password.

- **`input_name()` and `input_password()`**: 
  - Helper functions to securely collect the username and password from the user.

- **`loading_process()`**: 
  - Displays a loading animation.

- **`display_details()`**: 
  - Displays the details entered during signup.

- **`successfully_logined()`**: 
  - Displays a success message upon successful login.

- **`last_check()`**: 
  - Performs a final check using the hint and key in case of multiple failed login attempts.

### Usage

1. **Compile the Program**:
   - Use a C compiler like `gcc` to compile the program.
   ```
   gcc -o login_system login_system.c
   ```

2. **Run the Program**:
   - Execute the compiled binary to start the login system.
   ```
   ./login_system
   ```

3. **Signup**:
   - Follow the prompts to enter your username, password, hint, and key.

4. **Login**:
   - Enter your username and password to log in.

5. **Password Recovery**:
   - If you fail to log in multiple times, use the hint and key to recover access.

### Dependencies

- **Windows.h**: 
  - Required for using Windows-specific functions like `Sleep()`.
- **Conio.h**: 
  - Used for console input/output functions like `getch()`.

### Example

```
---------------------------------------------------------
|                WELCOME TO SYSTEM LOGIN                |
---------------------------------------------------------

                1 - SIGNUP

                2 - LOGIN

Enter your choice ( 1 / 2 ) :
```

This project can be further enhanced by adding features such as encryption for passwords, a more robust input validation mechanism, and improved error handling.
