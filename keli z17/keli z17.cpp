#include <iostream>
using namespace std;

int module(int a) {
    if (a < 0) {
        return -a;
    }
    return a;

}
int main()
{
    //Z17 a*b=a+(a^2)(b^2)+b
    cout << " --------------------------------------------------------------------------------------";
    for(int a=0; a<17; a++)
    {
       
        cout << endl;
        cout << " | ";
        for(int b=0; b<17; b++)
        {
            int k = ((a * a) + a + (2 * b)) % 17;
            
          if(k<10)
          {
              cout << " ";
          }
          cout << k << " | ";

        }
        cout << endl;
        cout << " --------------------------------------------------------------------------------------";

    }
    cout << endl;



    system("pause");
}

