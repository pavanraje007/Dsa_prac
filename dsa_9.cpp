#include <iostream>
#include <map>
#include <string>
using namespace std;

class Dictionary {
    map<string, string> dict;
public:
   void insert(string keywoed,string>dict;
   dict[keyword]=meaning){
   }
   
   void remove(string keyword){
   dict.erase(keyword);
   }
   void display Ascending(){
   for(cost auto &entry:dict)
   cout<<<entry.first<<":"<<entry.second<<endl;
   }
   void displayDescending(){
   for(auto it=dict.rbegin();it!=dict.read();++it)
   cout<<it->first<<":"<<it->second<<end;
   }
   
  void search(string keyword){
  auto it=dict.find(keyword);
  if(it!dict.end())
  cout<<"keyword found."<<it->first<<"->:"<<it->second<<endl;
  else
  cout<<keyword not found."<<end;
  }
  };
   int main() {
    Dictionary dict;
    int choice;
    string keyword, meaning;
    do {
        cout << "\n1. Insert\n2. Delete\n3. Display Ascending\n4. Display Descending\n5. Search\n6. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter keyword: ";
            cin >> keyword;
            cout << "Enter meaning: ";
            cin.ignore();
            getline(cin, meaning);
            dict.insert(keyword, meaning);
            break;
        case 2:
            cout << "Enter keyword to delete: ";
            cin >> keyword;
            dict.remove(keyword);
            break;
        case 3:
            dict.displayAscending();
            break;
        case 4:
            dict.displayDescending();
            break;
        case 5:
            cout << "Enter keyword to search: ";
            cin >> keyword;
            dict.search(keyword);
            break;
        case 6:
             cout<<"Exiting program."<<endl;
             cout<<"Invalid choice!"<<endl;
             }
             }while (choice ! = 6);
             return 0;
             }
        
        
          
