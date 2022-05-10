#include <bits/stdc++.h>
#include <direct.h>

#define int long long
using namespace std;

class Student {
public:
    string id;
    double sum = 0;
    string name;
    int common = 0;
    double math = 0;
    double english = 0;
    double programming = 0;
    double average = 0;
};


bool cmp_average(const Student &a, const Student& b) {
    return a.average > b.average;
}

bool cmp_math(const Student& a, const Student& b) {
    return a.math > b.math;
}

bool cmp_english(const Student& a, const Student& b) {
    return a.english > b.english;
}

bool cmp_programming(const Student& a, const Student& b) {
    return a.programming > b.programming;
}

void sort_average(Student *a, int n) {
    sort(a, a + n, cmp_average);
}

void sort_math(Student *a, int n) {
    sort(a, a + n, cmp_math);
}

void sort_english(Student *a, int n) {
    sort(a, a + n, cmp_english);
}

void sort_programming(Student *a, int n) {
    sort(a, a + n, cmp_programming);
}

char *where() {
    char *path;
    path = _getcwd(nullptr, 0);
    return path;
}

void create_fold() {
    string folderPath = where();
    folderPath = folderPath + "\\result";
    string command;
    command = "mkdir " + folderPath;
    system(command.c_str());
}

void delete_fold() {
    string folderPath = where();
    folderPath = folderPath + "\\result";
    string command;
    command = "rmdir /s /q " + folderPath;
    system(command.c_str());
}

void create_sort_average(Student *a, int n) {
    string folderPath = where();
    folderPath = folderPath + "\\result";
    string filePath = folderPath + "\\" + "sort-average.dat";
    ofstream file;
    file.open(filePath, ios::out);
    for (int i = 0; i < n; i++) {

        file << "id: " << a[i].id << "        ";
        file << "name: " << a[i].name << "        ";
        file << "math: " << a[i].math << "        ";
        file << "english: " << a[i].english << "        ";
        file << "programming: " << a[i].programming << "        ";
        file << "average: " << a[i].average;
        file << endl;
    }
    file.close();
}

void create_sort_math(Student *a, int n) {
    string folderPath = where();
    folderPath = folderPath + "\\result";
    string filePath = folderPath + "\\" + "sort-math.dat";
    ofstream file;
    file.open(filePath, ios::out);
    for (int i = 0; i < n; i++) {

        file << "id: " << a[i].id << "        ";
        file << "name: " << a[i].name << "        ";
        file << "math: " << a[i].math << "        ";
        file << "english: " << a[i].english << "        ";
        file << "programming: " << a[i].programming << "        ";
        file << "average: " << a[i].average;
        file << endl;
    }
    file.close();
}

void create_sort_english(Student *a, int n) {
    string folderPath = where();
    folderPath = folderPath + "\\result";
    string filePath = folderPath + "\\" + "sort-english.dat";
    ofstream file;
    file.open(filePath, ios::out);
    for (int i = 0; i < n; i++) {

        file << "id: " << a[i].id << "        ";
        file << "name: " << a[i].name << "        ";
        file << "math: " << a[i].math << "        ";
        file << "english: " << a[i].english << "        ";
        file << "programming: " << a[i].programming << "        ";
        file << "average: " << a[i].average;
        file << endl;
    }
    file.close();
}

void create_sort_programming(Student *a, int n) {
    string folderPath = where();
    folderPath = folderPath + "\\result";
    string filePath = folderPath + "\\" + "sort-programming.dat";
    ofstream file;
    file.open(filePath, ios::out);
    for (int i = 0; i < n; i++) {

        file << "id: " << a[i].id << "        ";
        file << "name: " << a[i].name << "        ";
        file << "math: " << a[i].math << "        ";
        file << "english: " << a[i].english << "        ";
        file << "programming: " << a[i].programming << "        ";
        file << "average: " << a[i].average;
        file << endl;
    }
    file.close();
}

int check_common(Student *students, int n, const string& id) {
    int value = 0;
    for (int i = 0; i < n; i++) {
        if (students[i].id == id) {
            value = 1;
        }
    }
    return value;
}

void create_student(Student *&students, int n) {
    for (int i = 0; i < n; i++) {
        cin >> students[i].id >> students[i].name >> students[i].math >> students[i].english >> students[i].programming;
        students[i].sum = students[i].math + students[i].english + students[i].programming;
        if (check_common(students, i, students[i].id) == 1) {
            cout << "id is already exist,please try aging!" << endl;
            i--;
        }
        students[i].average = students[i].sum / 3;
        for (int ix = 0; ix < i; ix++) {
            if (students[ix].name == students[i].name) {
                students[i].common = 1;
                students[ix].common = 1;
            }
        }
    }
}

void show_all(Student *&students, int n) {
    for (int i = 0; i < n; i++) {
        cout << "id: " << students[i].id << "       ";
        cout << "name: " << students[i].name << "       ";
        cout << "math: " << students[i].math << "       ";
        cout << "english: " << students[i].english << "      ";
        cout << "programming: " << students[i].programming << "        ";
        cout << "average: " << students[i].average;
        cout << endl;
    }
}

