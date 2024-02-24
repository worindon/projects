

#include <iostream>
#include <vector>
#include <string>



using namespace std;

int n = 0;

vector < vector <int> > a(n, vector <int>(n));
vector < vector <int>  > matrix2;


void input_matrix(vector <vector <int>>& matrix, int n) {

    
       
        matrix[0][0] = 0;
        matrix[5][5] = 0;
  
}

void print_matrix(vector <vector <int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            cout << matrix[i][j] << " ";

        }
        cout << endl;
    }
}



bool qwest() {

    char i;
    do {
        scanf_s("%c", &i, sizeof(i));
    } while (!(i == 'Y' || i == 'N' || i=='y' ||i == 'n'));

    if (i == 'y' || i == 'Y') return 1;
    return 0;

}



int main()
{
    if (qwest()) {
        cout << endl<<12131231213;
  }

}

