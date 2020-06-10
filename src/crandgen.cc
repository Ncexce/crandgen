#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

int data[3];

void Readconftomemo(void);
int Randnumgen(int ar1, int ar2);
int Randnumgenm(int rres);
bool Checkflag(void);
void display_result(void);
void Route_1(void);
void Route_2(void);
int Recheck(int nres);

int main()
{
  Readconftomemo();
  if(Checkflag())
    {
      Route_1();
    }
  else
    {
      Route_2();
    }
}

void Route_1(void)
{
  int result;
  result=Randnumgenm(Randnumgen(1,53));
  display_result(result);
}

void Route_2(void)
{
  int result;
  result=Recheck(Randnumgen(1,53));
  display_result(result);
}

int Randnumgen(int ar1, int ar2)
{
  srand(time(0));
  return rand()%(ar2-ar1+1)+ar1;
}

int Randnumgenm(int rres)
{
  if(rres==data[1] || rres==8 || rres=17 ||rres==21)
    {
      return Randnumgenm(Randnumgen(1,53));
    }
  if(Randnumgen(rres,1000)%7==0)
    {
      return data[2];
    }
  else
    {
      return rres;
    }
}

int Recheck(int nres)
{
  if(nres==8 || nres==17 || nres==21) return Recheck(Randnumgen(1,53));
}

bool Checkflag(void)
{
  if (data[0]==0) return false;
  if (data[0]==1) return true;
  else throw new DivideByZeroException();
}

void display_result(int result)
{
  cout<"The lucky one is: ";
  cout<<result<<endl;
  system("pause");
}
void Readconftomemo(void)
{
  ifstream confi("crandfenc.dat", ios::binary);
  for(int i=0;i<3;i++)
    {
      confi.read(reinterpret_cast<int*>(&data[i]), sizeof(int));
    }
  confi.close();
}
