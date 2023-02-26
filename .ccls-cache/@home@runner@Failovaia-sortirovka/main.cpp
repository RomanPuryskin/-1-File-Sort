#include <iostream>
#include <random>
#include <fstream>
using namespace std;
//-----------------Функции----------------//


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
bool isFileSorted(const string &fileName)
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



//Функция слияния файлов
bool mixFiles(const string &fileName1, const string &fileName2, const string &fileName3, const string &fileName4, int p)
{
  int x,y,i,j;
  ifstream file1(fileName1);
  ifstream file2(fileName2);
  ofstream filesToWrite[2]= {ofstream (fileName3), ofstream(fileName4)}; // сюда будем записывать числа
  if ( !file1.is_open() || !file2.is_open())
    return -1;
  for (j =0; j<2; j++)
    {
      if(!filesToWrite[j].is_open())
        return -1;
    }
  file1>>x;
  file2>>y;
  int n=0;
  while(file1 && file2)
    {
      i=j=0;
      while (file1 && file2 && i<p && j<p)
        {
          if (x<y)
          {
            filesToWrite[n]<<x<<' ';
            file1>>x;
            i++;
          }
          else
          {
            filesToWrite[n]<<y<<' ';
            file2>>y;
            j++;
          }
        }

      while (file1 && i<p)
        {
          filesToWrite[n]<<x<<' ';
          file1>>x;
          i++;
        }
      while(file2 && j<p)
        {
          filesToWrite[n]<<y<<' ';
          file2>>y;
          j++;
        }
      n=1-n;
    }

  while (file1)
    {
      filesToWrite[n]<<x<<' ';
      file1>>x;
    }
  while (file2)
    {
      filesToWrite[n]<<y<<' ';
      file2>>y;
    }
return true;
fcloseall();
}



//Реализация сортировки
bool sortFile(const string &fileName)
{
  
  ifstream file (fileName);
  ofstream file1 ("1.txt");
  ofstream file2 ("2.txt");
  if ( !file.is_open() || !file1.is_open() || !file2.is_open())
    return -1;
  int x,i;
  // сначала 
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
  fcloseall();
  return true;
}




int main()
{
  string fileName = "test.txt";
  createFileWithRandomNumbers(fileName,10,7);
  sortFile(fileName);
return 0;
}