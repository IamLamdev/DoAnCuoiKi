#include <iostream>
using namespace std;

bool isValidPlacement(char board[][9], int row, int col, char c) {
    //kiem tra hang co trung phan tu khong
    for(int i = 0; i < 9; i++)
        if(board[row][i] == c) return false;
    //kiem tra cot co trung phan tu khong
    for(int i = 0; i < 9; i++)
        if(board[i][col] == c) return false;
    //kiem tra trong khoi 3x3 co phan tu trung khong qua 9 toa do goc
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[row/3*3 + i][col/3*3 + j] == c)
                return false;
    return true;
}
    
bool solve(char board[][9]) {
    //Duyet het bang, tim cac phan tu trong ('.')
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            //Neu tim duoc phan tu '.', ta tim cach dien chu so vao o do
            if (board[i][j] == '.'){            
                // Lặp lại tất cả các số nguyên từ 1 đến 9 để điền vào
                // '1'+ k chuyen ve char
                for(int k = 0; k < 9; k++){
                    //Kiem tra dieu kien chen
                    if (isValidPlacement(board, i, j, k +'1')){
                        // Dien gia tri vao va tiep tuc backtracking
                        board[i][j] = '1'+ k;
                        if(solve(board))
                            //Tiep tuc tim kiem cau hinh cua phan tu tiep theo cho den khi dien
                            //tat ca cac o
                            return true;
                        else
                            // Neu chua duoc thi ta tim kiem mot gia tri khac
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
    
void solveSudoku(char board[][9]) {
    solve(board);
}

void printArray(char A[][9]) {
    for(int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    char A[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };
    solveSudoku(A);
    printArray(A);
    system("pause");
    return 0;
}