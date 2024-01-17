#include <iostream>
#include<iomanip>
#include<string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class product
{
	private:
		char name[21];
		double price;
		int score;
		/*Private members:
        name: an array of characters representing the name of the product.
        price: a double representing the price of the product.
        score: an integer representing the score of the product.*/
	public:
		product();
		void read();
		void print() const;
		bool is_better_from(product const&)const;
		double get_price() const;
		int get_score() const;
		/*Public member functions:
        product(): default constructor.
        void read(): reads input values for the product.
        void print() const: prints the product details.
        bool is_better_from(product const&) const: compares two products based on their score-to-price ratio.
        double get_price() const: returns the price of the product.
        int get_score() const: returns the score of the product.*/
		
};

void sorttable(int n, product*[]);
/*sorttable function:
Takes an integer n and an array of pointers to product objects.
Sorts the array of pointers based on the is_better_from comparison function, using selection sort.*/
using namespace std;
int main(int argc, char** argv) {
	cout<< setprecision(4)<< setiosflags(ios::fixed);
	product table[300];
	product*ptable[300];
	int n;
	
	do
	{
		cout<<"number of products?";
		cin>>n;
	}
	while(n<1||n>300);
	int i;
	for(i=0;i<n-1;i++)
	{
		table[i].read();
		ptable[i]=&table[i];
	}
	cout<<"table:\n";
	for(i=0;i<=n-1;i++)
	{
		table[i].print();
		cout<<endl;
	}
	sorttable(n,ptable);
	cout<<"\n New Table: \n";
	for(i=0;i<=n-1;i++)
	{
		ptable[i]->print();
		cout<<setw(7)<<ptable[i]->get_score()/ptable[i]->get_price()<<endl;
	}
	return 0;
	/*main function:
    Takes user input for the number of products (between 1 and 300).
    Reads product information into an array of product objects.
    Creates an array of pointers to products (ptable) and initializes it with addresses of the corresponding products.
    Prints the original table of products.
    Calls the sorttable function to sort the table based on the custom comparison function.
    Prints the sorted table along with the calculated score-to-price ratio for each product.*/
}

void product::read()
{
	cout<<"name: ";
	cin>>name;
	cout<<"price: ";
	cin>> price;
	cout<<"score: ";
	cin>>score;
}
void product::print()const
{
	cout<<setw(25)<<name
	<<setw(10)<<price
	<<setw(12)<<score;
}
bool product::is_better_from(product const& x)const
{
	return score/price > x.score/x.price;
}
double product::get_price()const
{
	return price;
}
int product::get_score()const
{
	return score;
}
void sorttable(int n,product*a[])
{
	for(int i;int i<=n-2;i++)
	{
		int k=i;
		product*max=a[i];
		for(int j=i+1;j<=n-1;j++)
		{
			if((*a[j]).is_better_from((*max)))
			{
				max=a[j];
				k=j;
			}
		}
		max=a[i];a[i]=a[k];a[k]=max;
	}
}






