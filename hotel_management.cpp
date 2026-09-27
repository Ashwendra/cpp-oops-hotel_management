
//hotel management system

#include<iostream>
#include<vector>
#include<string>
using namespace std;
class hotel{
	private:
		int roomno;
		string name;
		int days;
		float bill;
	public:
		void setdata(int r,string n,int d,float b){
			roomno=r;
			name=n;
			days=d;
			bill=b;
		}
		void setroom(int r){
			roomno=r;
		}
		void setname(string n){
			name=n;
		}
		void setday(int d){
			days=d;
		}
		void setbill(float b){
			bill=b;
		}
		int getroom(){
			return roomno;
		}
		string getname(){
			return name;
		}
		int getday(){
			return days;
		}
		float getbill(){
			return bill;
		}
		void display(){
			cout<<"room number is"<<roomno<<endl;
			cout<<"name of customer "<<name<<endl;
			cout<<"number of days"<<days<<endl;
			cout<<"total bill"<<bill<<endl;
			
		}	
};
main(){
	vector<hotel> hotels;
	int choice;
	char op;
	do{
		cout<<"==== hotel management system====="<<endl;
		cout<<"1.add customer detail"<<endl;
		cout<<"2.display all customers"<<endl;
		cout<<"3.search customer"<<endl;
		cout<<"4.update customer details"<<endl;
		cout<<"5.delete customer record"<<endl;
		cout<<"6.room booking"<<endl;
		cout<<"7.room checkout"<<endl;
		cout<<"enter your choice"<<endl;
		cin>>choice;
		switch(choice){
			case 1:{
				hotel h;
				int roomno;
				string name;
				int days;
				float bill;
				cout<<"enter room number "<<endl;
				cin>>roomno;
				cout<<"enter name of customer"<<endl;
				cin.ignore();
				getline(cin,name);
				cout<<"number of days"<<endl;
				cin>>days;
				cout<<"total bill"<<endl;
				cin>>bill;
				h.setdata(roomno,name,days,bill);
				hotels.push_back(h);
				cout<<"customer detail added successfully"<<endl;
				break;
			}
			case 2:{
				if(hotels.empty()){
					cout<<"record not found"<<endl;
					
				}
				else{
					for(int i=0;i<hotels.size();i++){
						hotels[i].display();
					}
				}
				break;
			}
			case 3:{
				string name;
				cout<<"enter name to search"<<endl;
				cin.ignore();
				getline(cin,name);
				bool found=false;
				for (int i=0;hotels.size();i++){
					if (hotels[i].getname()==name){
						cout<<"customer detail found"<<endl;
						hotels[i].display();
					}
				}
				if (!found){
					cout<<"record not found"<<endl;
				}
				break;
			}
			case 4:{
				string name;
				cout<<"enter customer name"<<endl;
				cin.ignore();
				getline(cin,name);
				bool found=false;
				for(int i=0;i<hotels.size();i++){
					if(hotels[i].getname()==name){
						int roomno;
						int days;
						float bill;
						cout<<"enter new new roomno"<<endl;
						cin>>roomno;
						cout<<"enter new number of days"<<endl;
						cin>>days;
						cout<<"enter new bill"<<endl;
						cin>>bill;
						hotels[i].setroom(roomno);
						hotels[i].setday(days);
						hotels[i].setbill(bill);
						cout<<"customer detail updated successfully"<<endl;
						found=true;
						
					}
				}
				if (!found){
					cout<<"record not founded"<<endl;
				}
				break;
			}
			case 5:{
				string name;
				cout<<"enter customer name "<<endl;
				cin.ignore();
				getline(cin,name);
				bool found=false;
				for(int i=0;i<hotels.size();i++){
					if (hotels[i].getname()==name){
						hotels.erase(hotels.begin()+i);
						cout<<"details deleted successfully"<<endl;
						found=true;
					}
				}
				if (!found){
					cout<<"record not found"<<endl;
				}
				break;
				}
			case 6:{
				int roomno;
				cout<<"enter room number for checkout"<<endl;
				cin>>roomno;
				bool found=false;
				for(int i=0;i<hotels.size();i++){
					if (hotels[i].getroom()==roomno){
						cout<<"checkout receipt"<<endl;
						hotels[i].display();
						cout<<"total bill"<<endl;
						hotels[i].getbill();
						cout<<"checkout successfully"<<endl;
					}
				}
				break;
			}			
		}
		cout<<"do you continue [yes/no]"<<endl;
		cin>>op;
		
	}
	while(op=='y' || op=='Y');
	
}
