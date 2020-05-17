#include "TestCuda.h"
#include <QtWidgets/QApplication>
#include "cuda_runtime.h"
#include <iostream>
using namespace std;

vector<cudaDeviceProp> vecDeviceProps;

int main(int argc, char *argv[])
{
	cudaDeviceProp prop;
	int gpu_count = 0;
	cudaGetDeviceCount(&gpu_count);		//check the kernel's count 
	cout << "The total gpu number is:" << gpu_count << endl;
	for (int i = 0; i < gpu_count; i++)
	{
		if(cudaGetDeviceProperties(&prop,i)!=cudaSuccess) 
			continue;
		cout << "the No:" << i + 1 << endl;
		cout << "gpu_name: " << prop.name << endl;
		cout << "gpu total global memory: " << prop.totalGlobalMem/1024/1024 <<"MB"<< endl;
		cout << "gpu major: " << prop.major << endl << endl;;  // Major Compute Capablity Version
		if (prop.totalGlobalMem >= 2000000000)		   //2G
			vecDeviceProps.push_back(prop);
			
	}
	system("pause");
	return 0;
	//QApplication a(argc, argv);
	//TestCuda w;
	//w.show();
	//return a.exec();
}
