// #include <iostream>
// using namespace std;

// struct point {
//     int x; // Hoành độ
//     int y; // Tung độ
// };

// struct node {
//     point info; // Thông tin điểm
//     node* next; // Con trỏ trỏ tới nút tiếp theo trong danh sách
// };

// struct List {
//     node* head; // Con trỏ trỏ tới nút đầu danh sách
//     node* tail; // Con trỏ trỏ tới nút cuối danh sách
// };

// // Hàm tạo một danh sách rỗng
// void CreateEmptyList(List& L) {
//     L.head = L.tail = NULL;
// }

// // Hàm tạo một nút mới chứa thông tin điểm
// node* Createnode(point p) {
//     node* newnode = new node;
//     newnode->info = p;
//     newnode->next = NULL;
//     return newnode;
// }

// // Hàm chèn một điểm vào danh sách theo thứ tự tăng dần hoành độ và tung độ
// void Insertnode(List& L, point p) {
//     node* newnode = Createnode(p);

//     if (L.head == NULL) {
//         L.head = L.tail = newnode;
//     } else if (p.x < L.head->info.x || (p.x == L.head->info.x && p.y < L.head->info.y)) {
//         newnode->next = L.head;
//         L.head = newnode;
//     } else if (p.x > L.tail->info.x || (p.x == L.tail->info.x && p.y > L.tail->info.y)) {
//         L.tail->next = newnode;
//         L.tail = newnode;
//     } else {
//         node* current = L.head;
//         while (current->next != NULL && (p.x > current->next->info.x || (p.x == current->next->info.x && p.y > current->next->info.y))) {
//             current = current->next;
//         }
//         newnode->next = current->next;
//         current->next = newnode;
//     }
// }

// // Hàm in danh sách các điểm
// void PrintList(List L) {
//     node* current = L.head;
//     while (current != NULL) {
//         cout << "(" << current->info.x <<","<<current->info.y <<")"<<endl;
//         current = current->next;
//     }
//     cout << endl;
// }

// // Hàm tạo danh sách điểm từ dữ liệu nhập vào
// void CreateList(List& L) {
//     int n;

//     cin >> n;

//     for (int i = 0; i < n; i++) {
//         point p;
      
//         cin >> p.x >> p.y;
//         Insertnode(L, p);
//     }
// }

// int main() {
//     List L;
//     CreateEmptyList(L);
//     CreateList(L);
//     PrintList(L);
//     return 0;
// }


#include <iostream>
using namespace std;

struct TIME {
    int gio, phut, giay;
};

struct node {
    TIME info;
    node* next;
};

struct List {
    node* head;
    node* tail;
};

// Hàm tạo một danh sách rỗng
void CreateEmptyList(List& L) {
    L.head = L.tail = NULL;
}

// Hàm tạo một nút mới chứa thông tin thời gian
node* CreateNode(TIME t) {
    node* newNode = new node;
    newNode->info = t;
    newNode->next = NULL;
    return newNode;
}

// Hàm chèn một thời gian vào danh sách
void InsertTime(List& L, TIME t) {
    node* newNode = CreateNode(t);

    if (L.head == NULL) {
        L.head = L.tail = newNode;
    } else {
        if (t.gio < L.head->info.gio || (t.gio == L.head->info.gio && t.phut < L.head->info.phut) || (t.gio == L.head->info.gio && t.phut == L.head->info.phut && t.giay < L.head->info.giay)) {
            newNode->next = L.head;
            L.head = newNode;
        } else if (t.gio > L.tail->info.gio || (t.gio == L.tail->info.gio && t.phut > L.tail->info.phut) || (t.gio == L.tail->info.gio && t.phut == L.tail->info.phut && t.giay > L.tail->info.giay)) {
            L.tail->next = newNode;
            L.tail = newNode;
        } else {
            node* current = L.head;
            while (current->next != NULL && (t.gio > current->next->info.gio || (t.gio == current->next->info.gio && t.phut > current->next->info.phut) || (t.gio == current->next->info.gio && t.phut == current->next->info.phut && t.giay > current->next->info.giay))) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
}

// Hàm in danh sách các thời gian
void PrintList(List L) {
    node* current = L.head;
    while (current != NULL) {
        cout << current->info.gio << "h" << current->info.phut << "p" << current->info.giay << "s" << endl;
        current = current->next;
    }
}

// Hàm tạo danh sách thời gian từ dữ liệu nhập vào
void CreateList(List& L) {
    int n;
    cout << "Nhap so luong thoi gian: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        TIME t;
        cout << "Nhap thoi gian thu " << i + 1 << ": ";
        cin >> t.gio >> t.phut >> t.giay;
        InsertTime(L, t);
    }
}

int main() {
    List L;
    CreateEmptyList(L);
    CreateList(L);
    cout << "Danh sach thoi gian sau khi sap xep: " << endl;
    PrintList(L);
    return 0;
}