void search_with_id(Student *&students, int n) {
    string id;
    int value = 0;
    cout << "id: ";
    cin >> id;
    for (int i = 0; i < n; i++) {
        if (students[i].id == id) {
            cout << "id: " << students[i].id << " ";
            cout << "name: " << students[i].name << " ";
            cout << "math: " << students[i].math << " ";
            cout << "english: " << students[i].english << " ";
            cout << "programming: " << students[i].programming << " ";
            cout << "average: " << students[i].average;
            cout << endl;
            value = 1;
        }
    }
    if (value == 0)
        cout << "û���ҵ�!" << endl;
}

void search_with_id(Student *&students, int n, const string& name) {
    string id;
    int value = 0;
    cout << "id: ";
    cin >> id;
    for (int i = 0; i < n; i++) {
        if (students[i].id == id) {
            if (students[i].name != name) {
                cout << "û���ҵ���Ϊ��" <<name<<"idΪ��"<<id<<"��ѧ��!"<<endl;
                cout<<"������id���ҽ����"<<endl;
            }
                {
                    cout << "id: " << students[i].id << " ";
                    cout << "name: " << students[i].name << " ";
                    cout << "math: " << students[i].math << " ";
                    cout << "english: " << students[i].english << " ";
                    cout << "programming: " << students[i].programming << " ";
                    cout << "average: " << students[i].average;
                    cout << endl;
                    value = 1;
                }
            }
    }
    if (value == 0)
        cout << "û���ҵ�!" << endl;
}
void search_with_name(Student *&students, int n) {
    string name;
    int value = 0;
    cout << "name: ";
    cin >> name;
    getchar();
    for (int i = 0; i < n; i++) {
        if (students[i].name == name) {
            if (students[i].common == 1) {
                cout << "����������������ѧ�Ų�ѯ��" << endl;
                search_with_id(students, n,name);
                return;
            } else {
                cout << "id: " << students[i].id << " ";
                cout << "name: " << students[i].name << " ";
                cout << "math: " << students[i].math << " ";
                cout << "english: " << students[i].english << " ";
                cout << "programming: " << students[i].programming << " ";
                cout << "average: " << students[i].average;
                cout << endl;
            }
            value = 1;
        }
    }
    if (value == 0)
        cout << "û���ҵ�!" << endl;
}

void average_math(Student *&students, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += students[i].math;
    }
    cout << "ƽ����ѧ�ɼ���" << sum / (double)n<< endl;
}

void average_english(Student *&students, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += students[i].english;
    }
    cout << "ƽ��Ӣ��ɼ���" << sum / (double)n << endl;
}

void average_programming(Student *&students, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += students[i].programming;
    }
    cout << "ƽ��������ɼ���" << sum / (double)n << endl;
}

void best_math(Student *a, int n) {
    double max = a[0].math;
    for (int i = 0; i < n; i++) {
        if (a[i].math > max) {
            max = a[i].math;
        }
    }
    cout << "�����ѧ�ɼ���" << max << endl;
}

void best_english(Student *a, int n) {
    double max = a[0].english;
    for (int i = 0; i < n; i++) {
        if (a[i].english > max) {
            max = a[i].english;
        }
    }
    cout << "���Ӣ��ɼ���" << max << endl;
}

void best_programming(Student *a, int n) {
    double max = a[0].programming;
    for (int i = 0; i < n; i++) {
        if (a[i].programming > max) {
            max = a[i].programming;
        }
    }
    cout << "��߼�����ɼ���" << max << endl;
}

void worst_math(Student *a, int n) {
    double min = a[0].math;
    for (int i = 0; i < n; i++) {
        if (a[i].math < min) {
            min = a[i].math;
        }
    }
    cout << "�����ѧ�ɼ���" << min << endl;
}

void worst_english(Student *a, int n) {
    double min = a[0].english;
    for (int i = 0; i < n; i++) {
        if (a[i].english < min) {
            min = a[i].english;
        }
    }
    cout << "���Ӣ��ɼ���" << min << endl;
}

void worst_programming(Student *a, int n) {
    double min = a[0].programming;
    for (int i = 0; i < n; i++) {
        if (a[i].programming < min) {
            min = a[i].programming;
        }
    }
    cout << "��������ɼ���" << min << endl;
}

void no_pass_math(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].math < 60) {
            count++;
        }
    }
    cout << "��ѧ������" << count << endl;
}

void no_pass_english(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].english < 60) {
            count++;
        }
    }
    cout << "Ӣ�ﲻ����" << count << endl;
}

void no_pass_programming(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].programming < 60) {
            count++;
        }
    }
    cout << "�����������" << count << endl;
}

void l_math(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].math >= 60 && a[i].math <= 69) {
            count++;
        }
    }
    cout << "��ѧ60~69�֣�" << count << endl;
}

void l_english(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].english >= 60 && a[i].english <= 69) {
            count++;
        }
    }
    cout << "Ӣ��60~69�֣�" << count << endl;
}

void l_programming(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].programming >= 60 && a[i].programming <= 69) {
            count++;
        }
    }
    cout << "�����60~69�֣�" << count << endl;
}

