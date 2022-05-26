#include<iostream>
#include<fstream>
#include<ctime>
#include"iomanip"

using namespace std;
struct user
{
    string f_name;
    string l_name;
    string salutation;
    string address;
    int phone_num;
    int age;
    char gender;
    string email_address;
    string username;
    string password;
};
struct inventory
{
    string I_code;
    string I_name;
    int I_QTY;
    float I_price;
};
struct bill
{
    string I_code;
    string I_name;
    int I_QTY;
    float I_price;
};

int i=0;
void header();

int fill_in_pro(user pro[100]);
void login(user pro[100],inventory item[1000],bill order[1000],int n);
void admin(user pro[100],inventory item[1000],bill order[1000],int n);
void cashier(user pro[100],inventory item[1000],bill order[1000],int n);
void c_log(user pro[100],inventory item[1000],bill order[1000],int &x);
void save_pro(user pro[100],inventory item [1000],bill order[1000],int n);

void invent(user pro[100],inventory item[1000],bill order[1000],int n);
int fill_in_inventory(inventory item[1000]);
void add_inventory(user pro[100],inventory item[1000],bill order[1000],int &y);
void save_inventory(user pro[100],inventory item[1000],bill order[1000],int n);
void list_inventory(user pro[100],inventory item[1000],bill order[1000],int n);

int fill_in_order(bill order[1000]);
void billing(inventory item[1000],bill order[1000],int z);
void save_order(inventory item[1000],bill order[1000],int z);
void recipt(inventory item[1000],bill order[1000],int y);

void ad_recipt(inventory item[1000],bill order[1000],int y);
void ad_billing(inventory item[1000],bill order[1000],int z);

void help();
void c_help();
void a_help();

void exit();
void c_exit();
void a_exit();

int main()
{
    system("cls");
    system("color 07");
    int option_1;
    user pro[100];
    inventory item[1000];
    bill order[1000];
    int num; 
    fill_in_pro(pro);
    num=fill_in_pro(pro);
    header();
    cout<<endl;
    cout<<setw(55)<<"-----------------------------"<<endl;
    cout<<setw(55)<<"          Main Menu          "<<endl;
    cout<<setw(55)<<"-----------------------------"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"        1. Login"<<endl;
    cout<<endl;
    cout<<setw(15)<<"2. Help"<<endl;
    cout<<endl;
    cout<<setw(15)<<"3. Exit"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Select An Option : ";
    cin>>option_1;
    switch(option_1)
    {
        case 1:
        login(pro,item,order,num);
        break;
        case 2:
        help();
        break;
        case 3:
        exit();
        break;
        default:
        cout<<"Invalid Input. Try Again."<<endl;
        main();
        break;
    }
}

int fill_in_pro(user pro[100])
{
    ifstream in;
    in.open("profile.txt");
    string column;
    int x=0;
    getline(in,column);
    in>>pro[x].f_name;
    in>>pro[x].l_name;
    in>>pro[x].gender;
    in>>pro[x].salutation;
    in>>pro[x].age;
    in>>pro[x].address;
    in>>pro[x].phone_num;
    in>>pro[x].email_address;
    in>>pro[x].username;
    in>>pro[x].password;
    while(in)
    {
        ++x;
        in>>pro[x].f_name;
        in>>pro[x].l_name;
        in>>pro[x].gender;
        in>>pro[x].salutation;
        in>>pro[x].age;
        in>>pro[x].address;
        in>>pro[x].phone_num;
        in>>pro[x].email_address;
        in>>pro[x].username;
        in>>pro[x].password;
    }
    in.close();
    return x;
}

