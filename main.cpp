#include <iostream>
#include <fstream>   // For file reading
#include <string.h>    // For string class
#include <vector>    // For vector class
#include <iomanip> // For format control 
#include <stdio.h>

#include "readstress.h"

#define SIZE 256
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;



int main(int argc, char** argv) {
	ifstream input("D:\\!CPP\\!DATAFILE\\666-element-volu-PRESOL.lis",ios::in);
	string name;
	char str[SIZE];
	vector<float> voluList(0);
	
	
	string headstr("    ELEM");
	while (!input.eof()){
		input.getline(str,SIZE);
		bool isfound = isHead(str, &headstr);
		if(isfound){
			float volu=0.0f;
			for(int j=0;j<41;j++){// 39
				input.getline(str,SIZE);
//				cout<<"strlen=="<<strlen(str)<<";____"<<str<<endl;
//				system("pause");
				if(strlen(str)<10){
					break;
				}else{
					char b[12];
					strncpy(b, str+10, 11);
//		     		cout<<b<<endl;
					float tmp;
					sscanf(b, "%f", &tmp);//把char写入到浮点类型定义的tmp里面
					
					volu=tmp; //element对应Volu值
					voluList.push_back(volu);
				}
				
			}
			
		}
//		system("pause");
	}
	
	
	for(int i=0;i<4;i++){
		cout<<"volu == "<<voluList.at(i)<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
//	ofstream outpt("output11111.csv");// Out put file name 
//	for(int j=0;j<voluList.size();j++){
//		outpt<<setw(8)<<voluList.at(j)<<endl;
//	}
//	outpt.close();












	vector<float>* eleAvg;
	eleAvg = readfile("D:\\!CPP\\!DATAFILE\\gauss-element-stress-PRESOL.lis");
	for(int i=0;i<4;i++){
		cout<<"stress == "<<eleAvg->at(i)<<endl;
	}
	
	// eleAvg, voluList
	cout<<eleAvg->size()<<"======"<<voluList.size()<<endl;

	float force=0.0f;
	for(int i=0;i<voluList.size();i++){
		force += (eleAvg->at(i) * voluList.at(i));
	}
	
	float sumVolu=0.0f;
	for(int i=0;i<voluList.size();i++){
		sumVolu+=voluList.at(i);
	}
	
	float result = force / sumVolu;
	cout<<"result=="<<result<<endl;
	
	return 0;
}











