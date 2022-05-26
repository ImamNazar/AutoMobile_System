#include<iostream>
#include <ctime> 
#include<string>
#include<fstream>
#include "iomanip"
using namespace std;
struct item
{
	string itemcode;
	string itemname;
	float price;
	float quantity;
};//inventory struct

int main()
{
item inventory[100];
void select(item inventory[100]);
int filein(item inv[100]);
select(inventory);
filein(inventory);
}
void head()
{
	cout<<"                 ***Auto Parts***              "<<endl;
	cout<<" The Best Place to fulfill your needs related to vehicles"<<endl;
	cout<<"                  Colombo, Sri Lanka     "<<endl;
	cout<<"                 Tel - 0112123123              "<<endl;
}//The header of the system
void select(item inventory[100])
{
	system("color f0");//to change the background color to white and text black
	system("cls");//clear screen command
	void head();//header function prototype
	void auth(item inventory[100]);//auth function prototype
	void help(item inventory[100]);//help function prototype
	int x;//selection variable
	head();//header function calling statement
	cout<<"Use BLOCK CAPITAL letters all throughout the System !"<<endl;
	cout<<"1.Login Page"<<endl;
	cout<<"2.Help"<<endl;
	cout<<"3.Exit"<<endl;
	cout<<"Please Enter Your Selection : ";
	cin>>x;
	switch(x)//Switch to call functions accordingly
	{
	case 1:auth(inventory);//auth function calling statement
		break;
	case 2:help(inventory);
		break;
	case 3:cout<<"Thank You"<<endl;
		break;
	}
}
void auth(item inventory[100])
{
	system("cls");
	void head();
	int num;// variable that wil be passed as a parameter
	void list(item inventory[100],int n);//list function prortype
	int filein(item inventory[100]);//file in function protoype
	void search(item inventory[100],int n);//search function prototype
	void add(item inventory[100],int &x);//add function prototype
	int x;//while loop control
	int sel;//user input variable
	num=filein(inventory);//return value from filein to be stored here
	string usr1,pas1;//variable declaration for the username and password
	head();
	
	
    x=0;
	cout<<"Please Enter The Username : ";
	cin>>usr1;//username input
	cout<<"Please Enter The Password : ";
	cin>>pas1;//password input
	while(x<3)//limitation to the number of wrong combinations
	{
	if(usr1=="ADMIN"&&pas1=="INPAUTOPARTS123")//condition to check the correct login credentials
	{
    system("cls");
	head();
	cout<<"Password correct"<<endl;
	cout<<"Logged In As Administrator"<<endl;
	cout<<"1.List Items"<<endl;
	cout<<"2.Search Item "<<endl;
	cout<<"3.Add Item"<<endl;
	cout<<"4.Exit"<<endl;
	cout<<"Enter Selection : ";
	cin>>sel;
	switch(sel)//switch that will call functions based on users input
	 {
	case 1:list(inventory,num);

	break;
	case 2: search(inventory,num);
		break;
	case 3: add(inventory,num);
		break;
	case 4:cout<<"Thank You"<<endl;
		break;
	 }
	break;
	}


	else//error handling
	{
	cout<<"Incorrect"<<endl;
	cout<<"Please Enter The Username : ";
	cin>>usr1;
	cout<<"Please Enter The Password : ";
	cin>>pas1;
	x++;//increment statement

	}
	}
	
	
}
int filein(item inventory[100])//the function to read the file and store in an array
{
	string nme;//cloumn name 
	int x=0;
	ifstream file;//declaring the input file
	file.open("item.txt");//opening the input file
	getline(file,nme);//column name collection
	file>>inventory[x].itemcode;
	file>>inventory[x].itemname;
	file>>inventory[x].price;
	file>>inventory[x].quantity;//storing in array values from file
	while(file)//error handling to make sure the file is there
	{
		x++;
	    file>>inventory[x].itemcode;
	    file>>inventory[x].itemname;
	    file>>inventory[x].price;
		file>>inventory[x].quantity;
	}
	file.close();
	return x;//the number of records returned to control other loops in the system
}
void list(item inventory[100],int n)//listing products in the inventory
{
	system("cls");
	void head();
	void auth(item inventory[100]);
	char sel;
	head();
	cout<<setw(10)<<left<<"Item Code"<<setw(10)<<left<<"Name"<<setw(10)<<left<<"Price"<<setw(10)<<left<<"Quantity"<<"\n";//column names in a order
	for(int x=0;x<n;x++)
	{
		cout<<setw(10)<<left<<inventory[x].itemcode<<setw(10)<<left<<inventory[x].itemname<<setw(10)<<left<<inventory[x].price<<setw(10)<<left<<inventory[x].quantity<<"\n";
	}
	
	cout<<"Type 'N' to end 'Y' to continue to Login Page : ";
	cin>>sel;
	if(sel!='N')//Terminate or stay in the system
	{
		auth( inventory);
	}
	else
	{
		cout<<"Thank You !"<<endl;
	}

}
void search(item inventory[100],int n)//search items from the inventory
{
	system("cls");
	void head();
	void write(item inventory[100],int n);//write function prototype
	string ser;
	char sel;
	
	head();
	while(ser!="Y")//The user input that would make sure the user in the search function or login page
	{
	cout<<"Please Enter The Item Name : ";
	cin>>ser;//Item name
	for(int x=0;x<n;x++)//loo to go through all the records
	 {
	if(ser==inventory[x].itemname)//Checking the product name with the items list in file
	  {
		cout<<setw(10)<<left<<"Item Code"<<setw(10)<<left<<"Name"<<setw(10)<<left<<"Price"<<setw(10)<<left<<"Quantity"<<"\n";
		cout<<setw(10)<<left<<inventory[x].itemcode<<setw(10)<<left<<inventory[x].itemname<<setw(10)<<left<<inventory[x].price<<setw(10)<<left<<inventory[x].quantity<<"\n";
	    cout<<"Type 'N' to stay 'Y' to continue to Login Page : ";
	cin>>sel;
	if(sel!='N')
	{
		auth( inventory);
	}
	else
	{
		
	}
	  }
	  else {
		  cout<<"Item not found"<<endl;
		  
	  }
	
	 }
	}
}
void add(item inventory[100],int &x)//Allows the user to add items to the file
{
	system("cls");
	void write(item inventory[100],int n);
	void auth(item inventory[100]);
	char sel;
	cout<<"Type 'N' to end 'Y' to continue: ";
	cin>>sel;//slection to control the user to keep adding items or not
	while(sel!='N')//the condition that would keep the user to keep adding items unless the input is N
	{

	cout<<" Add Items"<<endl;
	cout<<"Enter Product Code : ";
	cin>>inventory[x].itemcode;
	cout<<"Enter Product Name : ";
	cin>>inventory[x].itemname;
	cout<<"Enter Product Price : ";
	cin>>inventory[x].price;
	cout<<"Enter Product Quantity : ";
	cin>>inventory[x].quantity;
	x++;
	cout<<"Type 'N' to end 'Y' to continue: ";
	cin>>sel;
	}
	write(inventory,x);//calling statement for write function
	auth( inventory);//calling statement for auth function
	
}


