#include <iostream>
#include <random>
#include <fstream>
using namespace std;
//Создание файла с рандомными числами
bool createFileWithRandomNumbers(const string &fileName, const int numbersCount,const int maxNumberValue)
{
  int mas[numbersCount];
  ofstream file(fileName);
  if(!file.is_open())
    return -1;
  for (int i=0;i<numbersCount;i++)
    {
      // используем возможности библиотеки рандом 
      mt19937 engine;
      random_device rd;
      engine.seed(rd());
      uniform_int_distribution<unsigned> distrib(0,maxNumberValue);
      mas[i] = distrib(engine);
      file<<mas[i]<<' ';
    }
  file.close();
  return true;
}

//Проверка файла на упорядоченность
bool isFileSorted(const string fileName)
{
  int temp, temp1;
  ifstream *file = new ifstream(fileName);
  if(!file->is_open())
    return -1;
  *file>>temp;
  while (*file)
    {
      *file>>temp1;
      if (temp1 < temp )
      {
        file->close();
        return false;
      }
      temp = temp1;
    }
  file->close();
  return true;
}

void sortFile(string fileName)
{
  
}


int main()
{
  string fileName = "test.txt";
  createFileWithRandomNumbers(fileName,3,7);
return 0;
}