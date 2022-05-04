#include <iostream>
#include "Matrix.h"
using namespace std;
int main(){
   Matrix m1("m1.txt");
   Matrix m2("m2.txt");
   Matrix m3("m3.txt");
   cout << "--------------(M1)------------------" << endl;
   cout<<m1;
   cout << "------------(M2)--------------------" << endl ;
   cout<<m2;
   cout << "------------(M3)--------------------" << endl;
   cout <<m3;
   cout << "------------(M3)=(M3)---------------" << endl;
   m3  = m3;
   cout << "------------(M1==M1)----------------" << endl;
   cout<<((m1==m1)? "TRUE":"FALSE") << endl;
   cout << "------------(M1==M2)----------------" << endl;
   cout<<((m1==m2)? "TRUE":"FALSE") << endl;
   if(true){
       Matrix m4 = m1*m1[1][2];
       cout << "----------------(M4)----------------" << endl;
       cout << m4 << endl;
   }
   Matrix m5 = m1 + m2;
   cout << "---------------(M5)-----------------" << endl;
   cout << m5 << endl;
   cout << "-------------(M5-M2)----------------" << endl;
   cout << (m5 - m2);
   cout << "---------((M5-M2)*M3)---------------" << endl;
   cout << (m5 - m2)*m3;
   cout << "------------(M1*M3)-----------------" << endl;
   cout << m1*m3;
   cout << "------------(M3*M1)-----------------" << endl;
   cout << m3*m1;
   
   return 0;
}