void login(user pro[100],inventory item[1000],bill order[1000],int n)
{
    system("cls");
    int op_login;
    string username;
    string password;
    header();
    while(i<3)
    {
        cout<<endl;
        cout<<setw(55)<<"-------------------------"<<endl;
        cout<<setw(55)<<"          LOGIN          "<<endl;
        cout<<setw(55)<<"-------------------------"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"     1. Login As Admin"<<endl;
        cout<<endl;
        cout<<"     2. Login As Cashier"<<endl;
        cout<<endl;
        cout<<"     3. Return To Main Menu"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"Select An Option : ";
        cin>>op_login;
        switch(op_login)
        {
            case 1:
            system("cls");
            header();
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<setw(55)<<"Type Your Username : ";
            cin>>username;
            cout<<endl;
            cout<<endl;
            if(username=="test")
            {
                cout<<endl;
                cout<<setw(55)<<"Type Your Password : ";
                cin>>password;
                if(password=="test")
                {
                    admin(pro,item,order,n);
                }
            }
            else
            {
                i=i+1;
                cout<<"Wromg Combination Of Username And Password. Try Again.";
                login(pro,item,order,n);
            }
            break;
            case 2:
            system("cls");
            header();
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<setw(55)<<"     Type Your Username : ";
            cin>>username;
            cout<<endl;
            cout<<endl;
            cout<<setw(55)<<"     Type Your Password : ";
            cin>>password;
            for(int y=0;y<n;++y)
            {
                if(username==pro[y].username && password==pro[y].password)
                {
                    cashier(pro,item,order,n);
                }
                /*else
                {
                    i=i+1;
                    cout<<"Wromg Combination Of Username And Password. Try Again.";
                    login(pro,item,order,n);
                }*/
            }
            break;
            case 3:
            main();
            break;
            default:
            cout<<"Invalid Input. Try Again.";
            login(pro,item,order,n);
            break;
        }
        system("cls");
        break;
    }
}

void admin(user pro[100],inventory item[1000],bill order[1000],int n)
{
    system("cls");
    int admin_op;
    int num2;
    fill_in_inventory(item);
    num2=fill_in_inventory(item);
    header();
    cout<<endl;    
    cout<<"You Have Logged In As Admin"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"             1. Inventory"<<endl;
    cout<<endl;
    cout<<"             2. Billing"<<endl;
    cout<<endl;
    cout<<"             3. Create User"<<endl;
    cout<<endl;
    cout<<setw(20)<<"4. Help"<<endl;
    cout<<endl;
    cout<<setw(20)<<"5. Exit"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Select An Option : ";
    cin>>admin_op;
    switch(admin_op)
    {
        case 1:
        invent(pro,item,order,num2);
        break;
        case 2:
        ad_billing(item,order,num2);
        break;
        case 3:
        c_log(pro,item,order,n);
        break;
        case 4:
        a_help();
        break;
        case 5:
        a_exit();
        break;
        default:
        admin(pro,item,order,n);
        break;
    }  
}

void cashier(user pro[100],inventory item[1000],bill order[1000],int n)
{
    system("cls");
    int user_op;
    int num2;
    fill_in_inventory(item);
    num2=fill_in_inventory(item);
    header();
    cout<<endl;
    cout<<setw(20)<<"You have logged in as cashier"<<endl;
    cout<<endl;
    cout<<"             1. Billing"<<endl;
    cout<<endl;
    cout<<setw(20)<<"2. Help"<<endl;
    cout<<endl;
    cout<<setw(20)<<"3. Exit"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Select An Option : ";
    cin>>user_op;
    switch(user_op)
    {
        case 1:
        billing(item,order,num2);
        break;
        case 2:
        c_help();
        break;
        case 3:
        c_exit();
        break;
        default:
        cashier(pro,item,order,n);
        break;
    }  
}


void c_log(user pro[100],inventory item[1000],bill order[1000],int &x)
{
    system("cls");
    string con_password;
    header();
    char c_op;
    cout<<"Enter your first name      : "<<endl;
    cin>>pro[x].f_name;        
    cout<<endl;
    cout<<"Enter your last name       : "<<endl;
    cin>>pro[x].l_name;        
    cout<<endl;
    cout<<"Enter your gender          : "<<endl;
    cin>>pro[x].gender;
    cout<<endl;
    cout<<"Enter your salutation      : "<<endl;
    cin>>pro[x].salutation;        
    cout<<endl;
    cout<<"Enter your age             : "<<endl;
    cin>>pro[x].age;        
    cout<<endl;
    cout<<"Enter your address         : "<<endl;
    cin>>pro[x].address;        
    cout<<endl;
    cout<<"Enter your phone number    : "<<endl;
    cin>>pro[x].phone_num;       
    cout<<endl;
    cout<<"Enter your email address   : "<<endl;
    cin>>pro[x].email_address;        
    cout<<endl;
    cout<<"Enter a username           : "<<endl;
    cin>>pro[x].username;        
    cout<<endl;
    cout<<"Enter a password           : "<<endl;
    cin>>pro[x].password;
    cout<<endl;
    cout<<"Enter the confirm password : "<<endl;
    cin>>con_password;
    cout<<endl;
    if(con_password==pro[x].password)
    {
        cout<<"You Have Successfully Created An Account ";
    }
    else
    {
        cout<<"The Passwords You Have Typed Donnot Match. Try Again";
        c_log(pro,item,order,x);
    }
    cout<<endl;
    cout<<"Do You Want to return(Y/N)";
    cin>>c_op;
    if(c_op=='Y')
    {
        save_pro(pro,item,order,x);
    }
}

