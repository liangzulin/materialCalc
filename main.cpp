#include <iostream>
#include <vector>    // For vector class

#include "readstress.h"
#include "readvolu.h"
#include "test1.h"

#define SIZE 256
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;



int main(int argc, char** argv) {
	runTest();
	
//	ofstream outpt("output11111.csv");// Out put file name 
//	for(int j=0;j<voluList.size();j++){
//		outpt<<setw(8)<<voluList.at(j)<<endl;
//	}
//	outpt.close();

	vector<float>* voluList;
	voluList = readVolufile("D:\\!CPP\\!DATAFILE\\666-element-volu-PRESOL.lis");
//	for(int i=0;i<4;i++){
//		cout<<"volu == "<<voluList->at(i)<<endl;
//	}	

	vector<float>* eleAvg;
	eleAvg = readfile("D:\\!CPP\\!DATAFILE\\gauss-element-stress-PRESOL.lis");
//	for(int i=0;i<4;i++){
//		cout<<"stress == "<<eleAvg->at(i)<<endl;
//	}
	
	
	
	// eleAvg, voluList
	cout<<"eleAvg="<<eleAvg->size()<<", voluList="<<voluList->size()<<endl;

	float force=0.0f;
	for(int i=0;i<voluList->size();i++){
		force += (eleAvg->at(i) * voluList->at(i));
	}
	
	float sumVolu=0.0f;
	for(int i=0;i<voluList->size();i++){
		sumVolu+=voluList->at(i);
	}
	
	float result = force / sumVolu;
	cout<<"result="<<result<<endl;
	
	return 0;
}











