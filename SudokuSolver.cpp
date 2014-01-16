#include<iostream>
#include<cstdio>
using namespace std;

int arr[9][9];
bool gotIt[9][9];
int row,col;
 
//for no repetition in the column
bool rule1(int x,int y){
    bool flag = true;
    for(int a=0;a<9;a++){
        if(arr[x][y]==arr[a][y] && a!=x){
            flag=false;
            break;
        }
    }
    return flag;
}

//for no repetition in the row
bool rule2(int x,int y){
    bool flag = true;
    for(int a=0;a<9;a++){
        if(arr[x][y]==arr[x][a] && a!=y){
            flag=false;
            break;
        }
    }
    return flag;
}

//for no repetition in the box
bool rule3(int x, int y){
    int temp1 = (x/3);
    int temp2 = (y/3);
    bool flag = true;
    for(int a=0;a<3;a++){
        for(int b=0;b<3;b++){
            if(arr[a+(3*temp1)][b+(3*temp2)]==arr[x][y] && a+(3*temp1)!=x && b+(3*temp2)!=y){
                flag=false;
            }
        }
    }
    return flag;
}

bool findLocation(){
    for(int a=0;a<9;a++){
        for(int b=0;b<9;b++){
            if(gotIt[a][b]==false){
                //cout<<a<<" "<<b<<endl;
                row = a;
                col = b;
                return true;
            }
        }
    }
    return false;
}

bool solve(){
    int row = ::row;
    int col = ::col;
    //Finding the next location
    if(findLocation()==false)     return true;    //If full sudoku has been filled
    //Finding the no for the found location
    for(int a=1;a<=9;a++){
        arr[row][col] = a;
        if(rule1(row,col) && rule2(row,col) && rule3(row,col)){
            gotIt[row][col] = true;
            if(solve())     return true;           //solve next
        }
        //If doesn't match up
        gotIt[row][col] = false;
        arr[row][col] = 0;
    }
    return false;         //in case of no soln
}

int main(){
    printf("Enter the 9*9 sudoku with the empty tiles as 0.\n");
    row=0;
    col=0;
    //Input of sudoku and setting the pre-given elements as fixed
    for(int a=0;a<9;a++){
        for(int b=0;b<9;b++){
            scanf("%d", &arr[a][b]);
            gotIt[a][b] = true;
            if(arr[a][b]==0)    gotIt[a][b] = false;
        }
    }
    //initializing solve process
    if(solve()){
        //printing solved sudoku
        printf("Sudoku solved.\n");  
    } else {
        printf("Impossible to solve.\n");
    }
    printf("\n");
    for(int a=0;a<9;a++){
        for(int b=0;b<9;b++){
            printf("%d ", arr[a][b]);
        }
        printf("\n");
    }
#ifdef DEBUG
    system("pause>nul");
#endif
    return 0;
}