void save_pro(user pro[100],inventory item [1000],bill order[1000],int n)
{
    ofstream out;
    out.open("profile.txt");
    out<<"First Name"<<"\t";
    out<<"\t";
    out<<"Last Name "<<"\t";
    out<<"\t";
    out<<"Gender"<<"\t";
    out<<"\t";
    out<<"Salutation"<<"\t";
    out<<"\t";
    out<<"Age"<<"\t";
    out<<"\t";
    out<<"Address"<<"\t";
    out<<"\t";
    out<<"Phone Number"<<"\t";
    out<<"\t";
    out<<"Email Address"<<"\t";
    out<<"\t";
    out<<"Username"<<"\t";
    out<<"\t";
    out<<"Password"<<endl;
    for(int x=0;x<=n;++x)
    {
        out<<pro[x].f_name<<"\t";
        out<<"\t";
        out<<pro[x].l_name<<"\t";
        out<<"\t";
        out<<pro[x].gender<<"\t";
        out<<"\t";
        out<<pro[x].salutation<<"\t";
        out<<"\t";
        out<<pro[x].age<<"\t";
        out<<"\t";
        out<<pro[x].address<<"\t";
        out<<"\t";
        out<<pro[x].phone_num<<"\t";
        out<<"\t";
        out<<pro[x].email_address<<"\t";
        out<<"\t";
        out<<pro[x].username<<"\t";
        out<<"\t";
        out<<pro[x].password<<endl;
    }
    out.close();
    login(pro,item,order,n);
}

int fill_in_inventory(inventory item[1000])
{
    ifstream in;
    in.open("inventory.txt");
    string column;
    int y=0;
    getline(in,column);
    in>>item[y].I_code;
    in>>item[y].I_name;
    in>>item[y].I_price;
    in>>item[y].I_QTY;
    while(in)
    {
        ++y;
        in>>item[y].I_code;
        in>>item[y].I_name;
        in>>item[y].I_price;
        in>>item[y].I_QTY;
    }
    in.close();
    return y;
}

void invent(user pro[100],inventory item[1000],bill order[1000],int n)
{
    system("cls");
    int invent_op;
    int num;
    fill_in_pro(pro);
    num=fill_in_pro(pro);
    header();
    cout<<endl;
    cout<<"             1. Check inventory";
    cout<<endl;
    cout<<"             2. Add item";
    cout<<endl;
    cout<<"             3. Return";
    cout<<endl;
    cout<<endl;
    cout<<"Select An Option :";
    cin>>invent_op;
    switch(invent_op)
    {
        case 1:
        list_inventory(pro,item,order,n);
        break;
        case 2:
        add_inventory(pro,item,order,n);
        break;
        case 3:
        admin(pro,item,order,num);
        default:
        cout<<"Invalid input. Try again";
        invent(pro,item,order,n);
        break;
    }
}

void add_inventory(user pro[100],inventory item[1000],bill order[1000],int &y)
{
    system("cls");
    char op;
    header();
    cout<<endl;
    cout<<" Add Product 'Y' or 'y ";
    cin>>op;
    cout<<"\n";
    cout<<"\n";
    if(op=='Y' || op=='y')
    {
        cout<<"             I_code   : ";
        cin>>item[y].I_code;
        cout<<endl;
        cout<<"             I_name   : ";
        cin>>item[y].I_name;
        cout<<endl;
        cout<<"             I_price  : ";
        cin>>item[y].I_price;
        cout<<endl;
        cout<<"             I_QTY    : ";
        cin>>item[y].I_QTY;
        cout<<endl;
        save_inventory(pro,item,order,y);
    }
    else 
    {
        invent(pro,item,order,y);
    }
    invent(pro,item,order,y);
}