void q_math(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].math >= 70 && a[i].math <= 79) {
            count++;
        }
    }
    cout << "��ѧ70~79�֣�" << count << endl;
}

void q_english(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].english >= 70 && a[i].english <= 79) {
            count++;
        }
    }
    cout << "Ӣ��70~79�֣�" << count << endl;
}

void q_programming(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].programming >= 70 && a[i].programming <= 79) {
            count++;
        }
    }
    cout << "�����70~79�֣�" << count << endl;
}

void b_math(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].math >= 80 && a[i].math <= 89) {
            count++;
        }
    }
    cout << "��ѧ80~89�֣�" << count << endl;
}

void b_english(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].english >= 80 && a[i].english <= 89) {
            count++;
        }
    }
    cout << "Ӣ��80~89�֣�" << count << endl;
}

void b_programming(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].programming >= 80 && a[i].programming <= 89) {
            count++;
        }
    }
    cout << "�����80~89�֣�" << count << endl;
}

void j_math(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].math >= 90 && a[i].math <= 100) {
            count++;
        }
    }
    cout << "��ѧ����90�֣�" << count << endl;
}

void j_english(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].english >= 90 && a[i].english <= 100) {
            count++;
        }
    }
    cout << "Ӣ�ﳬ��90�֣�" << count << endl;
}

void j_programming(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].programming >= 90 && a[i].programming <= 100) {
            count++;
        }
    }
    cout << "���������90�֣�" << count << endl;
}


void menu(Student *&students, int n) {
    int choice;
    while (true) {
        cout << "1.��ʾ����ѧ����Ϣ" << endl;
        cout << "2.��ѧ�Ų�ѯѧ���ɼ�" << endl;
        cout << "3.��������ѯѧ���ɼ�" << endl;
        cout << "4.������ƽ���ɼ��������" << endl;
        cout << "5.����ѧ�ɼ��������" << endl;
        cout << "6.��Ӣ��ɼ��������" << endl;
        cout << "7.��������ɼ��������" << endl;
        cout << "8.��ѯ��ѧ���" << endl;
        cout << "9.��ѯӢ�����" << endl;
        cout << "10.��ѯ��������" << endl;
        cout << "0.�˳�ϵͳ" << endl;
        cout << "��ѡ��";
        cin >> choice;
        switch (choice) {
            case 1:
                show_all(students, n);
                system("pause");
                break;
            case 2:
                search_with_id(students, n);
                system("pause");
                break;
            case 3:
                search_with_name(students, n);
                system("pause");
                break;
            case 4: {
                sort_average(students, n);
                create_sort_average(students, n);
                cout << "done!" << endl;
                cout << "���������������ͬĿ¼��result�ļ��е�sort-average.dat�ļ���" << endl;
                system("pause");
                break;
            }
            case 5: {
                sort_math(students, n);
                create_sort_math(students, n);
                cout << "done!" << endl;
                cout << "���������������ͬĿ¼��result�ļ��е�sort-math.dat�ļ���" << endl;
                system("pause");
                break;
            }

            case 6: {
                sort_english(students, n);
                create_sort_english(students, n);
                cout << "done!" << endl;
                cout << "���������������ͬĿ¼��result�ļ��е�sort-english.dat�ļ���" << endl;
                system("pause");
                break;
            }

            case 7: {
                sort_programming(students, n);
                create_sort_programming(students, n);
                cout << "done!" << endl;
                cout << "���������������ͬĿ¼��result�ļ��е�sort-programming.dat�ļ���" << endl;
                system("pause");
                break;
            }
            case 8: {
                average_math(students, n);
                best_math(students, n);
                worst_math(students, n);
                no_pass_math(students, n);
                l_math(students, n);
                q_math(students, n);
                b_math(students, n);
                j_math(students, n);
                system("pause");
                break;
            }
            case 9: {
                average_english(students, n);
                best_english(students, n);
                worst_english(students, n);
                no_pass_english(students, n);
                l_english(students, n);
                q_english(students, n);
                b_english(students, n);
                j_english(students, n);
                system("pause");
                break;
            }
            case 10: {
                average_programming(students, n);
                best_programming(students, n);
                worst_programming(students, n);
                no_pass_programming(students, n);
                l_programming(students, n);
                q_programming(students, n);
                b_programming(students, n);
                j_programming(students, n);
                system("pause");
                break;
            }
            case 0: {
                delete[] students;
                cout << "goodbye!" << endl;
                system("pause");
                exit(0);
            }
            default:
                cout << "����������������룡" << endl;
                system("pause");
        }
    }
}

signed main() {
    cout << "��ӭʹ��ѧ���ɼ�����ϵͳ��" << endl;
    cout << "������ѧ��������";
    int n;
    retry:
    cin >> n;
    getchar();
    if (n == 0) {
        cout << "����������������룡" << endl;
        goto retry;
    }
    auto *students = new Student[n];
    cout << "�밴��ѧ�š���������ѧ��Ӣ��������˳������ѧ���ɼ���" << endl;
    cout << "�����磺001 ���� 78 77 90��" << endl;
    create_student(students, n);
    delete_fold();
    create_fold();
    menu(students, n);
    return 0;
}
