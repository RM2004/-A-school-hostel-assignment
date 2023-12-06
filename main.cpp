#include<bits/stdc++.h>
using namespace std;

void displayArray(vector<int> &arr){
    int n = arr.size();
    cout<<"[";
    for(int i = 0; i < n; i++){
        cout<<arr[i];
        if(i < n-1)cout<<", ";
    }
    cout<<"]\n";
}

class SortingHat{
    int hostel_capacity;
    vector<int> AV;
    vector<int> BV;
    vector<int> ANV;
    vector<int> BNV;
    vector<int> NA;
    unordered_set<int> registered;
public:
    SortingHat(int capacity){
        this->hostel_capacity = capacity/4;
    }

    void registerStudent(int rollNo, string classId, string foodPreference){
        if(registered.count(rollNo))    
            return;

        if(classId == "A" && foodPreference == "V"){
            if(AV.size() < this->hostel_capacity){
                AV.push_back(rollNo);
                registered.insert(rollNo);
            }else if(ANV.size() < this->hostel_capacity){
                ANV.push_back(rollNo);
                registered.insert(rollNo);
            }else{
                NA.push_back(rollNo);
            }
        }else if(classId == "B" && foodPreference == "V"){
            if(BV.size() < this->hostel_capacity){
                BV.push_back(rollNo);
                registered.insert(rollNo);
            }else if(BNV.size() < this->hostel_capacity){
                BNV.push_back(rollNo);
                registered.insert(rollNo);
            }else{
                NA.push_back(rollNo);
            }
        }else if(classId == "A" && foodPreference == "NV"){
            if(ANV.size() < this->hostel_capacity){
                ANV.push_back(rollNo);
                registered.insert(rollNo);
            }else{
                NA.push_back(rollNo);
            }
        }else{
            if(BNV.size() < this->hostel_capacity){
                BNV.push_back(rollNo);
                registered.insert(rollNo);
            }else{
                NA.push_back(rollNo);
            }
        }
    }

    void displayHostelResidents(){
        cout<<"BV : ";
        displayArray(BV);
        cout<<"AV : ";
        displayArray(AV);
        cout<<"BNV : ";
        displayArray(BNV);
        cout<<"ANV : ";
        displayArray(ANV);
        cout<<"NA : ";
        displayArray(NA);
    }
};


SortingHat* processInput(){
    string line;
    getline(cin, line);
    istringstream iss(line);
    string op,cap;
    getline(iss, op, ' ');
    if(op != "init")
        return NULL;
    getline(iss, cap, ' ');
    SortingHat *sorter = new SortingHat(stoi(cap));

    while(getline(cin, line)){
        istringstream iss(line);
        string op,rollNo, classId, foodPref;
        getline(iss, op, ' ');
        if(op == "fin")
            break;
        getline(iss, rollNo, ' ');
        getline(iss, classId, ' ');
        getline(iss, foodPref, ' ');
        sorter->registerStudent(stoi(rollNo), classId, foodPref);
    }
    return sorter;
}

int main(){
    SortingHat* sorter = processInput();
    if(sorter)
        sorter->displayHostelResidents();
    return 0;
}