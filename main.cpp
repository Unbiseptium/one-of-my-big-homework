#include <bits/stdc++.h>
#include <direct.h>

#include <utility>

#define int long long
using namespace std;

class Student {
private:
    string id;
    double sum = 0;
    string name;
    int common = 0;
    double math = 0;
    double english = 0;
    double programming = 0;
    double average = 0;
public:
    Student();

    ~Student();

    [[maybe_unused]] static bool cmp_average(const Student &a, const Student &b) {
        return a.average_output() > b.average_output();
    }

    [[maybe_unused]] static bool cmp_math(const Student &a, const Student &b) {
        return a.math_output() > b.math_output();
    }

    [[maybe_unused]] static bool cmp_english(const Student &a, const Student &b) {
        return a.english_output() > b.english_output();
    }

    [[maybe_unused]] static bool cmp_programming(const Student &a, const Student &b) {
        return a.programming_output() > b.programming_output();
    }

    void id_input(string d) {
        id = std::move(d);
    }

    void name_input(string d) {
        name = std::move(d);
    }

    void math_input(double d) {
        math = d;
    }

    void english_input(double d) {
        english = d;
    }

    void programming_input(double d) {
        programming = d;
    }

    void sum_input(double d) {
        sum = d;
    }

    void average_input(double d) {
        average = d;
    }

    void common_input(int d) {
        common = d;
    }

    string id_output() {
        return id;
    }

    string name_output() {
        return name;
    }

    [[nodiscard]] double math_output() const {
        return math;
    }

    [[nodiscard]] double english_output() const {
        return english;
    }

    [[nodiscard]] double programming_output() const {
        return programming;
    }

    [[maybe_unused]] [[nodiscard]] double sum_output() const {
        return sum;
    }

    [[nodiscard]] double average_output() const {
        return average;
    }

    [[nodiscard]] int common_output() const {
        return common;
    }
};

//构造函数
Student::Student() {
    id = "";
    name = "";
    math = 0;
    english = 0;
    programming = 0;
    sum = 0;
    average = 0;
    common = 0;
}

//析构函数
Student::~Student() = default;

//按平均分排序
void sort_average(Student *a, int n) {
    sort(a, a + n, Student::cmp_average);
}

//按数学分数排序
void sort_math(Student *a, int n) {
    sort(a, a + n, Student::cmp_math);
}

//按英语分数排序
void sort_english(Student *a, int n) {
    sort(a, a + n, Student::cmp_english);
}

//按计算机分数排序
void sort_programming(Student *a, int n) {
    sort(a, a + n, Student::cmp_programming);
}

//获取程序当前运行路径
char *where() {
    char *path;
    path = _getcwd(nullptr, 0);
    return path;
}

//建立result文件夹
void create_fold() {
    string folderPath = where();
    folderPath = folderPath + "\\result";
    string command;
    command = "mkdir " + folderPath;
    system(command.c_str());
}

//建立临时数据文件夹
void create_folds() {
    string folderPath = where();
    folderPath = folderPath + "\\lssj";
    string command;
    command = "mkdir " + folderPath;
    system(command.c_str());
}

//删除result文件夹
void delete_fold() {
    string folderPath = where();
    folderPath = folderPath + "\\result";
    string command;
    command = "rmdir /s /q " + folderPath;
    system(command.c_str());
}

//删除临时数据文件夹
void delete_folds() {
    string folderPath = where();
    folderPath = folderPath + "\\lssj";
    string command;
    command = "rmdir /s /q " + folderPath;
    system(command.c_str());
}

//创建输入数据文件
void create_input_file(Student *a, int n) {
    string folderPath = where();
    folderPath = folderPath + "\\result";
    string filePath = folderPath + "\\input.dat";
    ofstream file;
    file.open(filePath, ios::out);
    for (int i = 0; i < n; i++) {

        file << "id: " << a[i].id_output() << " \t";
        file << "name: " << a[i].name_output() << "     \t";
        file << "math: " << a[i].math_output() << " \t";
        file << "english: " << a[i].english_output() << " \t";
        file << "programming: " << a[i].programming_output() << " \t";
        file << "average: " << a[i].average_output();
        file << endl;
    }
    file.close();
}