void save_inventory(user pro[100],inventory item[1000],bill order[1000],int n)
{
    ofstream out;
    out.open("inventory.txt");
    out<<"I_code"<<"\t";
    out<<"\t";
    out<<"I_name"<<"\t";
    out<<"\t";
    out<<"I_price"<<"\t";
    out<<"\t";
    out<<"I_QTY"<<endl;
    for(int y=0;y<=n;++y)
    {
        out<<item[y].I_code<<"\t \t";
        out<<"\t";
        out<<item[y].I_name<<"\t \t";
        out<<"\t";
        out<<item[y].I_price<<"\t \t";
        out<<"\t";
        out<<item[y].I_QTY<<endl;        
    }
    out.close();
}

void list_inventory(user pro[100],inventory item[1000],bill order[1000],int n)
{
    system("cls");
    char dec;
    header();
    cout<<endl;
    cout<<setw(10)<<right<<"I_code"<<setw(10)<<right<<"I_name"<<setw(20)<<right<<"I_price"<<setw(10)<<right<<"I_QTY"<<endl;
    for(int x=0;x<=n;++x)
    {
        cout<<setw(10)<<right<<item[x].I_code<<setw(10)<<right<<item[x].I_name<<setw(20)<<right<<item[x].I_price<<setw(10)<<right<<item[x].I_QTY<<endl;
    }
    cout<<"Do You U Want To Return (y/n)"<<endl;
    cin>>dec;
    if (dec=='y')
    {
        invent(pro,item,order,n);
    }
    else if (dec=='n')
    {
        list_inventory(pro,item,order,n);
    }
    else
    {
        cout<<"Invalid Input";
        list_inventory(pro,item,order,n);

    }   
}

void billing(inventory item[1000],bill order[1000],int n)
{
    system("cls");
    string dec;
    int a; // qty 
    header();
    cout<<endl;
    for(int x=0;x<=n;++x)
    {
        order[x].I_code="default";
        order[x].I_name="default";
        order[x].I_price=0;
        order[x].I_QTY=0;
    }
    cout<<"             Item Code (Or Type Y To Bill) :  ";
    cin>>dec;
    cout<<endl;
    while(dec!="Y")
    {
        for(int y=0;y<n;++y)
        {
            if(dec==item[y].I_code)
            {
                order[y].I_code=item[y].I_code;
                order[y].I_name=item[y].I_name;
                order[y].I_price=item[y].I_price;
                cout<<"             Item Quantity : ";
                cin>>a;
                if(a<item[y].I_QTY)
                {
                    order[y].I_QTY=a;
                    item[y].I_QTY=item[y].I_QTY-a;
                }
                else
                {
                    cout<<"Quantity Is Low"<<endl;
                }  
            }
        }
        save_order(item,order,n); 
        cout<<"             Item Code :  ";
        cin>>dec;
        cout<<"(Or Type Y To Bill)";
        cout<<endl;
    }
    recipt(item,order,n);
}

void ad_billing(inventory item[1000],bill order[1000],int n)
{
    system("cls");
    string dec;
    int a; // qty
    header();
    cout<<endl; 
    for(int x=0;x<=n;++x)
    {
        order[x].I_code="default";
        order[x].I_name="default";
        order[x].I_price=0;
        order[x].I_QTY=0;
    }
    cout<<"             Item Code :  ";
    cin>>dec;
    cout<<"(Or Type Y To Bill)";
    cout<<endl;
    while(dec!="Y")
    {
        for(int y=0;y<n;++y)
        {
            if(dec==item[y].I_code)
            {
                order[y].I_code=item[y].I_code;
                order[y].I_name=item[y].I_name;
                order[y].I_price=item[y].I_price;
                cout<<"             Item Quantity : ";
                cin>>a;
                if(a<item[y].I_QTY)
                {
                    order[y].I_QTY=a;
                    item[y].I_QTY=item[y].I_QTY-a;
                }
                else
                {
                    cout<<"Quantity Is Low"<<endl;
                }  
            }
        }
        save_order(item,order,n); 
        cout<<"             Item Code :  ";
        cin>>dec;
        cout<<"(Or Type Y To Bill)";
        cout<<endl;
    }
    ad_recipt(item,order,n);
}


