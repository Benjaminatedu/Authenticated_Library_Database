#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>

using namespace std;

// IsLoggedIn Function returns true or false 
bool IsLoggedIn()
   {
      string user, pass, un, pw;

	  // Get User Input
      cout << "Username: "; cin >> user;
      cout << "Password: "; cin >> pass;
	  
	  //Search Files for User Information
      ifstream read(user + ".txt");
      getline(read, un);
      getline(read, pw);

      if (un == user && pw == pass)
      {
         return true;
      }
      else
      {
         return false;
      }
   }

   bool authenticate()
   {
      int choice;

	  // Get User Input
      cout << "1: Register\n2: Login\nYour Choice: "; cin >> choice;

      if (choice == 1)
      {
         string username, password;

		 // Get User Input
         cout << "Select a Username : "; cin >> username;
         cout << "Select a Password : "; cin >> password;

		 //Create ".txt" file using the username as filename
         ofstream file;
         file.open(username + ".txt");
		 //Write to ".txt" file
         file << username << endl << password;
         file.close();

         authenticate();
      }
	  //If user input not authenticated, end program
      else if (choice == 2)
      {
         bool status = IsLoggedIn();

         if (!status)
         {
               cout << "!False Login!" << endl;
			   return false;
         }
         else
         {
               cout << "Login Successful!" << endl;
			   return true;
         }
      }
	  else
	  {
		return false;
	  }
}


//Create "Book" class and all variables.
class Book	{
private:
	char *author,*title,*publisher;
	float *price;
	int *stock;
public:	
	Book()	{
	author= new char[20];
	title=new char[20];
	publisher=new char[20];
	price= new float;
	stock=new int;
	}
	//Instantiate functions
	void feeddata();
	void editdata();
	void showdata();
	int search(char[],char[]);
	void buybook();
	
};

//Populates Book variables
void Book::feeddata()	{

	// Get User Input
	cin.ignore();
	cout<<"\nEnter The Authors Name: ";    cin.getline(author,20);
	cout<<"Enter the Title Name";       cin.getline(title,20);
	cout<<"Enter the Publisher's Name";   cin.getline(publisher,20);
	cout<<"Enter Price: ";            cin>>*price;
	cout<<"Enter the Stock Position";   cin>>*stock;   
	
}

//Edits Book variables
void Book::editdata()	{
	
	// Get User Input
	cout<<"\nEnter The Authors Name: ";    cin.getline(author,20);
	cout<<"Enter the Title Name";       cin.getline(title,20);
	cout<<"Enter the Publisher's Name";   cin.getline(publisher,20);
	cout<<"Enter Price: ";            cin>>*price;
	cout<<"Enter the Stock Position";   cin>>*stock;   
	
}

//Displays variable values
void Book::showdata()	{

	// Get User Input
	cout<<"\nAuthor Name: "<<author;
	cout<<"\nTitle Name: "<<title;
	cout<<"\nPublisher Name: "<<publisher;
	cout<<"\nPrice: "<<*price;
	cout<<"\nStock Position: "<<*stock;   
	
}

//Searches for Book using user input
int Book::search(char tbuy[20],char abuy[20] )	{
	if(strcmp(tbuy,title)==0 && strcmp(abuy,author)==0)
		return 1;
	else return 0;
		
}

//Removes Book from stock
void Book::buybook()	{
	int count;

	// Get User Input
	cout<<"\nEnter Number Of Books to buy: ";
	cin>>count;
	if(count<=*stock)	{
		*stock=*stock-count;
		cout<<"\nBooks Bought Sucessfully";
		cout<<"\nAmount: Rs. "<<(*price)*count;
	}
	else
		cout<<"\nRequired Copies not in Stock";
}

//Prompts user for action to perform
int run()	{
	Book *B[20];
	int i=0,r,t,choice;
	char titlebuy[20],authorbuy[20];
	while(1)	{

		// Get User Input
		cout<<"\n\n\t\tMENU"
		<<"\n1. Add a New Book"
		<<"\n2. Buy a Book"
		<<"\n3. Search For a Book"
		<<"\n4. Edit The Details Of a Book"
		<<"\n5. Exit This Program"
		<<"\n\nPlease Enter a Choice: ";
		cin>>choice;
		
		switch(choice)	{
			case 1:	B[i] = new Book;
				B[i]->feeddata();
				i++;	break;
				
			case 2: cin.ignore();

				// Get User Input
				cout<<"\nEnter The Title Of  The Book: "; cin.getline(titlebuy,20);
				cout<<"Enter The Author Of The Book: ";  cin.getline(authorbuy,20);
				for(t=0;t<i;t++)	{
					if(B[t]->search(titlebuy,authorbuy))	{
						B[t]->buybook();
						break;
					}
				}

				if(t==1)
				cout<<"\nThis Book is not Available";
				
				break;
			case 3: cin.ignore();

				// Get User Input
				cout<<"\nEnter The Title Of The Book: "; cin.getline(titlebuy,20);
				cout<<"Enter The Author Of  The Book: ";  cin.getline(authorbuy,20);
				
				for(t=0;t<i;t++)	{
					if(B[t]->search(titlebuy,authorbuy))	{
						cout<<"\nBook Located";
						B[t]->showdata();
						break;
					}
				}

				if(t==i)
				cout<<"\nThis Book is Not Available";
				break;
			
			case 4: cin.ignore();

				// Get User Input
				cout<<"\nEnter Title Of Book: "; cin.getline(titlebuy,20);
				cout<<"Enter Author Of Book: ";  cin.getline(authorbuy,20);
				
				for(t=0;t<i;t++)	{
					if(B[t]->search(titlebuy,authorbuy))	{
						cout<<"\nBook Located";
						B[t]->editdata();
						break;
					}
				}

				if(t==i)
				cout<<"\nThis Book is Not Available";
				break;
			
			case 5: exit(0);
			default: cout<<"\nInvalid Choice Entered";
			
		}
	}
	
	
	
	
	return 0;
}

//Run authentication. If authenticated, run Book program.
int main(){
	if (authenticate()){
		run();
	}
	return 0;
}