//重载临时输入数据文件
void create_input_file(Student *a, const string &s) {
    string folderPath = where();
    folderPath = folderPath + "\\lssj";
    string filePath = folderPath + "\\" + s + ".dat";
    ofstream file;
    file.open(filePath, ios::app);
    file << a->id_output() << " ";
    file << a->name_output() << " ";
    file << a->math_output() << " ";
    file << a->english_output() << " ";
    file << a->programming_output();
    file << endl;
    file.close();
}

//创建按平均分排序的输出数据文件
void create_sort_average(Student *a, int n) {
    string folderPath = where();
    folderPath = folderPath + "\\result";
    string filePath = folderPath + "\\" + "sort-average.dat";
    ofstream file;
    file.open(filePath, ios::out);
    for (int i = 0; i < n; i++) {

        file << "id: " << a[i].id_output() << " \t";
        file << "name: " << a[i].name_output() << "     \t";
        file << "math: " << a[i].math_output() << " \t";
        file << "english: " << a[i].english_output() << " \t";
        file << "programming: " << a[i].programming_output() << " \t";
        file << "average: " << a[i].average_output();
        file << endl;
    }
    file.close();
}

//创建按数学分数排序的输出数据文件
void create_sort_math(Student *a, int n) {
    string folderPath = where();
    folderPath = folderPath + "\\result";
    string filePath = folderPath + "\\" + "sort-math.dat";
    ofstream file;
    file.open(filePath, ios::out);
    for (int i = 0; i < n; i++) {

        file << "id: " << a[i].id_output() << " \t";
        file << "name: " << a[i].name_output() << "     \t";
        file << "math: " << a[i].math_output() << " \t";
        file << "english: " << a[i].english_output() << " \t";
        file << "programming: " << a[i].programming_output() << " \t";
        file << "average: " << a[i].average_output();
        file << endl;
    }
    file.close();
}

//创建按英语分数排序的输出数据文件
void create_sort_english(Student *a, int n) {
    string folderPath = where();
    folderPath = folderPath + "\\result";
    string filePath = folderPath + "\\" + "sort-english.dat";
    ofstream file;
    file.open(filePath, ios::out);
    for (int i = 0; i < n; i++) {

        file << "id: " << a[i].id_output() << " \t";
        file << "name: " << a[i].name_output() << "     \t";
        file << "math: " << a[i].math_output() << " \t";
        file << "english: " << a[i].english_output() << " \t";
        file << "programming: " << a[i].programming_output() << " \t";
        file << "average: " << a[i].average_output();
        file << endl;
    }
    file.close();
}

//创建按计算机分数排序的输出数据文件
void create_sort_programming(Student *a, int n) {
    string folderPath = where();
    folderPath = folderPath + "\\result";
    string filePath = folderPath + "\\" + "sort-programming.dat";
    ofstream file;
    file.open(filePath, ios::out);
    for (int i = 0; i < n; i++) {

        file << "id: " << a[i].id_output() << " \t";
        file << "name: " << a[i].name_output() << "     \t";
        file << "math: " << a[i].math_output() << " \t";
        file << "english: " << a[i].english_output() << " \t";
        file << "programming: " << a[i].programming_output() << " \t";
        file << "average: " << a[i].average_output();
        file << endl;
    }
    file.close();
}
//检查是否重名
int check_common(Student *students, int n, const string &id) {
    int value = 0;
    for (int i = 0; i < n; i++) {
        if (students[i].id_output() == id) {
            value = 1;
        }
    }
    return value;
}