void save_order(inventory item[1000],bill order[1000],int n)
{
    ofstream out;
    out.open("inventory.txt");
    out<<"I_code"<<"\t";
    out<<"I_name"<<"\t";
    out<<"I_price"<<"\t";
    out<<"I_QTY"<<endl;
    for(int x=0;x<=n;++x)
    {
        if(order[x].I_name==item[x].I_name)
        {
            order[x].I_code=item[x].I_code;
            order[x].I_name=item[x].I_name;
            order[x].I_price=item[x].I_price;
            out<<order[x].I_code<<"\t";
            out<<order[x].I_name<<"\t";
            out<<order[x].I_price<<"\t";
            out<<item[x].I_QTY<<endl;
        }
        if(item[x].I_name!=order[x].I_name)
        {
            out<<item[x].I_code<<"\t";
            out<<item[x].I_name<<"\t";
            out<<item[x].I_price<<"\t";
            out<<item[x].I_QTY<<endl;
        }
    }
    out.close();
}

void recipt(inventory item[1000],bill order[1000],int n)
{
    system("cls");
    char op;
    string name;
    int no;
    float Total;
    float items;
    float cash;
    float balance;
    user pro[100];
    int num;
    fill_in_pro(pro);
    num=fill_in_pro(pro);
    header();
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Cashier : ";
    cin>>name;
    cout<<endl;
    cout<<"Invoice Number : ";
    cin>>no;
    cout<<endl;
    cout<<setw(10)<<"Item_Code"<<setw(10)<<"Item_name"<<setw(10)<<"Item_QTY"<<setw(10)<<"Unit Price"<<setw(10)<<"Total"<<endl;
    for(int x=0;x<=n;++x)
    {
        if(order[x].I_name!="default"&&order[x].I_price!=0&&order[x].I_code!="default"&&order[x].I_QTY!=0)
        {
            cout<<setw(10)<<order[x].I_code<<setw(10)<<order[x].I_name<<setw(10)<<order[x].I_QTY<<setw(10)<<order[x].I_price<<setw(10)<<order[x].I_QTY*order[x].I_price<<endl;
            Total=Total+order[x].I_QTY*order[x].I_price;
            ++items;
            no=no+order[x].I_QTY;
        }
    }
    cout<<"Total Bill Amount : "<<Total<<endl;
    cout<<"Cash Given        : ";
    cin>>cash;
    balance=cash-Total;
    cout<<"Balance           : "<<balance<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Return To Main Menu (Y/N) :";
    cin>>op;
    if(op=='Y')
    {
        cashier(pro,item,order,num);
    }
}

void ad_recipt(inventory item[1000],bill order[1000],int n)
{
    system("cls");
    char op;
    string name;
    int no;
    float Total;
    float items;
    float cash;
    float balance;
    user pro[100];
    int num;
    fill_in_pro(pro);
    num=fill_in_pro(pro);
    header();
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Cashier : ";
    cin>>name;
    cout<<endl;
    cout<<"Invoice Number : ";
    cin>>no;
    cout<<endl;
    cout<<setw(10)<<"Item_Code"<<setw(10)<<"Item_name"<<setw(10)<<"Item_QTY"<<setw(10)<<"Unit Price"<<setw(10)<<"Total"<<endl;
    for(int x=0;x<=n;++x)
    {
        if(order[x].I_name!="default"&&order[x].I_price!=0&&order[x].I_code!="default"&&order[x].I_QTY!=0)
        {
            cout<<setw(10)<<order[x].I_code<<setw(10)<<order[x].I_name<<setw(10)<<order[x].I_QTY<<setw(10)<<order[x].I_price<<setw(10)<<order[x].I_QTY*order[x].I_price<<endl;
            Total=Total+order[x].I_QTY*order[x].I_price;
            ++items;
            no=no+order[x].I_QTY;
        }
    }
    cout<<"Total Bill Amount : "<<Total<<endl;
    cout<<"Cash Given        : ";
    cin>>cash;
    balance=cash-Total;
    cout<<"Balance           : "<<balance<<endl;
    cout<<"Return To Main Menu (Y/N) :";
    cin>>op;
    if(op=='Y')
    {
        admin(pro,item,order,num);
    }
}

