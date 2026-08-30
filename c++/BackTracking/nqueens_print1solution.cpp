#include <iostream>
#include <vector>


using namespace std;

void printBoard(vector<vector<char>> &board){
    for(int i = 0 ; i<board.size() ; i++){
        for(int j = 0 ; j<board[i].size() ; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout << "----------------\n" ; 
}

bool isSafe(vector<vector<char>> &board , int row , int col){
    // return true or false i.e whther we can place a queuen at this give n row and col 

    int n = board.size(); 
    // horizontal safety
    for(int j = 0 ; j<n ; j++){
        if(board[row][j] == 'Q'){
            return false; 
        }
    }

    // vertical safety 
    for(int i = 0 ; i<row ; i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }

    // left diagnol attack check 
    for(int i = row-1 , j = col-1 ; i>=0 && j>=0 ; i-- , j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    // right diagnol attack 
    for(int i = row-1 , j = col+1 ; i>=0 && j<n ; i-- , j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }   

    return true;

}

bool nQueens(vector<vector<char>> &board , int row){
    int n = board.size();
    if(row == n ){
        printBoard(board);
        return true;
    }

    // cols 
    for(int j = 0 ; j<n ; j++){
        if(isSafe(board , row , j)){
            // we place queen on each row coloumn wise
            board[row][j] = 'Q';
            if(nQueens(board , row+1)) // place next queen in next row {
            {
            
                return true;
            }

            board[row][j] = '.'; // remove the queen before trying next place  
        }
    }

    return false;
}

int main(){
    int N = 4; // 2X 2 chess booard
    vector<vector<char>> board; 

    // vector<vector<char>> board(2) then can access board[i] as it creates a vector of 2 elements which can each store a vectoir of char so can pushback 

    //  intialize to '.' empty board
    for(int i = 0 ; i<N ; i++){
        vector<char> newRow ;
        for(int j = 0 ; j<N ; j++){
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }

    // printBoard(board);

    nQueens(board , 0);
}

// https://chatgpt.com/c/6a941bd6-05a8-83ee-994b-e82036bfd9c5 