#include "readstress.h"
//#include <string>    // For string class
#include <iostream>  // For cout 
#include <fstream>   // For file reading
#include <vector>    // For vector class
#include <iomanip> // For format control
//#include <string.h> // For strncpy
#include <string>

#define SIZE 256

using namespace std;

bool isHead(const char* str, string* const  compare){
	for(int i=0;i<compare->size();i++){
		if(*(str+i)!=compare->at(i)){
			return false;
		}
	}
	return true;
}


vector<float>* readfile(const char* filename){
	ifstream input(filename, ios::in);
	string name;
	char str[SIZE];
	vector<float>* eleAvg;
	eleAvg = new vector<float>();
	int i;
	i=1;
	string headstr("  ELEMENT=");
	while (!input.eof()){
		
		input.getline(str,SIZE);
//		
		bool isfound = isHead(str, &headstr);
		if(isfound){
			//�ҵ�element��ͷ������
//			cout<<"read:"<<str<<endl;
//			system("pause");
			//����node�� 
			//input.getline(str,SIZE);
	
			//�ڶ��п�ʼ
			int eof=0;
			float count=0.0f;
			for(int j=0;j<8;j++){
				input.getline(str,SIZE);
				
				char b[12];
				string str1(str);
				string str2 = str1.substr(9,12);
			//	string tmp=string.copy(str,9,9);
//				strncpy(b, str+9, 12);
//				cout<<b<<endl;
//				cout<<b<<"____"<<str2<<endl;
//				
				//str2��ȡ��ȷ 
				float tmp;
				
				eof = sscanf(str2.c_str(), "%f", &tmp);//��charд�뵽�������Ͷ����tmp����
				// eofΪת�������ж�int�����������1��������������1˵��ת��ʧ�ܡ� 
				
				if(eof!=1){
//					cout<<"eof="<<eof<<"; str2="<<str2<<endl;
//					ת��ʧ�ܣ��򲻽����ۼ� 
				}else{
					count+=tmp; //��Ԫ������8���ڵ�ĸ�˹��Ӧ�����
//					cout<<"eof="<<eof<<"; str2="<<str2<<"____tmp="<<tmp<<"___count="<<count<<endl;
//					
				}
//				system("pause");
				
			}
//			count=count/8.0;
//			cout<<"count="<<count<<"; Average="<<count/8.0<<endl;
//			cout<<eof<<endl;
//			if(eof!=0){
//				system("pause");
//			}
			eleAvg->push_back(count);
		}
	
	}
	input.close();
//	cout<<"eleAvg size=="<<eleAvg->size()<<endl;
	
//	char a[]="-0.72293E-01";
//	float tmp;
//	sscanf(a, "%f", &tmp);
	//��charд�뵽�������Ͷ����tmp����
//	cout<<"paser"<<tmp<<endl;
	return eleAvg;
} 