//创建学生
void create_student(Student *&students, int n) {
    for (int i = 0; i < n; i++) {
        string id, name;
        double math, english, programming, average, sum;
        int common = 0;
        cin >> id >> name >> math >> english >> programming;
        sum = math + english + programming;
        average = sum / 3;
        students[i].id_input(id);
        students[i].name_input(name);
        students[i].math_input(math);
        students[i].english_input(english);
        students[i].programming_input(programming);
        students[i].average_input(average);
        students[i].sum_input(sum);
        students[i].common_input(common);
        if (check_common(students, i, students[i].id_output()) == 1) {
            cout << "id is already exist,please try aging!" << endl;
            i--;
        }
        for (int ix = 0; ix < i; ix++) {
            if (students[ix].name_output() == students[i].name_output()) {
                students[i].common_input(1);
                students[ix].common_input(1);
            }
        }
    }
}

//无限输入模式下重载创建学生文件
void create_student(Student *&students, int n, [[maybe_unused]] char a) {
    for (int i = 0; i < n; i++) {
        string id, name, s;
        s = to_string(i);
        double math = 0, english = 0, programming = 0, average, sum;
        int common = 0;
        string folderPath = where();
        folderPath.append("\\lssj");
        string filePath = folderPath;
        filePath.append("\\" + s + ".dat");
        ifstream file;
        file.open(filePath, ios::in);
        file >> id >> name >> math >> english >> programming;
        sum = math + english + programming;
        average = sum / 3;
        students[i].id_input(id);
        students[i].name_input(name);
        students[i].math_input(math);
        students[i].english_input(english);
        students[i].programming_input(programming);
        students[i].average_input(average);
        students[i].sum_input(sum);
        students[i].common_input(common);
        if (check_common(students, i, students[i].id_output()) == 1) {
            i--;
            continue;
        }
        for (int ix = 0; ix < i; ix++) {
            if (students[ix].name_output() == students[i].name_output()) {
                students[i].common_input(1);
                students[ix].common_input(1);
            }
        }
    }
}

//无限输入模式下重载创建学生
void create_student(Student *&students) {
    string id, name;
    double math, english, programming;
    cin >> id >> name >> math >> english >> programming;
    students->id_input(id);
    students->name_input(name);
    students->math_input(math);
    students->english_input(english);
    students->programming_input(programming);
}

//输出学生信息
void show_all(Student *&students, int n) {
    for (int i = 0; i < n; i++) {
        cout << "id: " << students[i].id_output() << "\t";
        cout << "name: " << students[i].name_output() << "\t";
        cout << "math: " << students[i].math_output() << "\t";
        cout << "english: " << students[i].english_output() << "\t";
        cout << "programming: " << students[i].programming_output() << " \t";
        cout << "average: " << students[i].average_output();
        cout << endl;
    }
}

//按id查找
void search_with_id(Student *&students, int n) {
    string id;
    int value = 0;
    cout << "id: ";
    cin >> id;
    for (int i = 0; i < n; i++) {
        if (students[i].id_output() == id) {
            cout << "id: " << students[i].id_output() << "\t";
            cout << "name: " << students[i].name_output() << "\t";
            cout << "math: " << students[i].math_output() << "\t";
            cout << "english: " << students[i].english_output() << "\t";
            cout << "programming: " << students[i].programming_output() << " \t";
            cout << "average: " << students[i].average_output();
            cout << endl;
            value = 1;
        }
    }
    if (value == 0)
        cout << "没有找到!" << endl;
}

//重名情况下按id查找（辨别姓名是否对应）
void search_with_id(Student *&students, int n, const string &name) {
    string id;
    int value = 0;
    cout << "id: ";
    cin >> id;
    for (int i = 0; i < n; i++) {
        if (students[i].id_output() == id) {
            if (students[i].name_output() != name) {
                cout << "没有找到名为；" << name << "，id为；" << id << "的学生!" << endl;
                cout << "以下是id查找结果；" << endl;
            }
            {
                cout << "id: " << students[i].id_output() << "\t";
                cout << "name: " << students[i].name_output() << "\t";
                cout << "math: " << students[i].math_output() << "\t";
                cout << "english: " << students[i].english_output() << "\t";
                cout << "programming: " << students[i].programming_output() << " \t";
                cout << "average: " << students[i].average_output();
                cout << endl;
                value = 1;
            }
        }
    }
    if (value == 0)
        cout << "没有找到!" << endl;
}

