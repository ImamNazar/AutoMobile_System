# AutoMobile_System
The automobile system repository provides a desktop-based system for a automobile part shop that was written entirely in the C++ programming language. The system isn't very complex. The only thing a user should do while dealing with the system is to always input data in UPPERCASE LETTERS. They must also not leave any gaps between words/values while entering, and if they do, they must connect the values with a ( _ ) underscore. As a result, one must be aware that the system is case sensitive.

To edit and modify the program, get the assig1.cpp file from the repo and execute it in any IDE that can handle C++ programs (visual studio code is suggested). To execute this program, you must first download and save the assig1.cpp file to a folder before _running it in the terminal_.

The source code and functions used to develop the automobile shop system are listed below.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Structures
struct item
{
    string itemcode;
    string itemname;
    float price;
    float quantity;
};//inventory struct


Above mentioned structures are created in order to store values form the inventory.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Main Function
int main()
{
item inventory[100];
void select(item inventory[100]);
int filein(item inventory[100]);
select(inventory);
filein(inventory);

Main function will only callout the filein function and clear the way to run the selection function which will call the other functions later in the system.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Head Function
void head()
{
    cout<<"                 ***Auto Parts***              "<<endl;
    cout<<" The Best Place to fulfill your needs related to vehicles"<<endl;
    cout<<"                  Colombo, Sri Lanka     "<<endl;
    cout<<"                 Tel - 0112123123              "<<endl;
}//The header of the system

The main task of head function is to print/display the head of the Auto Parts shop. Later in the system, this function will be called by other function to display the head in every page that appears.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Select Function
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

This function mainly concentrates on the choices of the user/admin to call out other functions.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Auth (Authentication) Function
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
    if(usr1=="ADMIN"&&pas1=="INP")//condition to check the correct login credentials
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

This function is created to display a login page where user can verify the username and password correctly in order to call out the specified functions in the system. It is designed only to access by administrator. 

Username = ADMIN / 
Password = A001

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

# File-in Function
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

This function takes values form inventory file and assign them to the inventory structs, which will be need later in the system.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

# List Function
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

This function has been created to list out and display the Item’s name, code, price and the quantities that are available in the inventory/system in horizontal order, which will help the admin/user a lot while working.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Search Function
Search Function
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

This function helps the user/admin to search for an available specific item and it’s details from the inventory.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Add Function
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


In this function, admin/user can directly add items to inventory file indirectly, and later this process will be completed by auth and write functions.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Write Function
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

This function writes the edited values of the inventory struct to the inventory.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Help Function
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

This function is the main task of guiding the user to use the system without a trouble.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

# USER_MANUAL #
 In order to guide the user to use the program, a user manual along with screenshots are given below.
 
# Login Page
When it comes to the login page the user is subjected enter 3 options and based on the value the user enter other functions of the system are called
1= Login Page
2= Help Page
3. Exit

# Authentication Page
This page requires user to enter the username = ADMIN and Password as INP if the combination is correct the system will take into function listing of the system.

# Main Selection Page
This is quite similar to the main function of the system where the User is given 4 options where
1= List Item Function
2= Search Item Function
3= Add Item Function
4= Exit

# List Items Page
When the user is in the List Item Function the inventory would be displayed and in order to proceed to the login page again Y is required and N would result in system termination.

# Search Items Page
The Item name should be given by the user and system would go through all the records until the name matches with the Inventory, if the Item name is found the details would display and Item Not found would be displayed otherwise. 

# Add Items Page 
When it comes to the ADD Items function the user has to input Y to start adding items to system, the system would ask for the Product Code, Product Name without Spaces, product price and the product quantity then the system would prompt a selection in which the user has to enter Y to keep adding items to the inventory and N to terminate the function. 

