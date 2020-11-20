#ifndef Data
#define Data
#include <iostream>
#include "Student.h"
#include<fstream>

using namespace std;

struct Node {
public:
    Student student;
    Node* next;
    Node* prev;  
    Node();
    Node(Student student);
};
Node::Node() {
   
    student.newStudent();
}
Node::Node(Student newstudent) {
    student = newstudent;
    
}

class DataStudent {
private:
    Node* root;
public:
    DataStudent();
    ~DataStudent();

    int getLength();
    Node* getNode(int index);
    void insertInData();
    void insertInData(Student student);
    void deleteFromData(int index);
    void showData();
    void swap(Node* first, Node* last);
    void sortByFullName();
    void sortByGroup();
    void readFromFile(const char* pathFile);
    void writeToFile(const char* pathFile);
    void findOtl();
};

DataStudent::DataStudent() {
    root = nullptr;
}
DataStudent::~DataStudent() {

}

int DataStudent::getLength() {
    Node* linker = root;
    int length=0;
    while (linker->next != nullptr) {
        linker = linker->next;
        length++;
    }
    return length;
}
Node* DataStudent::getNode(int index) {
    Node* linker = root;
    while (index != 0) {
        linker = linker->next;
        index--;
    }
    return linker;
}
void DataStudent::insertInData() {
    if (root == nullptr) {
        root = new Node();
        root->student;
        root->prev = nullptr;
        root->next = nullptr;
    }
    else {
        
        Node* linker = root;
        Node* newnode = new Node();
        while (linker->next != nullptr) {
            linker = linker->next;
        }
        newnode->student;
        newnode->prev = linker;
        newnode->next = nullptr;
        linker->next = newnode;
    }
}
void DataStudent::insertInData(Student student) {
    if (root == nullptr) {
        root = new Node(student);
      //  cout << student.getFullname();
        root->prev = nullptr;
        root->next = nullptr;
    }
    else {

        Node* linker = root;
        Node* newnode = new Node(student);
        while (linker->next != nullptr) {
            linker = linker->next;
        }
        newnode->prev = linker;
        newnode->next = nullptr;
        linker->next = newnode;
    }
}

void DataStudent::deleteFromData(int index) {
    if (index > this->getLength()) {
        cout << "error";
    }
    else if(index==0) {
        Node* temp = root;
        root = root->next;
        delete temp;
    }
    else {
        Node* linker = root;
        while (index != 0) {
            linker = linker->next;
            index--;
        }
        Node* temp = linker->prev;
        linker->prev = nullptr;
        temp->next = linker->next;
        delete linker;
    }

}
void DataStudent::showData() {
    int num = 0;
    Node* linker = root;
    while (linker != nullptr) {
        cout << endl;
        Student student = (linker->student);
        cout << num << ":" << endl;
        student.showStudent();
        linker = linker->next;
        num++;
    }
}

void DataStudent::swap(Node* first, Node* last) {
    Student temp = first->student;
    first->student = last->student;
    last->student = temp;
}

void DataStudent::sortByGroup() {
    int length = getLength()+1;
    for (int i = 0; i < length; i++) {
        for (int j = length - 1; j >= (i + 1); j--) {
            cout << "a";
            if (getNode(j)->student.getGroup() < getNode(j - 1)->student.getGroup()) {
                swap(getNode(j), getNode(j - 1));
                cout << "swap";
            }
        }
    }
}

void DataStudent::sortByFullName() {
    int length = getLength()+1;
    for (int i = 0; i < length; i++) {
        for (int j = length - 1; j >= (i + 1); j--) {
            cout << "a";
            if ((int)(getNode(j)->student.getFullname()[0]) < (int)(getNode(j - 1)->student.getFullname()[0])) {
                swap(getNode(j), getNode(j - 1));
                cout << "swap";
            }
        }
    }
}

void DataStudent::readFromFile(const char* pathFile) {
    char* line = new char[64];
    ifstream in(pathFile);
    if (in.is_open()) {
        while (!in.eof()) {
            in.getline(line, 64);
            char* fullname=new char[strlen(line)+1];
            int group=0;
            int notes[n];
            int i = 0;
            while (line[i] != ':') {
                fullname[i]= line[i];
                i++;
            }
            fullname[i] = '\0';
            i++;
            while (line[i] != ':') {
                group *= 10;
                group += line[i] - '0';
                i++;
            }
            i++;
            for (int j = 0; j < 5; j++) {
               notes[j] = line[i + j] - '0';
                i += 1;
            }
            Student student(fullname, group, notes);
            insertInData(student);
            
        }
        
    }
    in.close();
}

void DataStudent::writeToFile(const char* pathFile) {
    ofstream out;
    out.open(filepath, ios::out);
    Node* linker = root;
    for (int i = 0; i < getLength()+1; i++) {
        if (out.is_open()) {
            out << linker->student.getFullname() << ":";
            out << linker->student.getGroup();
            for (int j = 0; j < n; j++) {
                out << ":" <<linker->student.getNote(i);
            }
            if (i != getLength()) {
                out << endl;
            }
        }
        linker = linker->next;
    }

    out.close();
}

void DataStudent::findOtl() {
    int num = 0;
    Node* linker = root;
    while (linker != nullptr) {
        
        Student student = (linker->student);
        bool otl = true;
        for (int i = 0; i < n; i++) {
            if (student.getNote(i) < 4) {
                otl = false;
            }
        }
        if (otl) {
            cout << endl;
            cout << num << ":" << endl;
            student.showStudent();
        }
        linker = linker->next;
        num++;
    }
}
#endif