//按姓名查找
void search_with_name(Student *&students, int n) {
    string name;
    int value = 0;
    cout << "name: ";
    cin >> name;
    getchar();
    for (int i = 0; i < n; i++) {
        if (students[i].name_output() == name) {
            if (students[i].common_output() == 1) {
                cout << "存在重名，请输入学号查询！" << endl;
                search_with_id(students, n, name);
                return;
            } else {
                cout << "id: " << students[i].id_output() << "\t";
                cout << "name: " << students[i].name_output() << "\t";
                cout << "math: " << students[i].math_output() << "\t";
                cout << "english: " << students[i].english_output() << "\t";
                cout << "programming: " << students[i].programming_output() << " \t";
                cout << "average: " << students[i].average_output();
                cout << endl;
            }
            value = 1;
        }
    }
    if (value == 0)
        cout << "没有找到!" << endl;
}

//输出平均数学成绩
void average_math(Student *&students, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += students[i].math_output();
    }
    cout << "平均数学成绩；" << sum / (double) n << endl;
}

//输出平均英语成绩
void average_english(Student *&students, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += students[i].english_output();
    }
    cout << "平均英语成绩；" << sum / (double) n << endl;
}

//输出平均计算机成绩
void average_programming(Student *&students, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += students[i].programming_output();
    }
    cout << "平均计算机成绩；" << sum / (double) n << endl;
}

//输出最高数学成绩
void best_math(Student *a, int n) {
    double max = a[0].math_output();
    for (int i = 0; i < n; i++) {
        if (a[i].math_output() > max) {
            max = a[i].math_output();
        }
    }
    cout << "最高数学成绩；" << max << endl;
}

//输出最高英语成绩
void best_english(Student *a, int n) {
    double max = a[0].english_output();
    for (int i = 0; i < n; i++) {
        if (a[i].english_output() > max) {
            max = a[i].english_output();
        }
    }
    cout << "最高英语成绩；" << max << endl;
}

//输出最高计算机成绩
void best_programming(Student *a, int n) {
    double max = a[0].programming_output();
    for (int i = 0; i < n; i++) {
        if (a[i].programming_output() > max) {
            max = a[i].programming_output();
        }
    }
    cout << "最高计算机成绩；" << max << endl;
}

//输出最低数学成绩
void worst_math(Student *a, int n) {
    double min = a[0].math_output();
    for (int i = 0; i < n; i++) {
        if (a[i].math_output() < min) {
            min = a[i].math_output();
        }
    }
    cout << "最差数学成绩；" << min << endl;
}

//输出最低英语成绩
void worst_english(Student *a, int n) {
    double min = a[0].english_output();
    for (int i = 0; i < n; i++) {
        if (a[i].english_output() < min) {
            min = a[i].english_output();
        }
    }
    cout << "最差英语成绩；" << min << endl;
}

//输出最低计算机成绩
void worst_programming(Student *a, int n) {
    double min = a[0].programming_output();
    for (int i = 0; i < n; i++) {
        if (a[i].programming_output() < min) {
            min = a[i].programming_output();
        }
    }
    cout << "最差计算机成绩；" << min << endl;
}

//输出数学不及格人数
void no_pass_math(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].math_output() < 60) {
            count++;
        }
    }
    cout << "数学不及格；" << count << endl;
}

//输出英语不及格人数
void no_pass_english(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].english_output() < 60) {
            count++;
        }
    }
    cout << "英语不及格；" << count << endl;
}

