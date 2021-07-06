#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdlib.h>
#include<string>
#include<stdio.h>
using namespace std;
class section{
	private:
	string sName, sMentor, sHOD, sCoord, sPlaceMentor, sCR, sEcellCoord, sPlaceCoord; 
	public:
		void add_section();
		void search_section();
		void show_section();
//		void delete_section();
//		void modify_section();	
};

void section::add_section(){
	cout<<"Enter Section Name: ";
	fflush(stdin);
	getline(cin,sName);
	cout<<"Enter Section Mentor Name: ";
	fflush(stdin);
	getline(cin,sMentor);
	cout<<"Enter Section HOD Name: ";
	fflush(stdin);
	getline(cin,sHOD);
	cout<<"Enter Section Coordinator Name: ";
	fflush(stdin);
	getline(cin,sCoord);
	cout<<"Enter Section Placement Mentor Name: ";
	fflush(stdin);
	getline(cin,sPlaceMentor);
	cout<<"Enter Class Representative Name: ";
	fflush(stdin);
	getline(cin,sCR);
	cout<<"Enter E-Cell Coordinator Name: ";
	fflush(stdin);
	getline(cin,sEcellCoord);
	cout<<"Enter Placement Coordinator Name: ";
	fflush(stdin);
	getline(cin,sPlaceCoord);
	
	ofstream f;
	f.open("section.txt", ios::app);
	f<<setw(20)<<sName<<setw(20)<<sMentor<<setw(20)<<sHOD<<setw(20)<<sCoord<<setw(20)<<sPlaceMentor<<setw(20)<<sCR<<setw(25)<<sEcellCoord<<setw(25)<<sPlaceCoord<<endl;
	f.close();
}

void section::search_section(){
	string temp;
	cout<<"Enter the section name: ";
	cin>>temp;
	ifstream f;
	f.open("section.txt");
	f.seekg(0,ios::beg);
	string dataCopier;
	int flag=0;
	while(f>>dataCopier){
		if(dataCopier==temp){
			flag=1;
			cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
			cout<<setw(90)<<"DATA FOUND!!!"<<endl;
			cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
			f.seekg(-20,ios::cur);
			getline(f,dataCopier);
			cout<<setw(20)<<"Section"<<setw(20)<<"Mentor"<<setw(20)<<"HOD"<<setw(20)<<"Coordinator"<<setw(20)<<"Placement Mentor"<<setw(20)<<"CR"<<setw(25)<<"E-Cell Coordinator"<<setw(25)<<"Placement Coordinator"<<endl;
			cout<<setw(160)<<dataCopier<<endl;
		}  
	}
	if(flag==0){
			cout << "\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
			cout<<setw(90)<<"DATA NOT FOUND!!!"<<endl;
			cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		}
}

void section::show_section(){
	ifstream f;
	f.open("section.txt");
	f.seekg(0,ios::beg);
	string dataCopier;
	cout<<setw(20)<<"Section"<<setw(20)<<"Mentor"<<setw(20)<<"HOD"<<setw(20)<<"Coordinator"<<setw(20)<<"Placement Mentor"<<setw(20)<<"CR"<<setw(25)<<"E-Cell Coordinator"<<setw(25)<<"Placement Coordinator"<<endl;
	while(getline(f,dataCopier)){
		cout<<setw(160)<<dataCopier<<endl;
		}  
	}

int main(){
	section s;
	int choice;
	do{
		cout<<"\nYou Can Perform Following Operations:"<<endl
			<<"1. Add New Section"<<endl
			<<"2. Search Section Details"<<endl
			<<"3. Show All Section Details"<<endl
			<<"4. Delete Any Section"<<endl
			<<"5. Modify Any Section"<<endl
			<<"6. Exit"<<endl
			<<"Enter Your Choice: ";
		cin>>choice;
		switch(choice){
			case 1:
			s.add_section();
			break;
			case 2:
			s.search_section();
			break;
			case 3:
			s.show_section();
			// sleep( 3000 );
			break;
			case 4:
//			s.delete_section();
			break;
			case 5:
//			s.modify_section();
			break;
			case 6:
			return 0;
			exit(0);
			break;
			default:
			cout<<"Wrong Input!";
			return 0;
			exit(0);
		} 
	}while(true);
	
	
	
	return 0;
}
