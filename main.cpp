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
        cout << "没有找到!" << endl;
}

void search_with_id(Student *&students, int n, const string& name) {
    string id;
    int value = 0;
    cout << "id: ";
    cin >> id;
    for (int i = 0; i < n; i++) {
        if (students[i].id == id) {
            if (students[i].name != name) {
                cout << "没有找到名为；" <<name<<"id为；"<<id<<"的学生!"<<endl;
                cout<<"以下是id查找结果；"<<endl;
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
        cout << "没有找到!" << endl;
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
                cout << "存在重名，请输入学号查询！" << endl;
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
        cout << "没有找到!" << endl;
}

void average_math(Student *&students, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += students[i].math;
    }
    cout << "平均数学成绩；" << sum / (double)n<< endl;
}

void average_english(Student *&students, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += students[i].english;
    }
    cout << "平均英语成绩；" << sum / (double)n << endl;
}

void average_programming(Student *&students, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += students[i].programming;
    }
    cout << "平均计算机成绩；" << sum / (double)n << endl;
}

void best_math(Student *a, int n) {
    double max = a[0].math;
    for (int i = 0; i < n; i++) {
        if (a[i].math > max) {
            max = a[i].math;
        }
    }
    cout << "最高数学成绩；" << max << endl;
}

void best_english(Student *a, int n) {
    double max = a[0].english;
    for (int i = 0; i < n; i++) {
        if (a[i].english > max) {
            max = a[i].english;
        }
    }
    cout << "最高英语成绩；" << max << endl;
}

void best_programming(Student *a, int n) {
    double max = a[0].programming;
    for (int i = 0; i < n; i++) {
        if (a[i].programming > max) {
            max = a[i].programming;
        }
    }
    cout << "最高计算机成绩；" << max << endl;
}

void worst_math(Student *a, int n) {
    double min = a[0].math;
    for (int i = 0; i < n; i++) {
        if (a[i].math < min) {
            min = a[i].math;
        }
    }
    cout << "最差数学成绩；" << min << endl;
}

void worst_english(Student *a, int n) {
    double min = a[0].english;
    for (int i = 0; i < n; i++) {
        if (a[i].english < min) {
            min = a[i].english;
        }
    }
    cout << "最差英语成绩；" << min << endl;
}

void worst_programming(Student *a, int n) {
    double min = a[0].programming;
    for (int i = 0; i < n; i++) {
        if (a[i].programming < min) {
            min = a[i].programming;
        }
    }
    cout << "最差计算机成绩；" << min << endl;
}

void no_pass_math(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].math < 60) {
            count++;
        }
    }
    cout << "数学不及格；" << count << endl;
}

void no_pass_english(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].english < 60) {
            count++;
        }
    }
    cout << "英语不及格；" << count << endl;
}

void no_pass_programming(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].programming < 60) {
            count++;
        }
    }
    cout << "计算机不及格；" << count << endl;
}

void l_math(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].math >= 60 && a[i].math <= 69) {
            count++;
        }
    }
    cout << "数学60~69分；" << count << endl;
}

void l_english(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].english >= 60 && a[i].english <= 69) {
            count++;
        }
    }
    cout << "英语60~69分；" << count << endl;
}

void l_programming(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].programming >= 60 && a[i].programming <= 69) {
            count++;
        }
    }
    cout << "计算机60~69分；" << count << endl;
}

void q_math(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].math >= 70 && a[i].math <= 79) {
            count++;
        }
    }
    cout << "数学70~79分；" << count << endl;
}

void q_english(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].english >= 70 && a[i].english <= 79) {
            count++;
        }
    }
    cout << "英语70~79分；" << count << endl;
}

void q_programming(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].programming >= 70 && a[i].programming <= 79) {
            count++;
        }
    }
    cout << "计算机70~79分；" << count << endl;
}

void b_math(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].math >= 80 && a[i].math <= 89) {
            count++;
        }
    }
    cout << "数学80~89分；" << count << endl;
}

void b_english(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].english >= 80 && a[i].english <= 89) {
            count++;
        }
    }
    cout << "英语80~89分；" << count << endl;
}

void b_programming(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].programming >= 80 && a[i].programming <= 89) {
            count++;
        }
    }
    cout << "计算机80~89分；" << count << endl;
}

void j_math(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].math >= 90 && a[i].math <= 100) {
            count++;
        }
    }
    cout << "数学超过90分；" << count << endl;
}

void j_english(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].english >= 90 && a[i].english <= 100) {
            count++;
        }
    }
    cout << "英语超过90分；" << count << endl;
}

void j_programming(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].programming >= 90 && a[i].programming <= 100) {
            count++;
        }
    }
    cout << "计算机超过90分；" << count << endl;
}


void menu(Student *&students, int n) {
    int choice;
    while (true) {
        cout << "1.显示所有学生信息" << endl;
        cout << "2.按学号查询学生成绩" << endl;
        cout << "3.按姓名查询学生成绩" << endl;
        cout << "4.按个人平均成绩排序并输出" << endl;
        cout << "5.按数学成绩排序并输出" << endl;
        cout << "6.按英语成绩排序并输出" << endl;
        cout << "7.按计算机成绩排序并输出" << endl;
        cout << "8.查询数学情况" << endl;
        cout << "9.查询英语情况" << endl;
        cout << "10.查询计算机情况" << endl;
        cout << "0.退出系统" << endl;
        cout << "请选择：";
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
                cout << "数据已输出至程序同目录下result文件夹的sort-average.dat文件中" << endl;
                system("pause");
                break;
            }
            case 5: {
                sort_math(students, n);
                create_sort_math(students, n);
                cout << "done!" << endl;
                cout << "数据已输出至程序同目录下result文件夹的sort-math.dat文件中" << endl;
                system("pause");
                break;
            }

            case 6: {
                sort_english(students, n);
                create_sort_english(students, n);
                cout << "done!" << endl;
                cout << "数据已输出至程序同目录下result文件夹的sort-english.dat文件中" << endl;
                system("pause");
                break;
            }

            case 7: {
                sort_programming(students, n);
                create_sort_programming(students, n);
                cout << "done!" << endl;
                cout << "数据已输出至程序同目录下result文件夹的sort-programming.dat文件中" << endl;
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
                cout << "输入错误，请重新输入！" << endl;
                system("pause");
        }
    }
}

signed main() {
    cout << "欢迎使用学生成绩分析系统！" << endl;
    cout << "请输入学生人数：";
    int n;
    retry:
    cin >> n;
    getchar();
    if (n == 0) {
        cout << "输入错误，请重新输入！" << endl;
        goto retry;
    }
    auto *students = new Student[n];
    cout << "请按照学号、姓名、数学、英语、计算机的顺序输入学生成绩：" << endl;
    cout << "（例如：001 王放 78 77 90）" << endl;
    create_student(students, n);
    delete_fold();
    create_fold();
    menu(students, n);
    return 0;
}
