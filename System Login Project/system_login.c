#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<string.h>

#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define AQUA "\033[1;36m"
#define WHITE "\033[1;37m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[0;33m"
#define PURPLE "\033[1;35m"

void login();
void signup();
void welcome();
void last_check();
void clear_line();
char* input_name();
char* input_password();
void loading_process();
void display_details();
void successfully_logined();

int choice;
char name[20], confirm_name[20], password[15], confirm_password[15], hint[25], key[15], ch, loading[] = {'\\', '|', '/', '-'};

int main() {
    system("cls");
    welcome();
choice:
    system("cls");
    printf("\n\n\t%s---------------------------------------------------------\n", BLUE);
    printf("\t|\t\t%sWELCOME TO SYSTEM LOGIN%s\t\t\t|\n", PURPLE, BLUE);
    printf("\t---------------------------------------------------------\n\n\n");
    printf("\t\t\t\t%s1 - SIGNUP\n\n\t\t\t\t2 - LOGIN%s", YELLOW, BLUE);
    printf("\n\n\t\tEnter your choice ( 1 / 2 ) :\t%s", AQUA);
    scanf("%d", &choice);
    switch(choice) {
    case 1:
        signup();
        system("cls");
        display_details();
        goto choice;
        break;
    case 2:
        if (name[0] == '\0' || password[0] == '\0') {
            printf("\n\n\t\t\t%sPlease sign up first.%s", RED, BLUE);
            Sleep(2000);
            goto choice;
        }
        login();
        break;
    default:
        system("cls");
        printf("\n\n\n\n\n\t\t%sEnter the correct choice 1 or 2", RED);
        Sleep(2000);
        goto choice;
    }
    printf("%s", YELLOW);
    loading_process();
    successfully_logined();
}

void login() {
    int count = 0;
    while(1) {
        system("cls");
        if(count > 2) {
            last_check();
            break;
        }
        printf("\n\n\t%s---------------------------------------------------------\n", BLUE);
        printf("\t|\t\t%sWELCOME TO SYSTEM LOGIN%s\t\t\t|\n", PURPLE, BLUE);
        printf("\t---------------------------------------------------------\n\n\n");
        strcpy(confirm_name, input_name());
        printf("\n\n");
        strcpy(confirm_password, input_password());
        if((!strcmp(name, confirm_name)) && (!strcmp(password, confirm_password))) {
            break;
        } else {
            ++count;
            printf("\n\n\t\t\t%sWRONG USER NAME OR WRONG PASSWORD\n\n\t\t\t\tTRY AGAIN\n\n\t\t\t\tATTEMPT : %d", RED, count);
            Sleep(3000);
        }
    }
}

void signup() {
    system("cls");
    printf("\n\n\t%s---------------------------------------------------------\n", BLUE);
    printf("\t|\t\t%sWELCOME TO SYSTEM SIGNUP%s\t\t|\n", PURPLE, BLUE);
    printf("\t---------------------------------------------------------\n\n\n");
    strcpy(name, input_name());
    printf("\n\n");
    strcpy(password, input_password());
    fflush(stdin);
    printf("\n\n\t\t%s( Hint : My pet name ? ) like this enter your customize Hint\n\t\t%sHint\t\t:  %s", YELLOW, BLUE, WHITE);
    fgets(hint, 25, stdin);
    hint[strlen(hint) - 1] = '\0';
    printf("\n\n\t\t%s( Key : jacky ) like this enter your Key\n\t\t%sKey\t\t:  %s", YELLOW, BLUE, WHITE);
    fgets(key, 15, stdin);
    key[strlen(key) - 1] = '\0';
}

void clear_line() {
    printf("\033[2K"); // Clear entire line
    printf("\033[0G"); // Move cursor to the beginning of the line
}

void loading_process() {
    printf("\n\n\n\t\t\t\tLoading...  ");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            printf("\b%c", loading[j]);
            Sleep(300);
        }
    }
}

void welcome() {
    printf("\n\n\n\n\n\n\n\t\t\t\t%s", GREEN);
    char intro[] = "WELCOME TO SYSTEM LOGIN";
    for(int i = 0; i < strlen(intro); i++) {
        printf("%c", intro[i]);
        Sleep(100);
    }
    Sleep(2000);
}

void display_details() {
    printf("\n\n\n\t\t\t\t%sSUCCESSFULLY SAVED%s\n\n\t\t\tName\t\t:\t%s\n\n\t\t\tPassword\t:\t%s\n\n", GREEN, BLUE, name, password);
    Sleep(3000);
}

void successfully_logined() {
    system("cls");
    printf("%s", GREEN);
    printf("\n\n\t\t\t***\tSUCCESSFULLY LOGIN\t***");
    printf("\n\n\t\t\t\t\t");
    for(int itr = 3; itr > 0; itr--) {
        printf("\b%d", itr);
        Sleep(1000);
    }
    system("cls");
    printf("\n\n\t\t\t***\tWELCOME TO SYSTEM\t***\n\n");
    system("color 7");
}

char* input_name() {
    static char NAME[20];
reenter:
    fflush(stdin);
    NAME[0] = '\0';
    printf("\t\tEnter User Name\t:  %s", WHITE);
    scanf("%[^\n]s", NAME);
    NAME[strlen(NAME)] = '\0';
    if(NAME[0] == '\n' || NAME[0] == ' ' || NAME[0] == '\0') {
        printf("\033[%dA", 1);
        clear_line();
        printf("%s\t\t\tName should be provided%s", RED, BLUE);
        Sleep(2000);
        clear_line();
        goto reenter;
    }
    return NAME;
}

char* input_password() {
    static char PASSWORD[15];
check:
    printf("\t\t%sEnter Password\t:  %s", BLUE, WHITE);
    int i = 0;
    PASSWORD[0] = '\0';
    while((ch = getch()) != 13 && i < 10) {
        if(ch == 8 && i >= 0) {
            printf("\b \b");
            i--;
            continue;
        } else if(ch == 32 || ch == ',' || ch == '.') {
            clear_line();
            printf("%s", RED);
            printf("\t--- Space \',\' \'.\' are not allowed, re-enter the password ---\t\t");
            Sleep(3000);
            clear_line();
            printf("%s", BLUE);
            goto check;
        }
        PASSWORD[i] = ch;
        i++;
        printf("%c", ch);
        Sleep(500);
        printf("\b*");
    }
    if(PASSWORD[0] == '\0') {
        clear_line();
        printf("%s\t\t\tPassword can't be empty%s", RED, BLUE);
        Sleep(2000);
        clear_line();
        goto check;
    }
    PASSWORD[i] = '\0';
    return PASSWORD;
}

void last_check() {
    fflush(stdin);
    char check_key[15];
    printf("\n\n\n\t\tHint\t:\t%s\n\n\t\tKey\t:\t", hint);
    scanf("%[^\n]s", check_key);
    check_key[strlen(check_key)] = '\0';
    if(!strcmp(key, check_key)) {
        successfully_logined();
        exit(1);
    } else {
        system("cls");
        printf("\n\n\n\t\t\t%sSystem Shutdown Automatically\n\n", RED);
        loading_process();
        system("cls");
        system("color 7");
        exit(1);
    }
}
