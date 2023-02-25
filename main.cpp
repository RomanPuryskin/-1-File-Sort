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

bool sortFile(const string fileName)
{
  
  ifstream file (fileName);
  ofstream file1 ("1.txt");
  ofstream file2 ("2.txt");
  if ( !file.is_open() || !file1.is_open() || !file2.is_open())
    return -1;
  int x,i;
  file>>x;
  while (file)
    {
      i=0;
      while(file && i<1)
        {
          file1<<x<<' ';
          file>>x;
          i++;
        }
      i=0;
      while(file && i<1)
        {
          file2<<x<<' ';
          file>>x;
          i++;
        }
    }
  file.close();
  file1.close();
  file2.close();
  return true;
}


int main()
{
  string fileName = "test.txt";
  createFileWithRandomNumbers(fileName,10,7);
  sortFile(fileName);
return 0;
}