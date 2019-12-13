#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

//used this reference for time
//https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c

using namespace std;

//Quick Sort
void quickSort(int myArray[], int a, int b)
{
  if(a >= b)
  {
    return;
  }
  int pivot = myArray[b];
  int l = a; //scan right
  int r = b - 1; //scan left
  while(l <= r)
  {
    //find element larger than pivot
    while(l <= r && myArray[l] <= pivot)
    {
      l++;
    }
    //find element larger than pivot
    while(r >= l && myArray[r] >= pivot)
    {
      r--;
    }
    if(l < r)
    {
      //swapping s[l] and s[r]
      //store l
      int temp = myArray[l];
      int temp1 = myArray[r];
      myArray[l] = temp1;
      myArray[r] = temp;
    }
  }
  //swap elements at s[l] and s[b]
  int t1 = myArray[l];
  int t2 = myArray[b];
  myArray[l] = t2;
  myArray[b] = t1;
  //recursive calls
  quickSort(myArray, a, l-1);
  quickSort(myArray, l+1, b);
}

//selection sort
void selectionSort(int myArray[], int size)
{
  //time code was used from specific site
  auto start = std::chrono::system_clock::now();
  time_t start_time = std::chrono::system_clock::to_time_t(start);

  int i, j, minIndex, tmp;
  for(i = 0; i < size - 1; ++i)
  {
    minIndex = i;
    for(j = i + 1; j < size; ++j)
    {
      if(myArray[j] < myArray[minIndex])
      {
        minIndex = j;
      }
    }
    if(minIndex != i)
    {
      tmp = myArray[i];
      myArray[i] = myArray[minIndex];
      myArray[minIndex] = tmp;
    }
  }
  auto end = chrono::system_clock::now();

  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);

  cout << "Selection Sort finished at: " << ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s\n";
}
//bubble sort
void bubbleSort(int myArray[], int size)
{
  //time code was used from specific site
  auto start = std::chrono::system_clock::now();
  time_t start_time = std::chrono::system_clock::to_time_t(start);
  for(int i = 0; i < size; ++i)
  {
    int temp = 0;
    for(int j = 0; j < size - 1; ++j)
    {
      if(myArray[j] > myArray[j+1])
      {
        temp = myArray[j+1];
        myArray[j+1] = myArray[j];
        myArray[j] = temp;
      }
    }
  }
  auto end = std::chrono::system_clock::now();

  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);

  cout << "Bubble Sort finished at: " << ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s\n";
}
//insertion sort
void insertionSort(int myArray[], int size)
{
  //time code was used from specific site
  auto start = std::chrono::system_clock::now();
  time_t start_time = std::chrono::system_clock::to_time_t(start);
  for(int i = 1; i < size; ++i)
  {
    int temp = myArray[i];
    int k = i; //where to start shifting
    while(k > 0 && myArray[k-1] >= temp) //while the thing to the left is larger, shift
    {
      myArray[k] = myArray[k-1];
      --k;
    }
    myArray[k] = temp; //put marked item in the right spot
  }
  auto end = std::chrono::system_clock::now();

  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);

  cout << "Insertion Sort finished at: " << ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s\n";
}
//print array
void printArray(int myArray[], int size)
{
  cout << "The array sorted is: " << endl;
  for(int i = 0; i < size; ++i)
  {
    cout << myArray[i] << endl;
  }
}

//main method
int main(int argc, char const *argv[])
{
  string filename;
  if(argc != 2)
  {
    cout << "Please enter a file" << endl;
  }
  else
  {
    filename = argv[1];
    //cout << "The filename is: " << filename << endl;
  }
  //int myArray;
  //read in from file
  int counter = 0;
  int lineCount = 0;
  int size;
  string line;
  ifstream myfile(filename);
  //read initial size
  if(myfile.is_open())
  {
    while(getline(myfile,line))
    {
      // cout << line << endl;
      size = stoi(line);
      break;
      //run it once to get the size and then build the array accordingly
    }
  }
  //initialize array with size value
  int myArray[size];
  int myArray1[size];
  int myArray2[size];
  int myArray3[size];
  cout << "Size is: " << size << endl;
  //fill rest of array
  if(myfile.is_open())
  {
    while(getline(myfile,line))
    {
      //need to miss first line
      myArray[counter] = stoi(line);
      myArray1[counter] = stoi(line);
      myArray2[counter] = stoi(line);
      myArray3[counter] = stoi(line);
      counter++;
    }
    myfile.close();
  }


  insertionSort(myArray, size);
  bubbleSort(myArray1, size);
  selectionSort(myArray2, size);
  //time code was used from specific site
  auto start = std::chrono::system_clock::now();
  time_t start_time = std::chrono::system_clock::to_time_t(start);
  quickSort(myArray3, 0, size - 1);
  auto end = std::chrono::system_clock::now();

  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);

  cout << "Quick Sort finished at: " << ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s\n";
  //print out array
  // // printArray(myArray, size);
  // printArray(myArray2, size);
  // printArray(myArray1, size);


  return 0;
}
