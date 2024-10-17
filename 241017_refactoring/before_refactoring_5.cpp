#include <iostream>
#include <cmath>

using namespace std;
int main(int argc, char* argv[])
{ int d, s, m, g, y, c;
cout<<"vvedite daty dnja"<<endl;
cin>>d;
cout<<"vvedite 4islo mesjatsa"<<endl;
cin>>m;
cout<<"vvedite god"<<endl;
cin>>g;
y=g%100;
c=g/100;
s=(d+((13*m-1)/5)+(y/4)+(c/4)-2*c+777)%7;
if (s == 0)
cout<<"voskresenje"<<endl;
else if (s == 1)
cout<<"ponedelnik"<<endl;
else if (s == 2)
cout<<"vtornik"<<endl;
else if (s == 3)
cout<<"sreda"<<endl;
else if (s == 4)
cout<<"chetverg"<<endl;
else if (s == 5)
cout<<"pjatnitsa"<<endl;
else if (s == 6)
cout<<"subbota"<<endl;

system("pause");
return 0;
}