void help()
{   
    char dec;
    system("cls");
    header();
    cout<<endl;
    cout<<setw(55)<<"-------------------------------------"<<endl;
    cout<<setw(55)<<"              HELP PAGE              "<<endl;
    cout<<setw(55)<<"-------------------------------------"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<setw(55)<<"              About Us              "<<endl;
    cout<<setw(55)<<"------------------------------------"<<endl;
    cout<<endl;
    cout<<"WingsWeird Is Fashion Outlet For Womens With Best Dressing Sense. We Provide Number One Quality Dress In The Whole Country.";
    cout<<" You Can Desing Your Own Dress Or You Can Ask Our Designer To Desing A Dress For You And Get It Ready Within A Week.";
    cout<<"We Desing Our Own Product. Our Brand Is The Most Popular Brand In THe Whole World. It Is Our Pride To Serve You.";
    cout<<endl;
    cout<<endl;
    cout<<setw(55)<<"              How To Use              "<<endl;
    cout<<setw(55)<<"--------------------------------------"<<endl;
    cout<<endl;
    cout<<"To Select Options :- Enter The Number Assingned To It. "<<endl;
    cout<<"Incase Of Wrong Input The System Will Give You Another Try"<<endl;
    cout<<endl;
    cout<<"To Login Use The Username That Is Given To You."<<endl;
    cout<<"Only The Admin Can Create A User"<<endl;
    cout<<"Incase You Haved To Type The Incorrect Username And Password The System Will Give You Another Try."<<endl;
    cout<<"But The System Will Provide You With A Limitted Number OF Tries Due To Security Concerned.";
    cout<<"In That Case ShutDown The Whole System And Try Again."<<endl;
    cout<<"If You Have Forgot The Password. Contact Us."<<endl;
    cout<<endl;
    cout<<endl;
    cout<<setw(55)<<"              Contact Us              "<<endl;
    cout<<setw(55)<<"--------------------------------------"<<endl;
    cout<<endl;
    cout<<"We Are Here To Answer Any Question You May Have About Our WingsWeird POS Experiance. Reach Out To Us And We'll Respond As Soon As We Can."<<endl;
    cout<<endl;
    cout<<"Even If There Is Something Inconvenient In Using Our System, Let Us Know And We Promise We'll Do Our Best To Sort It Out For You."<<endl;
    cout<<endl;
    cout<<endl;
    cout<<setw(35)<<"Developer Of The System"<<endl;
    cout<<setw(35)<<"```````````````````````"<<endl;;
    cout<<endl;
    cout<<"Visit Us"<<endl;
    cout<<"Address:- 14/A Gampola Kandy"<<endl;
    cout<<endl;
    cout<<"Ring Us"<<endl;
    cout<<"Mobile  :- +94777555555"<<endl;
    cout<<"Tel/Fax :- 0814444444"<<endl;
    cout<<endl;
    cout<<"Mail Us"<<endl;
    cout<<"Amra@gmail.com";
    cout<<endl;
    cout<<"Do You Want To Return (Y/N)"<<endl;
    cin>>dec;
    switch(dec)
    {
        case 'Y':
        main();
        break;
        defualt:
        help();
        break;
    }
}

