//Ritik gupta
//reg_no=11803278
//roll_no=23
//section=K18Jf
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int n1=2552,n2;
void confirm()
{
	cout<<"enter passcode :";
	cin>>n2;
	if(n2==n1)
{
	cout<<"WELCOME RITIK \n"<<endl;
	}
	else
{	cout<<"SORRY!";
	exit(1);}
}
class shop{
	int id;
	char name[50];
	int no;
	float price;
	public:
	void ip()
	{
	cout<<"enter id of product :";
	cin>>id;
	cout<<"\n enter the name of product :";
	cin>>name;
	cout<<"\n enter the no. of items :";
	cin>>no;
	cout<<"\n enter price :";
	cin>>price;
}
	void op()
	{

	cout<<"\n Id :"<<id;
	cout<<"\n Name :"<<name;
	cout<<"\n No of items :"<<no;
	cout<<"\n Price :"<<price;
}
int getid()
		{
			return id ;
		}
		  int checkpc(int ac)                //accessor function
							 { if((id%ac)==0)
							     return 0;
							    else return 1; 
								 };
} b,c,d,s;
int display();
int add();
int search();
void delt();
int main()
{
	confirm();
	cout<<"_________********_________*******SHOPING ADVISOR********________*******_________"<<endl;
	cout<<"_________********_________*******   WELCOME   ********________*******_________"<<endl;
	int a=1;
	while(a)
	{int x ;
	cout<<" MENU"<<endl;
	cout<<"1. Display All Products. "<<endl ;
	cout<<"2. Add New Products."<<endl ;
	cout<<"3. Search"<<endl ;
	cout<<"4. delete"<<endl;
	cout<<"Enter Your Option : "<<endl ;
	cin>>x;
	switch(x)
	{
		case 1 : display();
		break;
		case 2 : add();
		break;
		case 3 : search();
		break;
		case 4: delt();
		break;
		default : cout<<"Sorry Please Enter a Valid Input";
		break;
	}
	cout<<"\nDO you want to continue press 1 for YES or 0 for NO"<<endl;
	cin>>a;
	}
	return 0;
}
int display()
{
	ifstream infile ;
	infile.open("shop11803278.dat") ;
	if(!infile)
	{
		cout<<"ERROR!"  ;
		return 0 ;
	}
	while(!infile.eof())
	{
		infile.read((char*)&b,sizeof(b)) ;
		if(infile.eof())
		break ;
		b.op() ;
	}
	infile.close() ;
	return 1;
}
	int add()
{
	int n ;
	cout<<endl ;
	cout<<"Enter Number of Products : " ;
	cin>>n;
	cout<<endl<<endl ;
	ofstream outfile ;
	outfile.open("shop11803278.dat",ios::app|ios::binary) ;
	if(!outfile)
	{
		cout<<"ERROR!"<<endl<<endl ;
		return 0 ;
	}
	for(int i=0;i<n;i++)
	{
		c.ip() ;
		outfile.write((char*)&c,sizeof(c)) ;
	}
	outfile.close() ;

	return 1 ;
}
int search()
{
	int id1 ;
	int check=0 ;
	cout<<"Enter Serial ID : " ;
	cin>>id1 ;
	fstream Search ;
	Search.open("shop11803278.dat",ios::binary|ios::in) ;
	if(!Search)
	{
		cout<<"ERROR!!!"<<endl ;
		return 0 ;
	}
	while(!Search.eof())
	{
    	Search.read((char*)&d,sizeof(d)) ;
		if(id1==d.getid())
		{
			d.op();
			break;
		}
	if(check==0)
	{
		cout<<"ITEM NOT FOUND!"<<endl;
	}
	Search.close() ;
}
		return 1 ;
		}
		  void delt()
						  {
						    ifstream fio("shop11803278.dat",ios::binary);
						    ofstream file("temp.dat",ios::out|ios::binary);
						    int mpc1;
						    char found='f',confirm='n';
						    cout<<"\nEnter the Product code to be deleted:-";
							  cin>>mpc1;
							while(!fio.eof())
							{
								fio.read((char*)&s,sizeof(s));
								if(!(s.checkpc(mpc1))==0)
								{
									s.op();
									found='t';
							
									  
								}
								else
								     file.write((char*)&s,sizeof(s));
							    
							   } 
								if(found=='f')
								 cout<<"\nFile deleted!!\n";
								fio.close();
								file.close();
								remove("shop11803278.dat");
								rename("temp.dat","shop11803278.dat");   //old file is removed and temp file is renamed
								 		  
							  }
