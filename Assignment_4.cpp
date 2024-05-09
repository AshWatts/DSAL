/*	Consider telephone book database of N clients. Make use of a hash
	table implementation to quickly look up client’s telephone number.
	Make use of two collision handling techniques and compare them using
	number of comparisons required to find a set of telephone numbers
	(Note: Use linear probing with replacement and without replacement) 	*/
#include <bits/stdc++.h>
using namespace std;

class Record{
public:
	char name[10];
	long int Telephone;
};

class HashTable{
private:
	Record HT1[10];
	Record HT2[10];
	int TableSize=10;
public:
	HashTable (){
		for(int i=0; i< TableSize; i++){
			HT1[i].Telephone=0;
			strcpy(HT1[i].name, "--");
		}
		for(int i=0; i< TableSize; i++){
			HT2[i].Telephone=0;
			strcpy(HT2[i].name, "--");
		}
	}
	//without replacement
	void create_HT1(){
		int ASCII;
		char Name[10];
		long int tele;
		bool check=false;
		int index;
		for(int i=0; i<TableSize; i++){
			ASCII =0;
			cout<<"Enter name of client: ";
			cin>>Name;
			cout<<"Enter telephone number of client: ";
			cin>>tele;
			for(int j=0; Name[j]!='\0'; j++){
				ASCII=ASCII + Name[j];
			}
			index=ASCII %TableSize;
			check=false;
			while(check!= true){
				if(HT1[index].Telephone==0){
					strcpy(HT1[index].name, Name);
					HT1[index].Telephone=tele;
					check=true;
				}
				else{
					while(HT1[index].Telephone !=0)
						index=(index+1)%TableSize;
				}
			}
		}
	}
	//with replacement
	void create_HT2(){
        int ASCII;
        int index1;
        int index2;
        char Name[10];
        long int tele;
        bool check;
        for(int i=0; i<TableSize;i++){
            ASCII=0;
            cout<<"Enter name of client: ";
            cin>>Name;
            cout<<"Enter telephone number of client: ";
            cin>>tele;
            for(int j=0; Name[j]!='\0';j++){
                ASCII =ASCII + Name[j];
            }
            index1= ASCII % TableSize;
            if(HT2[index1].Telephone==0){
                strcpy(HT2[index1].name, Name);
                HT2[index1].Telephone=tele;
                //display(); //display
            }
            else{
                ASCII=0;
                for(int j=0; HT2[index1].name[j]!='\0';j++){
                    ASCII=ASCII +HT2[index1].name[j];
                }
                index2=ASCII % TableSize;
                if(index1==index2){
                    check=false;
                    while(check==false){
                        if(HT2[index1].Telephone==0){
                            strcpy(HT2[index1].name, Name);
                            HT2[index1].Telephone=tele;
                            check=true;
                            //display(); //display
                        }
                        else{
                            while(HT2[index1].Telephone!=0)
                                index1=(index1 +1)%TableSize;
                        }
                    }
                }else{
                    //temporary retrieval of past client
                    char temp_name[10];
                    long int temp_tele=HT2[index1].Telephone;
                    strcpy(temp_name, HT2[index1].name);
                    //placing new client at its correct position
                    strcpy(HT2[index1].name, Name);
                    HT2[index1].Telephone=tele;
                    //finding next suitable place for new client
                    check=false;
                    while(check==false){
                        if(HT2[index1].Telephone==0){
                            strcpy(HT2[index1].name, temp_name);
                            HT2[index1].Telephone=temp_tele;
                            check=true;
                            //display(); //display
                        }
                        else{
                            while(HT2[index1].Telephone !=0)
                                index1=(index1 +1)%TableSize;
                        }
                    }
                }
            }
        }
	}
	//display common for both hash tables
	void display(){
        cout<<"Which Table do you want to display? [Enter 0 for HT1 OR 1 for HT2] :";
        int key;
        cin>>key;
        if(key==0){
            cout.width(15);
            cout.fill(' ');
            cout.setf(ios::left, ios::adjustfield);
            cout<<"Name";
            cout.width(15);cout.width(15);
            cout.fill(' ');
            cout.setf(ios::left, ios::adjustfield);
            cout<<"Telephone"<<endl;
            for(int i=0; i<TableSize; i++){
                cout.width(15);
                cout.fill(' ');
                cout.setf(ios::left, ios::adjustfield);
                cout<<HT1[i].name;
                cout.width(15);
                cout.fill(' ');
                cout.setf(ios::left, ios::adjustfield);
                cout<<HT1[i].Telephone<<endl;
		}
        }
        else{
            cout.width(15);
            cout.fill(' ');
            cout.setf(ios::left, ios::adjustfield);
            cout<<"Name";
            cout.width(15);cout.width(15);
            cout.fill(' ');
            cout.setf(ios::left, ios::adjustfield);
            cout<<"Telephone"<<endl;
            for(int i=0; i<TableSize; i++){
                cout.width(15);
                cout.fill(' ');
                cout.setf(ios::left, ios::adjustfield);
                cout<<HT2[i].name;
                cout.width(15);
                cout.fill(' ');
                cout.setf(ios::left, ios::adjustfield);
                cout<<HT2[i].Telephone<<endl;
        }
        }
	}
	//search common for both Hash Tables
	void search_HT(){
        cout<<"Which Table do you want to search in? [Enter 0 for HT1 OR 1 for HT2] :";
        int key;
        cin>>key;
        if(key==0){
                char Name[10];
                cout<<"Enter name you want to search: ";
                cin>>Name;
                bool check=false;
                int cnt=0;
                int index;
                int ASCII=0;
                for(int j=0; Name[j]!='\0'; j++){
				ASCII=ASCII + Name[j];
                }
                index=ASCII %TableSize;
                while( check==false && cnt<TableSize){
                    if(strcmp(HT1[index].name, Name)==0){
                        check=true;
                        cout<<"Telephone: "<<HT1[index].Telephone<<endl;
                        cout<<index<<endl;
                    }
                    else{
                        index=(index +1)%TableSize;
                        cout<<index<<endl;
                        cnt++;
                    }
                }
                if(check == false){
                    cout<<"The client does not exist in the directory..."<<endl;
                }
                cout<<"Number of comparisons are: "<<cnt+1<<endl;
        }
        else{
            char Name[10];
                cout<<"Enter name you want to search: ";
                cin>>Name;
                bool check=false;
                int cnt=0;
                int index;
                int ASCII=0;
                for(int j=0; Name[j]!='\0'; j++){
				ASCII=ASCII + Name[j];
                }
                index=ASCII %TableSize;
                while( check==false && cnt<TableSize){
                    if(strcmp(HT2[index].name, Name)==0){
                        check=true;
                        cout<<"Telephone: "<<HT2[index].Telephone<<endl;
                        cout<<index<<endl;
                    }
                    else{
                        index=(index +1)%TableSize;
                        cout<<index<<endl;
                        cnt++;
                    }
                }
                if(check == false){
                    cout<<"The client does not exist in the directory..."<<endl;
                }
                cout<<"Number of comparisons are: "<<cnt+1<<endl;
        }
	}
};
int main() {
	HashTable H1;
	H1.create_HT1();
	H1.display();
	H1.create_HT2();
	H1.display();
	H1.search_HT();
	H1.search_HT();
	H1.search_HT();
	H1.search_HT();
	H1.search_HT();
	H1.search_HT();
	H1.search_HT();
	H1.search_HT();
	H1.search_HT();
	H1.search_HT();
	H1.search_HT();
	H1.search_HT();
	return 0;
}