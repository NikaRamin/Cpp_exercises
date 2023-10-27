#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct score{
    int win=0,lose=0,tie=0;
};

class game{
    private:
        char board[9];
        string playerOneName,playerTwoName;
        score playerOneScore,playerTwoScore;
    public:
        void setNameOne(string name){
            playerOneName = name;
        }
        void setNameTwo(string name){
            playerTwoName = name;
        }
        string getNameOne(){
            return playerOneName;
        }
        string getNameTwo(){
            return playerTwoName;
        }
        string turn(){
            srand(time(0));
            int randNum = (rand() % 2) + 1;
            if(randNum==1){
                return playerOneName;
            }
            return playerTwoName;
        }
        void printBoard(){
            for(int i = 0 ; i < 9 ; i++){
                cout<<"|"<<board[i]<<"|";
                if(i==2||i==5){
                    cout<<endl<<"---------"<<endl;
                }
            }
            cout<<endl;
        }
        void action(char act,int chosenNum){
            //becuse the array starts with 0
            chosenNum -= 1;
            if(board[chosenNum]=='x'||board[chosenNum]=='o'){
                cout<<"THIS CELL IS FULL!"<<endl;
                cout<<"Choose another cell:"<<endl;
                cin>>chosenNum;
                action(act,chosenNum);
                return;
            }
            board[chosenNum] = act;
        }
        void reset(){
            for(int i = 0 ; i < 9 ; i++){
                board[i] = ' ';
            }
        }
        int check(){
            int win = 0 , tie = 0;
            int i,j;
            char base;
            //check the rows
            for(i = 0 ; i < 9 ; i += 3){
                base = board[i];
                for(j = i ; j <= j+2 ; j++){
                    if(base == ' ') {
                        win = 0;
                        break;
                    }
                    if(board[j]==base){
                        win++;
                    }
                    else{
                        win = 0;
                        break;
                    }
                    if(win==3){
                        return 1;
                    }
                }
            }
            win=0;
            //check the columns
            for(i = 0 ; i <= 2 ; i++ ){
                base = board[i];
                for(j = i ; j <= j+6 ; j += 3){
                    if(base == ' ') {
                        win = 0;
                        break;
                    }
                    if(board[j]==base){
                        win++;
                    }
                    else{
                        win = 0;
                        break;
                    }
                    if(win==3){
                        return 1;
                    }
                }
            }
            win=0;
            //check 0,4,8
            i=0;
            base = board[i];
            for(i = 0 ; i < 9 ; i +=4){
                if(base == ' ') {
                    win = 0;
                    break;
                }
                if(board[i]==base){
                    win++;
                }
                else{
                    win = 0;
                    break;
                }
                if(win==3){
                    return 1;
                }
            }
            win=0;
            //check 2,4,6:
            i=2;
            base = board[i];
            for(i = 2 ; i < 7 ; i +=2){
                if(base == ' ') {
                    win = 0;
                    break;
                }
                if(board[i]==base){
                    win++;
                }
                else{
                    win = 0;
                    break;
                }
                if(win==3){
                    return 1;
                }
            }
            for(i = 0 ; i < 9 ; i++){
                if(board[i]=='o'||board[i]=='x'){
                    tie++;
                }
                else{
                    // -1 means the game isn't done
                    return -1;
                }
            }
            if(tie == 9) return 0; // It's a tie
        }
        void winScoreBoard(string winner){
            if(winner==playerOneName){
                playerOneScore.win++;
                playerTwoScore.lose++;
            }
            if(winner==playerTwoName){
                playerTwoScore.win++;
                playerOneScore.lose++;
            }
        }
        void tieScoreBoard(){
            playerOneScore.tie++;
            playerTwoScore.tie++;
        }
        void printScoreBoard(){
            cout<<playerOneName<<":"<<endl;
            cout<<"Win: "<<playerOneScore.win<<" Lose: "<<playerOneScore.lose<<" Tie: "<<playerOneScore.tie<<endl;
            cout<<playerTwoName<<":"<<endl;
            cout<<"Win: "<<playerTwoScore.win<<" Lose: "<<playerTwoScore.lose<<" Tie: "<<playerTwoScore.tie<<endl;
        }
};


int main(){
    string playerone,playertwo,turn1,turn2;
    int choice,rounds=0,status;
    game one;
    while(true){
        if(rounds==0){
            cout<<"Welcome to TicTacToe game!"<<endl<<"What's the name of player one?"<<endl;
            cin>>playerone;
            one.setNameOne(playerone);
            cout<<"What's the name of player two?"<<endl;
            cin>>playertwo;
            one.setNameTwo(playertwo);
        }
        rounds=0;
        turn1 = one.turn();
        if(turn1==playerone){
            turn2 = playertwo;
        }
        else{
            turn2 = playerone;
        }
        one.reset();
        while(rounds <= 9){
            cout<<turn1<<" You're up. you're x! "<<" Which cell number you pick? "<<endl;
            cin>>choice;
            one.action('x',choice);
            one.printBoard();
            status=one.check();
            if(status==1){
                cout<<turn1<<" WINS!"<<endl;
                one.winScoreBoard(turn1);
                break;
            }
            if(status==0){
            cout<<"It's a tie!"<<endl;
            one.tieScoreBoard();
            break;
            }
            cout<<turn2<<" Which cell number you pick? you're o! "<<endl;
            cin>>choice;
            one.action('o',choice);
            one.printBoard();
            status=one.check();
            if(status==1){
                cout<<turn2<<" WINS!"<<endl;
                one.winScoreBoard(turn2);
                break;
            }
            if(status==0){
            cout<<"It's a tie!"<<endl;
            one.tieScoreBoard();
            break;
            }
            rounds++;
        }
        cout<<"Do you wanna play another round?"<<endl<<"1.Yes\n2.No"<<endl;
        cin>>choice;
        if(choice==2){
            cout<<"Final results:"<<endl;
            one.printScoreBoard();
            cout<<"Thank you for playing this game!"<<endl;
            exit(0);
        }
    }
    return 0;
}