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
	ifstream input(filename,ios::in);
//	string name;
	char str[SIZE];
	vector<float>* voluList;
	voluList = new vector<float>();
	
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
					voluList->push_back(volu);
				}
				
			}
			
		}
//		system("pause");
	}
	input.close();
	return voluList;
	
}