void write(item inventory[100],int n)//the fuction that writes users inputs to the file
{
	ofstream file;//output file
	file.open("item.txt");//opening output file
	file<<"Item Code"<<"\t";//writing the column names to the file
	file<<"Item Name"<<"\t";
	file<<"Price"<<"\t";
	file<<"Quantity"<<endl;
	for(int x=0;x<n;x++)//going through all the records in the array
	{
		file<<inventory[x].itemcode<<"\t";
	    file<<inventory[x].itemname<<"\t";
	    file<<inventory[x].price<<"\t";
		file<<inventory[x].quantity<<endl;
	}
	file.close();//closin output file
}
void help(item inventory[100])
{
    system("cls");
	void auth(item inventory[100]);
	char sel;
	cout<<"               Help Page             "<<endl;
	cout<<"--------------------------------------"<<endl;
	cout<<"1.The Selections are done by entering the number assigned to it or Entering 'Y' or 'N'"<<endl;
	cout<<"Y=Yes"<<endl;
	cout<<"N=No"<<endl;
	cout<<"Please use uppercase letters at all times"<<endl;
	cout<<"Enter 'Y' to go to Login Page 'N' to end session : ";
	cin>>sel;
	if(sel!='N')
	{
	auth( inventory);
	}
	else
	{
		cout<<"Thank You !"<<endl;
	}
}

	