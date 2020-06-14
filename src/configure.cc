#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int tow[3];

void menu(void);
void Sequence1(void);
void Serialwrite(void);

int main()
{
  cout<<"Enable Cheating? :";
  cin>>tow[0];
  if(tow[0]==0)
    {
      Sequence1();
      return 0;
    }
  while(1)
    {
      cout<<endl<<"Input the disabled number: ";
      cin>>tow[1];
      if(tow[1]!=0) break;
    }
  while(1)
    {
      cout<<endl<<"Input the increased number: ";
      cin>>tow[2];
      if(tow[2]!=) break;
    }
  Serialwrite();
}

void menu(void)
{
  cout<<"*================*"<<endl;
  cout<<"| Configuration  |"<<endl;
  cout<<"*================*"<<endl;
  cout<<"\n\n";
}

void Sequence1(void);
{
  for (int 1=0;i<3;i++) tow[i]=0;
  SerialWrite();
}

void Serialwrite(void)
{
  ofstream confi("crandgenc.dat", ios::binary|ios::trunc);
  for(int i=0;i<3;i++) confi.write(reinterpret_cast<int*>(&tow[i]),sizeof(int));
  confi.close();
}
