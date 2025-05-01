#include<iostream>
#include<string> 
#include<iomanip>
#include<fstream>
#include <cstdlib> //utility funtions
#include <ctime>

using namespace std;

struct shopping{ // structure = user define data type
	
	char choice;
    string name[10];
    int price[10];
    int quantity[10];
    double total[10];
    double total_price;
    int i;
};
struct order{
	string location;
	string city;
	string homeadress;
};
struct payment
{
	int zipcode;
	string ph_no;
	int balance;
	string acc_no;
	string cvv;
	
};
struct user
{
	string google_id;
	string password;
	string username;
	
	
	
};

shopping c; // shopping = structure , c = his object;

string generatePassword(int length) {
    const string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string lowercase = "abcdefghijklmnopqrstuvwxyz";
    const string digits = "0123456789";
    const string specialChars = "!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?";
    const string allChars = uppercase + lowercase + digits + specialChars;

    string password = "";
    srand(time(0));

    for (int i = 0; i < length; i++) {
        int randomIndex = rand() % allChars.length();
        password += allChars[randomIndex];
    }

    return password;
}
void registerUser(user& a) {
	cout<<setw(35)<<setfill('-')<<" "<<setfill(' ')<<endl;
	int length;
	
    cout << "Welcome to the online shopping store  (-_-) " << endl;
    cout << "Please enter your email/phone number: ";
    cin.ignore();  
    getline(cin, a.google_id);
    cout << "Please enter your username: ";
    getline(cin, a.username);
    
    cout << "Please enter the length of your password: ";
    cin>>length;
    cout<<endl;
	a.password=generatePassword(length);
	
	cout<<"Your unique passworsd is="<<a.password<<endl;
	cout<<endl;
	cout<<"Your account has been succesfully created\n\n"<<endl;
	
}
    
  



void signin(user& a) {
    int choice, n;
    cout << setw(35) << setfill('-') << " " << setfill(' ') << endl;
    string name;
    string password;

    cout << "Please enter your Google ID for login: ";
    cin.ignore();
    getline(cin, name);
    if (name != a.google_id) {
        cout << "You entered the wrong ID! Please try again." << endl;
        return ;
    }

    cout << "Please enter your password: ";
    getline(cin, password);
    if (password != a.password) {
        cout << "You entered the wrong password! Please try again!\n\n" << endl;
        cout << "Please select one of the choices:\n";
        cout << "1) Forgot password\n";
        cout << "2) Return\n";
        cout << "Please enter the choice: ";
        cin >> choice;

        if (choice == 1) {
        	cout<<endl;
            cout << "Your password is: " << a.password << endl;
            cout << "1) Do you want to create your own password?\n";
            cout << "2) Return\n";
            cout << "Please select one of the choices: ";
            cin >> n;
            cin.ignore(); // Clear buffer
            if (n == 1) {
                cout << "Please enter your new password: ";
                getline(cin, a.password);
                system("cls");
            } else if (n == 2) {
                return;
            }
        } else if (choice == 2) {
            return;
        }
    } else {
        cout << "Successfully logged in!" << endl;
        system("cls");
    }
}
void profile(user& a)
{
	system("cls");
	cout<<setw(35)<<setfill('-')<<" "<<setfill(' ')<<endl;
	
	cout<<"your google id is="<<a.google_id<<endl;
	cout<<"your user name="<<a.username<<endl;
    cout<<endl;

}
void payment_setting(payment& a)
{
	cout<<setw(35)<<setfill('-')<<" "<<setfill(' ')<<endl;
	int choice;
	cout<<"please selected one the following payment option:\n"<<endl;
	cout<<"1)JazzCash"<<endl;
	cout<<"2)Easy paisa"<<endl;
	cout<<"3)Nayapay"<<endl;
	cout<<"4)online banking account\n"<<endl;
	cout<<"please enter your choice:";
	cin>>choice;
	cout<<setw(35)<<setfill('-')<<" "<<setfill(' ')<<endl;
	switch(choice)
	{
		case 1:
			cout<<"please enter your jazzcash account no:   ";
            cin.ignore();
            getline(cin,a.ph_no);
            cout<<"please enter your zip code:             ";
            cin>>a.zipcode;
            cout<<"please enter your balance:              ";
            cin>>a.balance;	
            break;
        case 2:
        	cout<<"please enter Easypaisa  account no:    ";
            cin.ignore();
            getline(cin,a.ph_no);
            cout<<"please enter your zip code:           ";
            cin>>a.zipcode;
            cout<<"please enter your balance:            ";
            cin>>a.balance;	
            break;
        case 3:
        	cout<<"please enter nayapay  account no:    ";
            cin.ignore();
            getline(cin,a.ph_no);
            cout<<"please enter your zip code:          ";
            cin>>a.zipcode;
            cout<<"please enter your balance:           ";
            cin>>a.balance;	
            break;
        case 4:
        	cout<<"please enter mobile banking account no with dashes(-)  :";
            cin.ignore();
            getline(cin,a.ph_no);
            cout<<"please enter your 3 digit CVV code:                     ";
            cin>>a.cvv;
            cout<<"please enter your balance:                             ";
            cin>>a.balance;	
            break;
        default:
        	cout<<"You entered wrong choice please try again."<<endl;
        	return;
        	break;
    }
			
}
	