//输出计算机不及格人数
void no_pass_programming(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].programming_output() < 60) {
            count++;
        }
    }
    cout << "计算机不及格；" << count << endl;
}

//输出数学60~69分人数
void l_math(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].math_output() >= 60 && a[i].math_output() <= 69) {
            count++;
        }
    }
    cout << "数学60~69分；" << count << endl;
}

//输出英语60~69分人数
void l_english(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].english_output() >= 60 && a[i].english_output() <= 69) {
            count++;
        }
    }
    cout << "英语60~69分；" << count << endl;
}

//输出计算机60~69分人数
void l_programming(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].programming_output() >= 60 && a[i].programming_output() <= 69) {
            count++;
        }
    }
    cout << "计算机60~69分；" << count << endl;
}

//输出数学70~79分人数
void q_math(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].math_output() >= 70 && a[i].math_output() <= 79) {
            count++;
        }
    }
    cout << "数学70~79分；" << count << endl;
}

//输出英语70~79分人数
void q_english(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].english_output() >= 70 && a[i].english_output() <= 79) {
            count++;
        }
    }
    cout << "英语70~79分；" << count << endl;
}

//输出计算机70~79分人数
void q_programming(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].programming_output() >= 70 && a[i].programming_output() <= 79) {
            count++;
        }
    }
    cout << "计算机70~79分；" << count << endl;
}

//输出数学80~89分人数
void b_math(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].math_output() >= 80 && a[i].math_output() <= 89) {
            count++;
        }
    }
    cout << "数学80~89分；" << count << endl;
}

//输出英语80~89分人数
void b_english(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].english_output() >= 80 && a[i].english_output() <= 89) {
            count++;
        }
    }
    cout << "英语80~89分；" << count << endl;
}

//输出计算机80~89分人数
void b_programming(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].programming_output() >= 80 && a[i].programming_output() <= 89) {
            count++;
        }
    }
    cout << "计算机80~89分；" << count << endl;
}

//输出数学超过90分人数
void j_math(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].math_output() >= 90 && a[i].math_output() <= 100) {
            count++;
        }
    }
    cout << "数学超过90分；" << count << endl;
}

//输出英语超过90分人数
void j_english(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].english_output() >= 90 && a[i].english_output() <= 100) {
            count++;
        }
    }
    cout << "英语超过90分；" << count << endl;
}

//输出计算机超过90分人数
void j_programming(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].programming_output() >= 90 && a[i].programming_output() <= 100) {
            count++;
        }
    }
    cout << "计算机超过90分；" << count << endl;
}

//菜单
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
    system("color A");
    delete_fold();
    create_fold();
    cout << "欢迎使用学生成绩分析系统！" << endl;
    cout << "您是否知道学生人数（y/n）？" << endl;
    char c;
    int n = 0;
    cin >> c;
    if (c == 'y') {
        cout << "请输入学生人数：";
        retry:
        cin >> n;
        getchar();
        if (n == 0) {
            cout << "输入错误，请重新输入！" << endl;
            goto retry;
        }
        cout << "请按照学号、姓名、数学、英语、计算机的顺序输入学生成绩：" << endl;
        cout << "（例如：001 王放 78 77 90）" << endl;
    } else if (c == 'n') {
        create_folds();
        cout << "无限输入模式：" << endl;
        cout << "请按照学号、姓名、数学、英语、计算机的顺序输入学生成绩：" << endl;
        cout << "（例如：001 王放 78 77 90）,id为0时停止输入" << endl;
        string br = "0";
        for (;; n++) {
            auto *student = new Student;
            create_student(student);
            if (student->id_output() == br) {
                break;
            }
            string s = to_string(n);
            create_input_file(student, s);
        }
    }
    auto *students = new Student[n];
    if (c == 'n') {
        create_student(students, n, c);
        delete_folds();
    } else
        create_student(students, n);
    create_input_file(students, n);
    menu(students, n);
    return 0;
}