void c_help()
{   
    user pro[100];
    inventory item[1000];
    bill order[1000];
    int num;
    fill_in_pro(pro);
    num=fill_in_pro(pro);
    system("cls");
    char dec;
    header();
    cout<<endl;
    cout<<setw(55)<<"-------------------------------------"<<endl;
    cout<<setw(55)<<"              HELP PAGE              "<<endl;
    cout<<setw(55)<<"-------------------------------------"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<setw(55)<<"              About Us              "<<endl;
    cout<<setw(55)<<"------------------------------------"<<endl;
    cout<<endl;
    cout<<"WingsWeird Is Fashion Outlet For Womens With Best Dressing Sense. We Provide Number One Quality Dress In The Whole Country.";
    cout<<" You Can Desing Your Own Dress Or You Can Ask Our Designer To Desing A Dress For You And Get It Ready Within A Week.";
    cout<<"We Desing Our Own Product. Our Brand Is The Most Popular Brand In THe Whole World. It Is Our Pride To Serve You.";
    cout<<endl;
    cout<<endl;
    cout<<setw(55)<<"              How To Use              "<<endl;
    cout<<setw(55)<<"--------------------------------------"<<endl;
    cout<<endl;
    cout<<"To Select Options :- Enter The Number Assingned To It. "<<endl;
    cout<<"Incase Of Wrong Input The System Will Give You Another Try"<<endl;
    cout<<endl;
    cout<<"To Login Use The Username That Is Given To You."<<endl;
    cout<<"Only The Admin Can Create A User"<<endl;
    cout<<"Incase You Haved To Type The Incorrect Username And Password The System Will Give You Another Try."<<endl;
    cout<<"But The System Will Provide You With A Limitted Number OF Tries Due To Security Concerned.";
    cout<<"In That Case ShutDown The Whole System And Try Again."<<endl;
    cout<<"If You Have Forgot The Password. Contact Us."<<endl;
    cout<<endl;
    cout<<endl;
    cout<<setw(55)<<"              Contact Us              "<<endl;
    cout<<setw(55)<<"--------------------------------------"<<endl;
    cout<<endl;
    cout<<"We Are Here To Answer Any Question You May Have About Our WingsWeird POS Experiance. Reach Out To Us And We'll Respond As Soon As We Can."<<endl;
    cout<<endl;
    cout<<"Even If There Is Something Inconvenient In Using Our System, Let Us Know And We Promise We'll Do Our Best To Sort It Out For You."<<endl;
    cout<<endl;
    cout<<endl;
    cout<<setw(35)<<"Developer Of The System"<<endl;
    cout<<setw(35)<<"```````````````````````"<<endl;;
    cout<<endl;
    cout<<"Visit Us"<<endl;
    cout<<"Address:- 14/A Gampola Kandy"<<endl;
    cout<<endl;
    cout<<"Ring Us"<<endl;
    cout<<"Mobile  :- +94777555555"<<endl;
    cout<<"Tel/Fax :- 0814444444"<<endl;
    cout<<endl;
    cout<<"Mail Us"<<endl;
    cout<<"Amra@gmail.com";
    cout<<endl;
    cout<<"Do You Want To Return (Y/N)"<<endl;
    cin>>dec;
    switch(dec)
    {
        case 'Y':
        cashier(pro,item,order,num);
        break;
        defualt:
        help();
        break;
    }
}

void a_help()
{   
    user pro[100];
    inventory item[1000];
    bill order[1000];
    int num;
    fill_in_pro(pro);
    num=fill_in_pro(pro);
    system("cls");
    char dec;
    header();
    cout<<endl;
    cout<<setw(55)<<"-------------------------------------"<<endl;
    cout<<setw(55)<<"              HELP PAGE              "<<endl;
    cout<<setw(55)<<"-------------------------------------"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<setw(55)<<"              About Us              "<<endl;
    cout<<setw(55)<<"------------------------------------"<<endl;
    cout<<endl;
    cout<<"WingsWeird Is Fashion Outlet For Womens With Best Dressing Sense. We Provide Number One Quality Dress In The Whole Country.";
    cout<<" You Can Desing Your Own Dress Or You Can Ask Our Designer To Desing A Dress For You And Get It Ready Within A Week.";
    cout<<"We Desing Our Own Product. Our Brand Is The Most Popular Brand In THe Whole World. It Is Our Pride To Serve You.";
    cout<<endl;
    cout<<endl;
    cout<<setw(55)<<"              How To Use              "<<endl;
    cout<<setw(55)<<"--------------------------------------"<<endl;
    cout<<endl;
    cout<<"To Select Options :- Enter The Number Assingned To It. "<<endl;
    cout<<"Incase Of Wrong Input The System Will Give You Another Try"<<endl;
    cout<<endl;
    cout<<"To Login Use The Username That Is Given To You."<<endl;
    cout<<"Only The Admin Can Create A User"<<endl;
    cout<<"Incase You Haved To Type The Incorrect Username And Password The System Will Give You Another Try."<<endl;
    cout<<"But The System Will Provide You With A Limitted Number OF Tries Due To Security Concerned.";
    cout<<"In That Case ShutDown The Whole System And Try Again."<<endl;
    cout<<"If You Have Forgot The Password. Contact Us."<<endl;
    cout<<endl;
    cout<<endl;
    cout<<setw(55)<<"              Contact Us              "<<endl;
    cout<<setw(55)<<"--------------------------------------"<<endl;
    cout<<endl;
    cout<<"We Are Here To Answer Any Question You May Have About Our WingsWeird POS Experiance. Reach Out To Us And We'll Respond As Soon As We Can."<<endl;
    cout<<endl;
    cout<<"Even If There Is Something Inconvenient In Using Our System, Let Us Know And We Promise We'll Do Our Best To Sort It Out For You."<<endl;
    cout<<endl;
    cout<<endl;
    cout<<setw(35)<<"Developer Of The System"<<endl;
    cout<<setw(35)<<"```````````````````````"<<endl;;
    cout<<endl;
    cout<<"Visit Us"<<endl;
    cout<<"Address:- 14/A Gampola Kandy"<<endl;
    cout<<endl;
    cout<<"Ring Us"<<endl;
    cout<<"Mobile  :- +94777555555"<<endl;
    cout<<"Tel/Fax :- 0814444444"<<endl;
    cout<<endl;
    cout<<"Mail Us"<<endl;
    cout<<"Amra@gmail.com";
    cout<<endl;
    cout<<"Do You Want To Return (Y/N)"<<endl;
    cin>>dec;
    switch(dec)
    {
        case 'Y':
        admin(pro,item,order,num);
        break;
        defualt:
        help();
        break;
    }
}