void order_tracing(order& f)
{
	cout<<setw(35)<<setfill('-')<<" "<<setfill(' ')<<endl;
	cout<<"please enter the location:                     ";
	cin.ignore();
	getline(cin,f.location);
	cout<<"please enter your city:                        ";
	getline(cin,f.city);
	cout<<"please enter the homeadress with comma(,):     ";
	cin.ignore();
	getline(cin,f.homeadress);
	cout<<"according to your location your order will delivered you in 24 hours"<<endl;
	cout<<setw(35)<<setfill('-')<<" "<<setfill(' ')<<endl;
}
void change_password(user a)
{
	cout<<setw(35)<<setfill('-')<<" "<<setfill(' ')<<endl;
	
    string password;
    cout<<"please enter your previous password:";
    cin>>password;
    if(password==a.password)
    {
      cout<<"please enter your password:";
      cin>>a.password;
      cout<<"Successfully changed password -_-  "<<endl;
    }
    else
    cout<<"your enterd the wrong password!! please try again.."<<endl;
}
    
    
    void shopping_items(shopping& c)
{
	cout<<setw(35)<<setfill('-')<<" "<<setfill(' ')<<endl;
	    c.i=0;
	    int n;
	    double groceryPrices[] = {10, 30, 40,50,60}; 
        double clothingPrices[] = {10.0, 20.0,30.0,40.0,50.0};    
        double bakeryPrices[] = {8, 9,10,11,12};        
        double mobileAccessoriesPrices[] = {5.0, 7.0,8.0,9.0,10.0};
	    
    do {
    c.i++;
    if (c.i >= 10) {
        cout << "You reached your maximum limit!!\n\n" << endl;
        return;
    }
    cout << "Please select one of the following options:\n" << endl;
    cout << "1. Grocery items" << endl;
    cout << "2. Clothing items" << endl;
    cout << "3. Bakery items" << endl;
    cout << "4. Mobile accessories" << endl;
    cout << "5. Exit\n" << endl;
    cout << "Please enter your choice: ";
    cin >> c.choice;
    switch (c.choice) {
        case '1': 
            cout << "Available grocery items:\n" << endl;
            cout << "1. Apples    - $10" << endl;
            cout << "2. Bananas   - $30" << endl;
            cout << "3. Oranges   - $40" << endl;
            cout << "4. Strawberry - $50" << endl;
            cout << "5. Blueberry - $60\n" << endl;
            cout << "Please enter the choice: ";
            cin >> n;
            if (n == 1) {
                c.price[c.i] = groceryPrices[0];
                c.name[c.i] = "Apples";
                cout << "Please enter the quantity: ";
                cin >> c.quantity[c.i];
                c.total[c.i] = c.quantity[c.i] * c.price[c.i];  
                system("cls");
            }
            else if (n == 2) {
                c.price[c.i] = groceryPrices[1];
                c.name[c.i] = "Bananas";
                cout << "Please enter the quantity: ";
                cin >> c.quantity[c.i];
                c.total[c.i] = c.quantity[c.i] * c.price[c.i];
				system("cls");  
            }
            else if (n == 3) {
                c.price[c.i] = groceryPrices[2];
                c.name[c.i] = "Oranges";
                cout << "Please enter the quantity: ";
                cin >> c.quantity[c.i];
                c.total[c.i] = c.quantity[c.i] * c.price[c.i]; 
				system("cls"); 
            }
            else if (n == 4) {
                c.price[c.i] = groceryPrices[3];
                c.name[c.i] = "Strawberry";
                cout << "Please enter the quantity: ";
                cin >> c.quantity[c.i];
                c.total[c.i] = c.quantity[c.i] * c.price[c.i];  
                system("cls");
            }
            else if (n == 5) {
                c.price[c.i] = groceryPrices[4];
                c.name[c.i] = "Blueberry";
                cout << "Please enter the quantity: ";
                cin >> c.quantity[c.i];
                c.total[c.i] = c.quantity[c.i] * c.price[c.i]; 
				system("cls"); 
            }
            else {
                cout << "You entered the wrong choice!!" << endl;
                return;
            }
            break;

        case '2': 
            cout << "Available clothing items:\n" << endl;
            cout << "1. T-Shirt    - $10" << endl;
            cout << "2. Jeans      - $20" << endl;
            cout << "3. Swimwear   - $30" << endl;
            cout << "4. Pajamas    - $40" << endl;
            cout << "5. Dress      - $50" << endl;
            cout << "Please enter the choice: ";
            cin >> n;
            if (n == 1) {
                c.price[c.i] = clothingPrices[0];
                c.name[c.i] = "T-Shirt";
                cout << "Please enter the quantity: ";
                cin >> c.quantity[c.i];
                c.total[c.i] = c.quantity[c.i] * c.price[c.i];  
                system("cls");
            }
            else if (n == 2) {
                c.price[c.i] = clothingPrices[1];
                c.name[c.i] = "Jeans";
                cout << "Please enter the quantity: ";
                cin >> c.quantity[c.i];
                c.total[c.i] = c.quantity[c.i] * c.price[c.i];  
                system("cls");
            }
            else if (n == 3) {
                c.price[c.i] = clothingPrices[2];
                c.name[c.i] = "Swimwear";
                cout << "Please enter the quantity: ";
                cin >> c.quantity[c.i];
                c.total[c.i] = c.quantity[c.i] * c.price[c.i];  
                system("cls");
            }
            else if (n == 4) {
                c.price[c.i] = clothingPrices[3];
                c.name[c.i] = "Pajamas";
                cout << "Please enter the quantity: ";
                cin >> c.quantity[c.i];
                c.total[c.i] = c.quantity[c.i] * c.price[c.i]; 
				system("cls"); 
            }
            else if (n == 5) {
                c.price[c.i] = clothingPrices[4];
                c.name[c.i] = "Dress";
                cout << "Please enter the quantity: ";
                cin >> c.quantity[c.i];
                c.total[c.i] = c.quantity[c.i] * c.price[c.i];  
                system("cls");
            }
            else {
                cout << "You entered the wrong choice!!" << endl;
                return;
            }
            break;

        case '3': 
            cout << "Available bakery items:" << endl;
            cout << "1. Bread     - $8" << endl;
            cout << "2. Croissant - $9" << endl;
            cout << "3. Pastries  - $10" << endl;
            cout << "4. Cakes     - $11" << endl;
            cout << "5. Donuts    - $12" << endl;
            cout << "Please enter the choice: ";
            cin >> n;
            if (n == 1) {
                c.price[c.i] = bakeryPrices[0];
                c.name[c.i] = "Bread";
                cout << "Please enter the quantity: ";
                cin >> c.quantity[c.i];
                c.total[c.i] = c.quantity[c.i] * c.price[c.i]; 
				system("cls"); 
            }
            else if (n == 2) {
                c.price[c.i] = bakeryPrices[1];
                c.name[c.i] = "Croissant";
                cout << "Please enter the quantity: ";
                cin >> c.quantity[c.i];
                c.total[c.i] = c.quantity[c.i] * c.price[c.i];  
                system("cls");
            }
            else if (n == 3) {
                c.price[c.i] = bakeryPrices[2];
                c.name[c.i] = "Pastries";
                cout << "Please enter the quantity: ";
                cin >> c.quantity[c.i];
                c.total[c.i] = c.quantity[c.i] * c.price[c.i]; 
				system("cls"); 
            }
            else if (n == 4) {
                c.price[c.i] = bakeryPrices[3];
                c.name[c.i] = "Cakes";
                cout << "Please enter the quantity: ";
                cin >> c.quantity[c.i];
                c.total[c.i] = c.quantity[c.i] * c.price[c.i];  
                system("cls");
            }
            else if (n == 5) {
                c.price[c.i] = bakeryPrices[4];
                c.name[c.i] = "Donuts";
                cout << "Please enter the quantity: ";
                cin >> c.quantity[c.i];
                c.total[c.i] = c.quantity[c.i] * c.price[c.i];  
                system("cls");
            }
            else {
                cout << "You entered the wrong choice!!" << endl;
                return;
            }
            break;

        case '4': 
            cout << "Available mobile accessories:" << endl;
            cout << "1. Phone case    - $5" << endl;
            cout << "2. Earphones     - $7" << endl;
            cout << "3. Power Bank    - $8" << endl;
            cout << "4. Cases         - $9" << endl;
            cout << "5. HeadPhones    - $10" << endl;
            cout << "Please enter the choice: ";
            cin >> n;
            if (n == 1) {
                c.price[c.i] = mobileAccessoriesPrices[0];
                c.name[c.i] = "Phone Case";
                cout << "Please enter the quantity: ";
                cin >> c.quantity[c.i];
                c.total[c.i] = c.quantity[c.i] * c.price[c.i];
				system("cls");  
            }
            else if (n == 2) {
                c.price[c.i] = mobileAccessoriesPrices[1];
                c.name[c.i] = "Earphones";
                cout << "Please enter the quantity: ";
                cin >> c.quantity[c.i];
                c.total[c.i] = c.quantity[c.i] * c.price[c.i];  
                system("cls");
            }
            else if (n == 3) {
                c.price[c.i] = mobileAccessoriesPrices[2];
                c.name[c.i] = "Power Bank";
                cout << "Please enter the quantity: ";
                cin >> c.quantity[c.i];
                c.total[c.i] = c.quantity[c.i] * c.price[c.i]; 
				system("cls");
				 
            }
            else if (n == 4) {
                c.price[c.i] = mobileAccessoriesPrices[3];
                c.name[c.i] = "Cases";
                cout << "Please enter the quantity: ";
                cin >> c.quantity[c.i];
                c.total[c.i] = c.quantity[c.i] * c.price[c.i]; 
				system("cls"); 
            }
            else if (n == 5) {
                c.price[c.i] = mobileAccessoriesPrices[4];
                c.name[c.i] = "Headphones";
                cout << "Please enter the quantity: ";
                cin >> c.quantity[c.i];
                c.total[c.i] = c.quantity[c.i] * c.price[c.i];
				system("cls");  
            }
            else {
                cout << "You entered the wrong choice!!" << endl;
                return;
            }
            break;

        case '5':
            cout << "Exiting the system!" << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
            break;
    } 
} while (c.choice != '5');

     

cout<<setw(40)<<setfill('-')<<" "<<setfill(' ')<<endl;
}
double total_calculation(shopping& c)
{
	cout<<setw(35)<<setfill('-')<<" "<<setfill(' ')<<endl;
    c.total_price = 0; 

    
    for (int i = 0; i < 10; i++)  
    {
        c.total_price += c.total[i];  
    }

    return c.total_price;
    system("cls");
}
void check_out(shopping &c,payment& a)
{
	cout<<setw(35)<<setfill('-')<<" "<<setfill(' ')<<endl;
	int order=0;
	int choice;
	cout<<"Your balance in your account is=$"<<a.balance<<endl;
	    cout<<"Your total payment is="<<c.total_price;
	cout<<"please enter one of the following chocies\n\n"<<endl;
	cout<<"1) for check out"<<endl;
	cout<<"2) edit your balance"<<endl;
	cin>>choice;
	if(choice==1)
	{
		if(c.total_price<a.balance)
		{
			order=a.balance-c.total_price;
			cout<<"Your remaining balance is="<<order<<endl;
			cout<<"Sucessfully check out! Thankyou dor chosing us(-_-)"<<endl;
			for(int i=0;i<10;i++)
			{
				c.price[i]=0;
				c.price[i]=0;
				c.total_price=0;
				c.total[i]=0;
			}
		}
		else
		{
		
	    cout<<"Your balance is less than your payment please add balance!!"<<endl;
	    return;
	   }
	}
	if(choice==2)
	{
         cout<<"your account no:"<<a.ph_no<<endl;
         cout<<"Your balance is $"<<a.balance;
         cout<<"please enter your new balance $:";
         cin>>a.balance;
         cout<<"your Balance is successfully updated"<<endl;
	}
	else
	{cout<<"You entered the wrong choice"<<endl;
	return;
    }
    system("cls");
}
void history_cart(shopping c) 
{
    
    ofstream history_file("purchase_history.txt", ios::app);
    history_file << "Shopping Cart:" << endl;
     for (int j = 0; j<c.i; j++) 
	 {
        cout << left << setw(20) << c.name[j]
             << setw(12) << c.quantity[j]
             << setw(15) << fixed << setprecision(2) << c.price[j]
             << setw(15) << fixed << setprecision(2) << c.total[j] << endl;
        
    }

    history_file << "Total Price: " << c.total_price << endl;
    history_file << "--------------------------------------------" << endl;
    history_file.close();
}

