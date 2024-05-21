#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <random>
#include <iomanip> 
#include <string>

void intro();
void board_layout();
void user_board(int my_board[], int size);
void comp_board(int computor_board[]);
void show_comp_board(int computor_board[]);
bool check_number(int numbers[], int size, int element);
int random_number_generator(int computor[], int z);
int cross_maker(int array[], int size, int element, int flag);
void copyIntToStringArray(int* src, std::string* dest, int size);
int check_score(std::string spaces[]);

int main() {
    int my_board[25] = {0};
    int computor_board[25] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
    int random_generator[25] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
    int helper[25] = {0};
    int z = 0;
    int element;
    int size_my_board = sizeof(my_board) / sizeof(my_board[0]);
    int time_pass = 0;
    char choice;
    intro();
    board_layout();
    
    for (int i = 0; i < 25; i++) {
        do {
            std::cout << "Enter the " << i + 1 << " element ==>";
            std::cin >> element;
        } while (element < 1 || element > 25 || check_number(my_board, size_my_board, element));
        my_board[i] = element;
        user_board(my_board, size_my_board);
    }

    std::cout << "*****************************************************************************" << '\n';

    user_board(my_board, size_my_board);
    comp_board(computor_board); 

    do {
        if (time_pass % 2 == 0) {
            do {
                std::cout << "Enter the element you want to cancel: ";
                std::cin >> element;
            } while (check_number(helper, sizeof(helper) / sizeof(helper[0]), element));
        } else {
            do {
                element = random_number_generator(random_generator, z);
                z++;
            } while (check_number(helper, sizeof(helper) / sizeof(helper[0]), element));
            std::cout << "The element chosen by computer is " << element << "\n";
        }

        std::cout << "*********************************************************************************************************************" << '\n';
        std::cout << "                                                     YOUR BOARD                                                            " << "\n";
        int user_score = cross_maker(my_board, 25, element, 0);

       
        int comp_score = cross_maker(computor_board, 25, element, 1);
        
        if ((user_score == 5) || (comp_score == 5)) {
            if (user_score == 5) {
                std::cout << "********************************************************* You win the game *********************************************\n";
            } else {
                std::cout << "******************************************************** You lose the game *********************************************\n";
            }
            break;
        }
        
        helper[time_pass] = element;
        time_pass++;
        
    } while (true);
    std::cout << "*********************************************************************************************************************" << '\n';
    std::cout << "                                                     COMPUTER BOARD                                                            " << "\n";

    int over = cross_maker(computor_board, 25, 0, 2);
    std::cout << "*********************************************************************************************************************" << '\n';

    return 0;
}

void intro() {
    std::cout << "*************************************************" << '\n';
    std::cout << "*              Welcome to the BINGO             *" << '\n';
    std::cout << "*************************************************" << '\n';
    std::cout << "The board given below is the layout you have to fill the numbers between 1 to 25\n";
    std::cout << "randomly in the board\n";
    std::cout << "Then you have to say a number and make a cross in the board\n";
    std::cout << "The computer will say a number and you also have to make a cross in that number on your board\n";
    std::cout << "You have to continue this process until you make 5 rows crossed\n";
}

void board_layout() {
    std::cout << " _____________________________" << "\n";
    std::cout << "|     |     |     |     |     |" << "\n";
    std::cout << "|_____|_____|_____|_____|_____|" << "\n";
    std::cout << "|     |     |     |     |     |" << "\n";
    std::cout << "|_____|_____|_____|_____|_____|" << "\n";
    std::cout << "|     |     |     |     |     |" << "\n";
    std::cout << "|_____|_____|_____|_____|_____|" << "\n";
    std::cout << "|     |     |     |     |     |" << "\n";
    std::cout << "|_____|_____|_____|_____|_____|" << "\n";
    std::cout << "|     |     |     |     |     |" << "\n";
    std::cout << "|_____|_____|_____|_____|_____|" << "\n";
    std::cout << "                                                                 \n";
}

void user_board(int my_board[], int size) {
    std::cout << "                                                                 \n";
    std::cout << "       YOUR BOARD       " << "\n";
    std::cout << "                                                                 \n";
    std::cout << " _____________________________" << "\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "|";
        for (int j = 0; j < 5; ++j) {
            std::cout << std::setw(4) << my_board[i * 5 + j] << " |";
        }
        std::cout << "\n";
        std::cout << "|_____|_____|_____|_____|_____|\n";
    }
}

void show_comp_board(int computor_board[]) {
    std::cout << "                                                                 \n";
    std::cout << "       COMPUTER BOARD       " << "\n";
    std::cout << "                                                                 \n";
    std::cout << " _____________________________" << "\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "|";
        for (int j = 0; j < 5; ++j) {
            std::cout << std::setw(4) << computor_board[i * 5 + j] << " |";
        }
        std::cout << "\n";
        std::cout << "|_____|_____|_____|_____|_____|\n";
    }
}

void comp_board(int computor_board[]) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(computor_board, computor_board + 25, g);
}

bool check_number(int numbers[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (element == numbers[i]) {
            return true;
        }
    }
    return false;
}

int random_number_generator(int computor[], int z) {
    comp_board(computor);
    return computor[z];
}

int cross_maker(int array[], int size, int element, int flag) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == element) {
            array[i] = -1; 
        }
    }
    std::string printer_array[size];
    copyIntToStringArray(array, printer_array, size);
    if (flag == 0 || flag == 2) {
        std::cout << " _____________________________" << "\n";
        for (int i = 0; i < 5; ++i) {
            std::cout << "|";
            for (int j = 0; j < 5; ++j) {
                std::cout << std::setw(4) << printer_array[i * 5 + j] << " |";
            }
            std::cout << "\n";
            std::cout << "|_____|_____|_____|_____|_____|\n";
        }
        if (flag==2){
            return 0;
        }
    }
    int score = check_score(printer_array);
    return score;
}

void copyIntToStringArray(int* src, std::string* dest, int size) {
    for (int i = 0; i < size; ++i) {
        if (src[i] == -1) {
            dest[i] = "X";
        } else {
            dest[i] = std::to_string(src[i]);
        }
    }
}

int check_score(std::string spaces[]) {
    int score = 0;
    for (int i = 0; i < 5; i++) {
        if (spaces[i*5] == "X" && spaces[i*5+1] == "X" && spaces[i*5+2] == "X" && spaces[i*5+3] == "X" && spaces[i*5+4] == "X") {
            score++;
        }
        if (spaces[i] == "X" && spaces[i+5] == "X" && spaces[i+10] == "X" && spaces[i+15] == "X" && spaces[i+20] == "X") {
            score++;
        }
    }
    if (spaces[0] == "X" && spaces[6] == "X" && spaces[12] == "X" && spaces[18] == "X" && spaces[24] == "X") {
        score++;
    }
    if (spaces[4] == "X" && spaces[8] == "X" && spaces[12] == "X" && spaces[16] == "X" && spaces[20] == "X") {
        score++;
    }
    return score;
}
