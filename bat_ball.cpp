#include <iostream>
#include <ctime>
char tose();
char computor_tose();
std::string check(char user, char computor);
char computor_player();
int users_run();
int computors_run();
void check_winner(int player,int computor);

int main(){
    do{
        char user=tose();
        char computor=computor_tose();
        char player_choice;
        int user_run;
        int computor_run;
        std::string choice=check(user,computor);
        char again;
        
        if(choice=="true"){
            std::cout<<"choice the following\n";
            std::cout<<"**************************\n";
            std::cout<<"b for batting\n";
            std::cout<<"f for balling\n";
            std::cout<<"===================>";
            std::cin>>player_choice;

            switch(player_choice){
                case 'b':
                    user_run=users_run();
                    computor_run=computors_run();
                    break;
                case 'f':
                    computor_run=computors_run();
                    user_run=users_run();
                    break;

            }
        }
        else{
            std::cout<<"**************************\n";
            player_choice=computor_player();
            switch(player_choice){
                case 'b':std::cout<<"computor wants to BATT first\n";
                        computor_run=computors_run();
                        user_run=users_run();
                        break;
                case 'f':std::cout<<"computor wants to BALL \n";
                        user_run=users_run();
                        computor_run=computors_run();
                        break;
            }
        }
        check_winner(user_run,computor_run);
        do{
            std::cout<<"want to play agian\n";
            std::cout<<"if yes enter y\n";
            std::cout<<"if no enter n\n";
            std::cin>>again;
        }while(again!='y' && again!='n');
        if(again=='n'){
            break;
        }
    }while(true);
    
    return 0;
}
char  tose(){
    char choice;
    std::cout<<"Wellcome to the game \n";
    do{
        std::cout<<"******************************\n";
        std::cout<<"let's make a tose for selecting who well bat first \n";
        std::cout<<"Enter your choice\n";
        std::cout<<"o for odd \n";
        std::cout<<"e for eff \n";
        std::cout<<"===============>";
        std::cin>> choice;
    }while(choice!='o' && choice !='e');
    return choice;   
}
char computor_tose(){
    srand(time(0));
    int var=(rand() % 2)+1;
    switch(var){
        case 1:return 'o';
        case 2:return 'e';
    }
}
std::string check(char user,char computor){
    if(user == computor){
        std::cout<<"you win the tose\n";
        return "true";
    }
    else{
        std::cout<<"you lose the tose\n";
        return "false";
    }
}
char computor_player(){
    int choice;
    srand(time(0));
    choice=(rand() % 2)+1;
    switch(choice){
        case 1:return 'b';
        case 2: return 'f';
    }
}
int users_run(){
    int user;
    int computor;
    int run=0;
    std::cout<<"********************your batting is started********************\n";
    std::cout<<"enter anynumber bettween 0 to 6\n";
    do{
        std::cout<<"your choice ======>";
        std::cin>>user;
        if(user>=0 && user<=6){
            srand(time(0));
            computor=(rand() % 7);
            std::cout<<"computor's choice====>"<<computor<<'\n';
            if(user==computor){
                std::cout<<"you are out\n";
            }
            else{
                run=user+run;
            }
        }
        else{
            std::cout<<"enter the valid number btw 0 to 6\n";
        }
    }while(user!=computor);
    std::cout<<"your score"<<run<<"\n";
    return run;
}
int computors_run(){
    int user;
    int computor;
    int run=0;
    std::cout<<"********************your balling is started********************\n";
    std::cout<<"enter anynumber bettween 0 to 6\n";
    do{
        std::cout<<"your choice ======>";
        std::cin>>user;
        if(user>=0 && user<=6){
            srand(time(0));
            computor=(rand() % 7);
            std::cout<<"computor's choice====>"<<computor<<"\n";
            if(user==computor){
                std::cout<<"you are out\n";
            }
            else{
                run=computor+run;
            }
        }
        else{
            std::cout<<"enter the valid number btw 0 to 6\n";
        }
    }while(user!=computor);
    std::cout<<"computors score"<<run<<"\n";
    return run;
}
void check_winner(int user,int computor){
    if(user>computor){
        std::cout<<"******************YOU HAVE WIN THE GAME******************\n";
    }
    else if(computor>user){
        std::cout<<"******************YOU HAVE LOSE THE GAME******************\n";
    }
    else{
        std::cout<<"******************it's an tie******************\n";
    }
}