void display_cart(shopping c) {
    cout << setw(35) << setfill('-') << " " << setfill(' ') << endl;
    cout << "Shopping Cart:" << endl;
    cout << "--------------------------------------------" << endl;

    
    cout << "Product     |" << "quantity    |       price   |     total     | " << endl;
     for (int j = 0; j < c.i; j++) {
        cout << left << setw(20) << c.name[j]
             << setw(12) << c.quantity[j]
             << setw(15) << fixed << setprecision(2) << c.price[j]
             << setw(15) << fixed << setprecision(2) << c.total[j] << endl;
   
    }
    cout << setw(35) << setfill('-') << " " << setfill(' ') << endl;

    
}



 int main()
 {
 	int i;
    int choice;
    user b;
    payment c;
    shopping d;
    int e;
    order a;

    cout << " OOO   N   N  L        III  N   N  EEEEE       SSS  H   H  OOO  PPPP  PPPP   III  N   N   GGG         SSS  TTTTT  OOO  RRRR   EEEEE" << endl;
    cout << "O   O  NN  N  L         I   NN  N  E           S    H   H O   O P   P P   P   I   NN  N  G            S      T   O   O R   R  E     " << endl;
    cout << "O   O  N N N  L         I   N N N  EEEE        SSS  HHHHH O   O PPPP  PPPP    I   N N N  G  GG        SSS    T   O   O RRRR   EEEE" << endl;
    cout << "O   O  N  NN  L         I   N  NN  E             S  H   H O   O P     P       I   N  NN  G   G          S    T   O   O R  R   E     " << endl;
    cout << " OOO   N   N  LLLLL    III  N   N  EEEEE       SSS  H   H  OOO  P     P      III  N   N   GGG         SSS    T    OOO  R   R  EEEEE" << endl;

    


    


    do{
    cout<<"1.register "<<endl;
    cout<<"2.sign in "<<endl;
    cout<<"3.profile  "<<endl;
    cout<<"4.payment setting"<<endl;
    cout<<"5.order tracing"<<endl;
    cout<<"6.online shopping"<<endl;
    cout<<"7.change password"<<endl;
    cout<<"8.Total price"<<endl;
    cout<<"9.Check out"<<endl; 
    cout<<"10.Cart"<<endl;
    cout<<"11.History of cart"<<endl;
    cout<<"12.exit"<<endl;
    cout<<"please enter the code above(1~11):";
    
    
	cin>>choice;
	  system("cls");
    if(choice==1)
    {
    	system("cls"); 
        registerUser(b);
     
}
    else if(choice==2)
    {
    	system("cls"); 
        signin(b);
          
    }
    else if(choice==3)
    {
    	system("cls");
        profile(b);
          
    }
    else if(choice==4)
    {
    	system("cls"); 
         payment_setting(c);
         system("cls");
          
	}
    else if(choice==5)
       
    {
    	system("cls"); 
        order_tracing(a);
         
    }
    else if(choice==6)
    {
    	system("cls"); 
        shopping_items(d);
           
    }
    else if(choice==7)
    {
    	system("cls"); 
        change_password(b);
          
    }
    else if(choice==8)
    {
    	system("cls"); 
        e=total_calculation(d);
        
        cout<<"The total price=$"<<e<<endl; 
          
    }
    else if(choice==9)
    {
    	system("cls"); 
    	check_out(d,c);
    	   
	}
	else if(choice==10)
	{
		system("cls"); 
		display_cart(d);
		  
	}
     else if(choice==11)
    {
	    system("cls"); 
        cout<<setw(35)<<setfill('-')<<" "<<setfill(' ')<<endl;	
        history_cart(d);
          
    }
    else if(choice==12)
    {
    	cout<<"Exiting the system"<<endl;
    	
	}
    else
    cout<<"please enter choices between(1~12)"<<endl;
    }while(choice!=12);
    system("pause");
    return 0;
    
    
    
}//system cls;

