//
//  main.cpp
//  1022
//
//  Created by huangsunyang on 10/11/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Book {
    string id, year;
    string title, author, publisher;
    string keywords;
    Book(string id1, string year1, string title1, string author1, string publisher1, string k):
    id(id1), year(year1), title(title1), author(author1), publisher(publisher1), keywords(k){}
    bool operator< (const Book& b) const {
        return id < b.id;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<Book> books;
    int n, m, num;
    string title, author, publisher, keywords, temp, id, year;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        getline(cin, id);
        getline(cin, title);
        getline(cin, author);
        getline(cin, keywords);
        getline(cin, publisher);
        getline(cin, year);
        books.push_back(Book(id, year, title, author, publisher, keywords));
    }
    sort(books.begin(), books.end());
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        bool has_found = false;
        scanf("%d", &num);
        getchar();
        getchar();
        getline(cin, temp);
        switch (num) {
            case 1:
                cout<<"1: "<<temp<<endl;
                for (int i = 0; i < books.size(); i++) {
                    if (books[i].title == temp) {
                        has_found = true;
                        cout<<books[i].id<<endl;
                    }
                }
                if (!has_found) cout<<"Not Found"<<endl;
                break;
            case 2:
                cout<<"2: "<<temp<<endl;
                for (int i = 0; i < books.size(); i++) {
                    if (books[i].author == temp) {
                        has_found = true;
                        cout<<books[i].id<<endl;
                    }
                }
                if (!has_found) cout<<"Not Found"<<endl;
                break;
            case 3:
                cout<<"3: "<<temp<<endl;
                for (int i = 0; i < books.size(); i++) {
                    if (books[i].keywords.find(temp) != string::npos) {
                        has_found = true;
                        cout<<books[i].id<<endl;
                    }
                }
                if (!has_found) cout<<"Not Found"<<endl;
                break;
            case 4:
                cout<<"4: "<<temp<<endl;
                for (int i = 0; i < books.size(); i++) {
                    if (books[i].publisher == temp) {
                        has_found = true;
                        cout<<books[i].id<<endl;
                    }
                }
                if (!has_found) cout<<"Not Found"<<endl;
                break;
            case 5:
                cout<<"5: "<<temp<<endl;
                for (int i = 0; i < books.size(); i++) {
                    if (books[i].year == temp) {
                        has_found = true;
                        cout<<books[i].id<<endl;
                    }
                }
                if (!has_found) cout<<"Not Found"<<endl;
                break;
            default:
                break;
        }
    }
    return 0;
}