void exit()
{
    system("cls");
    char exit_op;
    header();
    cout<<endl;
    cout<<setw(55)<<"-------------------------------------"<<endl;
    cout<<setw(55)<<"              EXIT PAGE              "<<endl;;
    cout<<setw(55)<<"-------------------------------------"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Do You Really Want To Exit"<<endl;
    cout<<endl;
    cout<<setw(20)<<right<<" Yes (Y) "<<setw(10)<<right<<" No (N) ";
    cin>>exit_op;
    switch(exit_op)
    {
        case 'Y':
        system("cls");
        break;
        case 'N':
        main();
        break;
        default:
        cout<<"Invalid Input. Try Again"<<endl;
        exit();
        break;
    }
}

void c_exit()
{
    system("cls");
    user pro[100];
    inventory item[1000];
    bill order[1000];
    int num;
    fill_in_pro(pro);
    num=fill_in_pro(pro);
    char exit_op;
    header();
    cout<<endl;
    cout<<setw(55)<<"-------------------------------------"<<endl;
    cout<<setw(55)<<"              EXIT PAGE              "<<endl;;
    cout<<setw(55)<<"-------------------------------------"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Do You Really Want To Exit"<<endl;
    cout<<endl;
    cout<<setw(20)<<right<<" Yes (Y) "<<setw(10)<<right<<" No (N) ";
    cin>>exit_op;
    switch(exit_op)
    {
        case 'Y':
        system("cls");
        break;
        case 'N':
        cashier(pro,item,order,num);
        break;
        default:
        cout<<"Invalid Input. Try Again"<<endl;
        exit();
        break;
    }
}

void a_exit()
{
    system("cls");
    user pro[100];
    inventory item[1000];
    bill order[1000];
    int num;
    fill_in_pro(pro);
    num=fill_in_pro(pro);
    char exit_op;
    header();
    cout<<endl;
    cout<<setw(55)<<"-------------------------------------"<<endl;
    cout<<setw(55)<<"              EXIT PAGE              "<<endl;;
    cout<<setw(55)<<"-------------------------------------"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Do You Really Want To Exit"<<endl;
    cout<<endl;
    cout<<setw(20)<<right<<" Yes (Y) "<<setw(10)<<right<<" No (N) ";
    cin>>exit_op;
    switch(exit_op)
    {
        case 'Y':
        system("cls");
        break;
        case 'N':
        admin(pro,item,order,num);
        break;
        default:
        cout<<"Invalid Input. Try Again"<<endl;
        exit();
        break;
    }
}

void header()
{
    time_t t=time(0);
    struct tm *now = localtime(&t);
    cout<<endl;
    cout<<endl;
    cout<<setw(55)<<"________________________________________________________________________________________________________________________"<<endl;
    cout<<setw(55)<<"                                                                                                                     "<<endl;
    cout<<setw(55)<<"                                                      WINGSWEIRD                                                     "<<endl;
    cout<<setw(55)<<"                                               Fashoin Outlet For Womens                                             "<<endl;
    cout<<setw(55)<<"                            12/B Kandy Road Colombo / +94777222222 / WingsWeird@gmail.com                            "<<endl;
    cout<<setw(55)<<"________________________________________________________________________________________________________________________"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<setw(110)<<now->tm_year+1900;
    cout<<" / ";
    cout<<now->tm_mon+1;
    cout<<" / ";
    cout<<now->tm_mday<<endl;
    cout<<setw(109)<<now->tm_hour;
    cout<<" : ";
    cout<<now->tm_min;
    cout<<" : ";
    cout<<now->tm_sec<<endl;
    cout<<endl;
}