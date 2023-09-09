#include <iostream>
#include <string>

using namespace std;

const int ROWS = 6;
const int COLUMNS = 7;

char board[COLUMNS][ROWS]; 

const char P1 = 'X';
const char P2 = 'O';
const char EMPTY = '-';

bool playerIsWinner(bool player);
void initializeTheBoard();
void displayTheBoard();
bool addAPiece(int col, bool isPlayer1);

int main() {
    char choice;
    if (choice == 'n' || choice == 'N'){
      return -1;
    }
    do{
    bool PlayerOne = true;
    bool gameWon = false;
    int totalMoves = 0;
    const int MAX_MOVES = ROWS * COLUMNS;

    initializeTheBoard();
    displayTheBoard();

   
    while ((totalMoves < MAX_MOVES) && (!gameWon)){
        bool validMove = false;
        int columnToPlay = 0;
        
        while (!validMove) {
            cout << "Player ";
            if (PlayerOne) {
                cout << "1";
            } else {
                cout << "2";
            }
            cout << " - Select a column (0-" << (COLUMNS-1) << ") to play: ";
            cin >> columnToPlay;
            validMove = addAPiece(columnToPlay, PlayerOne);
            if (!validMove) {
                cout << "Try again. Column full. " << endl;
            }
        }
        totalMoves++;
        displayTheBoard();
        gameWon = playerIsWinner(PlayerOne);
        if (!gameWon){
            PlayerOne = !PlayerOne;
        }
    }
    if (gameWon){
        cout << "Congratulations Player ";
        if (PlayerOne) {
            cout << "1";
        } else {
            cout << "2";
        }
        cout << ". You won Connect Four!!!! YAYYY!!!" << endl;
    }
    else if (totalMoves == MAX_MOVES){
        cout << "Game over! It is a tie." << endl;
    }
    cout << "Would you like to play again? (Y/N)" << endl; 
       cin >> choice;
   } while(choice =='Y' || choice == 'y');
}

bool playerIsWinner(bool player){
    char currentTile;
    if (player){
        currentTile = P1;
    }else{
        currentTile = P2;
    }
    
    for (int r = 0; r < ROWS; r++){
        
        int counterr = 0; 
        for (int c = 0; c < COLUMNS; c++){
            if(board[c][r] == currentTile){
                counterr++;
            }else {
                counterr = 0;
            }
            
            if (counterr == 4){
                return true;
            }
        }
    }
    
    for (int col = 0; col < COLUMNS; col++){
        int counterr = 0; 
        for (int row = 0; row < ROWS; row++){
            if(board[col][row] == currentTile){
                counterr++;
            }else{ 
                counterr = 0;
            }
            
            if (counterr == 4){
                return true; 
            }
        }
    }
    
    for (int row = 0; row < ROWS; row++){ 
        for (int col = 0; col < COLUMNS; col++){
            int counterr=0;
            
            for (int i=0;i<4;i++){
                if (board[col+i][row+i]==currentTile &&(row+i)<ROWS&&(col+i)<COLUMNS){
                    counterr=counterr+1;
                }
            }
            
            if (counterr==4){
                return true;
            }

        }
    }

    for (int row = 0; row < ROWS; row++){
        for (int col = 0; col < COLUMNS; col++){
            int counterr=0;
            
            for (int i=0;i<4;i++){ 
                if (board[col+i][row-i] == currentTile &&(row-i) > 0 &&(col+i) < COLUMNS)
                {
                    counterr=counterr+1;
                }
            }
            
            if (counterr==4)
            {
                return true;
            }

        }
    }
    return false;
}

void initializeTheBoard() {
  for (int col = 0; col < COLUMNS; col++) {
    for (int row = 0; row < ROWS; row++) {
        board[col][row] = EMPTY;
    }
  }
}

void displayTheBoard() {
  cout << endl <<  "Connect 4 Board:" << endl;
  
  for (int row = 0; row < ROWS; row++) {
    
    for (int col = 0; col < COLUMNS; col++){
      cout << board[col][row] << " ";
    }
   
    cout << endl;
  }
  for (int col = 0; col < COLUMNS; col++){
      cout << col << " ";
  }
  cout << endl << endl;
}

bool addAPiece(int col, bool isPlayer1){
  
  if (board[col][0] != EMPTY) {
    return false;
  } else {
    
    for (int row = (ROWS-1); row >= 0; row--){
        if (board[col][row] == EMPTY) {
          if (isPlayer1) {
            board[col][row] = P1;
          }
          else {
            board[col][row] = P2;
          }
          break;
        }
    }
    return true;
  }
}