#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <fstream> // Use this line to export data in a .txt file
using namespace std;

const int MAX = 8;
int main(){
int EndOfPath, z, Next;
int Distance;

// The Network Table has the data that the algorithm will use
int Network [MAX][MAX] = {};
Network [1][2] = 3;
Network [1][3] = 3;
Network [1][7] = 1;
Network [2][3] = 2;
Network [2][4] = 2;
Network [2][5] = 2;
Network [3][2] = 2;
Network [3][4] = 8;
Network [3][6] = 2;
Network [4][2] = 2;
Network [4][3] = 8;
Network [4][5] = 2;
Network [4][6] = 2;
Network [4][7] = 4;
Network [5][2] = 2;
Network [5][4] = 2;
Network [5][7] = 1;
Network [6][3] = 2;
Network [6][4] = 2;
Network [6][7] = 1;
Network [7][4] = 4;
Network [7][5] = 1;
Network [7][6] = 1;

////////////////////////////////////////////////////////////
//THIS PART'S PURPOSE IS TO EXPORT THE DATA IN A .TXT FILE
// OMMIT IT OTHERWISE
ofstream Data;
Data.open("C:\\Users\\silma\\Desktop\\Data.txt");
////////////////////////////////////////////////////////////

// Display the Network Table
cout << "The Network Table is: "<< endl;
for (int i = 1; i< MAX; i++){
    for (int j = 1; j<MAX; j++){
        cout << "__";
    }
    cout << endl;
    for (int j = 1; j<MAX; j++){
        cout << Network[i][j] << "|";
    }
    cout << endl;
}

for (int j = 1; j<MAX; j++){
        cout << "//////////";
    }
    cout << endl;
    cout << endl;
/////////////////////////////////////////////


for (int Iterations = 0; Iterations < 3; Iterations++){
int Table [MAX] [MAX] = {};
int Path [MAX-1] = {};
int Position = 1;
Path[0] = Position;
bool x = 0;
int Tzatziki;
// Algorithm
for (int i = 0; i<MAX-1; i++) {

    for (int j = 2; j<MAX; j++){
        if (Table [i][j] == 0){
            continue;
        }
        Table [i+1][j] = Table[i][j];
    }

    for (int j= 2; j<MAX; j++){
        if (Network[Position][j] == 0){
            continue;
        }
        else {
            if ((Network[Position][j]<Table[i+1][j]) | (Table[i][j] == 0)){
                Table[i+1][j] = Network[Position][j];
            }
        }
    }
    Tzatziki = 9;
    for (int j = 2; j<MAX; j++) {
        x = 0;
        if (Table[i+1][j] == 0){
            continue;
        }

        for (int Hi = 0; Hi< MAX-1; Hi++){
            if (j == Path[Hi]) {
                x = 1;
            }
        }
        if (x == 1){
            continue;
        }
        if (Table[i+1][j] <= Tzatziki){
            Next = j;
            Tzatziki = Table[i+1][j];
            continue;
        }
    }
    if (Tzatziki == 9){
        break;
    }
    Position = Next;
    Path[i+1] = Position;
}

//Display Output Table
cout << "This is the algorithm's table  for iteration " << Iterations+1 << " :" << endl;
Data << "This is the algorithm's table  for iteration " << Iterations+1 << " :" << endl;
for (int j = 1; j<MAX; j++){
        cout << "__";
        Data << "_______";
}
cout << endl;
Data << endl;
for (int i = 1; i< MAX; i++){
    for (int j = 1; j<MAX; j++){
        cout << Table[i][j] << "|";
        Data << Table[i][j] << "\t";
    }
    cout<< endl;
    for (int j = 1; j<MAX; j++){
        cout << "__";
    }
    cout << endl<< endl;
    Data << endl<< endl;
}
// Determine the path to Node 4
EndOfPath = Table[MAX-1][4];
for (int i = 1; i< MAX; i++){
    if (EndOfPath != Table[MAX-i-1][4]){
        z = MAX-i;
        break;
    }
    EndOfPath = Table[MAX-i-1][4];
}



/////////////////////////////////////////////////
Distance = 0;
cout << "The shortest path from Node 1 to Node 4 is: ";
Data << "The shortest path from Node 1 to Node 4 is: "; // THIS LINE EXPORTS DATA TO A .TXT FILE
for (int a = 0; a < z; a++){
    cout << Path[a] << "--> ";
    Data << Path[a] << "--> ";  // THIS LINE EXPORTS DATA TO A .TXT FILE
    if (a == (z-1)){
        Distance = Distance + Network [Path[a]][4];
        Network [Path[a]][4] = 0;
        Network [Path[4]][a] = 0;
        cout << "4" << endl;
        Data << "4" << endl;    // THIS LINE EXPORTS DATA TO A .TXT FILE
        break;
    }
    Distance = Distance + Network [Path[a]][Path[a+1]];
    Network [Path[a]][Path[a+1]] = 0;
    Network [Path[a+1]][Path[a]] = 0;
}
    cout << "The total distance is : "<< Distance <<endl << endl;
    Data << "The total distance is : "<< Distance <<endl << endl;



// Display the modified Network Table
cout << "The updated Network Table is : \n";
for (int i = 1; i< MAX; i++){
    for (int j = 1; j<MAX; j++){
        cout << "__";
    }
    cout << endl;
    for (int j = 1; j<MAX; j++){
        cout << Network[i][j] << "|";
    }
    cout << endl;
}

cout << endl<< endl;

}
    cout << "Done!!" << endl;
    return 0;
}

