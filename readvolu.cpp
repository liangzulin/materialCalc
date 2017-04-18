#include "readvolu.h"
#include "readstress.h"
#include <iostream>  // For cout 
#include <fstream>   // For file reading
#include <vector>    // For vector class
#include <iomanip> // For format control
#include <string.h> // For strncpy

#define SIZE 256

using namespace std;

vector<float>* readVolufile(const char* filename){
	// "D:\\!CPP\\!DATAFILE\\666-element-volu-PRESOL.lis"
	int lines=0;
	ifstream input(filename,ios::in);
//	string name;
	char str[SIZE];
	vector<float>* voluList;
	voluList = new vector<float>();
	
	string headstr("    ELEM");
	while (!input.eof()){
		input.getline(str,SIZE);lines++;
		bool isfound = isHead(str, &headstr);
		if(isfound){
			string record = str;
			int eleline = lines;
			float volu=0.0f;
			vector<float> exceptionData(0);
			for(int j=0;j<41;j++){// 39
				input.getline(str,SIZE);lines++;
//				cout<<"strlen=="<<strlen(str)<<";____"<<str<<endl;
//				system("pause");
				if(strlen(str)<10){
					//此处对单元结尾进行了有效判断
					if(j<38){
						cout<<"Line "<<eleline<<":"<<record<<endl;
						cout<<"This element has only "<<j<<" elements."<<endl;
//						for(int k=0;k<exceptionData.size();k++){
//							cout<<exceptionData.at(k)<<" "<<endl;
//						}
//						system("pause");
					}
					break;
				}else{
					char b[12];
					strncpy(b, str+10, 11);
//		     		cout<<b<<endl;
					float tmp;
					int eof = sscanf(b, "%f", &tmp);//把char写入到浮点类型定义的tmp里面
					if(eof != 1){
						cout<<j<<"tmp="<<tmp<<"; eof="<<eof<<endl;
						system("pause");
					}else{
//						cout<<j<<"tmp="<<tmp<<"___b="<<b<<endl;
//						system("pause");
					}
					volu=tmp; //element对应Volu值
					voluList->push_back(volu);
					exceptionData.push_back(volu);
				}
				
			}
			
		}
//		system("pause");
	}
	input.close();
	return voluList;
	
}
