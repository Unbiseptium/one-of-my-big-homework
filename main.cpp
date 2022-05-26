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

//���캯��
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

//��������
Student::~Student() = default;

//��ƽ��������
void sort_average(Student *a, int n) {
    sort(a, a + n, Student::cmp_average);
}

//����ѧ��������
void sort_math(Student *a, int n) {
    sort(a, a + n, Student::cmp_math);
}

//��Ӣ���������
void sort_english(Student *a, int n) {
    sort(a, a + n, Student::cmp_english);
}

//���������������
void sort_programming(Student *a, int n) {
    sort(a, a + n, Student::cmp_programming);
}

//��ȡ����ǰ����·��
char *where() {
    char *path;
    path = _getcwd(nullptr, 0);
    return path;
}

//����result�ļ���
void create_fold() {
    string folderPath = where();
    folderPath = folderPath + "\\result";
    string command;
    command = "mkdir " + folderPath;
    system(command.c_str());
}

//������ʱ�����ļ���
void create_folds() {
    string folderPath = where();
    folderPath = folderPath + "\\lssj";
    string command;
    command = "mkdir " + folderPath;
    system(command.c_str());
}

//ɾ��result�ļ���
void delete_fold() {
    string folderPath = where();
    folderPath = folderPath + "\\result";
    string command;
    command = "rmdir /s /q " + folderPath;
    system(command.c_str());
}

//ɾ����ʱ�����ļ���
void delete_folds() {
    string folderPath = where();
    folderPath = folderPath + "\\lssj";
    string command;
    command = "rmdir /s /q " + folderPath;
    system(command.c_str());
}

//�������������ļ�
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

//������ʱ���������ļ�
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

//������ƽ�����������������ļ�
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

//��������ѧ�����������������ļ�
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

//������Ӣ������������������ļ�
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

//����������������������������ļ�
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
//����Ƿ�����
int check_common(Student *students, int n, const string &id) {
    int value = 0;
    for (int i = 0; i < n; i++) {
        if (students[i].id_output() == id) {
            value = 1;
        }
    }
    return value;
}

//����ѧ��
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

//��������ģʽ�����ش���ѧ���ļ�
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

//��������ģʽ�����ش���ѧ��
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

//���ѧ����Ϣ
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

//��id����
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
        cout << "û���ҵ�!" << endl;
}

//��������°�id���ң���������Ƿ��Ӧ��
void search_with_id(Student *&students, int n, const string &name) {
    string id;
    int value = 0;
    cout << "id: ";
    cin >> id;
    for (int i = 0; i < n; i++) {
        if (students[i].id_output() == id) {
            if (students[i].name_output() != name) {
                cout << "û���ҵ���Ϊ��" << name << "��idΪ��" << id << "��ѧ��!" << endl;
                cout << "������id���ҽ����" << endl;
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
        cout << "û���ҵ�!" << endl;
}

//����������
void search_with_name(Student *&students, int n) {
    string name;
    int value = 0;
    cout << "name: ";
    cin >> name;
    getchar();
    for (int i = 0; i < n; i++) {
        if (students[i].name_output() == name) {
            if (students[i].common_output() == 1) {
                cout << "����������������ѧ�Ų�ѯ��" << endl;
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
        cout << "û���ҵ�!" << endl;
}

//���ƽ����ѧ�ɼ�
void average_math(Student *&students, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += students[i].math_output();
    }
    cout << "ƽ����ѧ�ɼ���" << sum / (double) n << endl;
}

//���ƽ��Ӣ��ɼ�
void average_english(Student *&students, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += students[i].english_output();
    }
    cout << "ƽ��Ӣ��ɼ���" << sum / (double) n << endl;
}

//���ƽ��������ɼ�
void average_programming(Student *&students, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += students[i].programming_output();
    }
    cout << "ƽ��������ɼ���" << sum / (double) n << endl;
}

//��������ѧ�ɼ�
void best_math(Student *a, int n) {
    double max = a[0].math_output();
    for (int i = 0; i < n; i++) {
        if (a[i].math_output() > max) {
            max = a[i].math_output();
        }
    }
    cout << "�����ѧ�ɼ���" << max << endl;
}

//������Ӣ��ɼ�
void best_english(Student *a, int n) {
    double max = a[0].english_output();
    for (int i = 0; i < n; i++) {
        if (a[i].english_output() > max) {
            max = a[i].english_output();
        }
    }
    cout << "���Ӣ��ɼ���" << max << endl;
}

//�����߼�����ɼ�
void best_programming(Student *a, int n) {
    double max = a[0].programming_output();
    for (int i = 0; i < n; i++) {
        if (a[i].programming_output() > max) {
            max = a[i].programming_output();
        }
    }
    cout << "��߼�����ɼ���" << max << endl;
}

//��������ѧ�ɼ�
void worst_math(Student *a, int n) {
    double min = a[0].math_output();
    for (int i = 0; i < n; i++) {
        if (a[i].math_output() < min) {
            min = a[i].math_output();
        }
    }
    cout << "�����ѧ�ɼ���" << min << endl;
}

//������Ӣ��ɼ�
void worst_english(Student *a, int n) {
    double min = a[0].english_output();
    for (int i = 0; i < n; i++) {
        if (a[i].english_output() < min) {
            min = a[i].english_output();
        }
    }
    cout << "���Ӣ��ɼ���" << min << endl;
}

//�����ͼ�����ɼ�
void worst_programming(Student *a, int n) {
    double min = a[0].programming_output();
    for (int i = 0; i < n; i++) {
        if (a[i].programming_output() < min) {
            min = a[i].programming_output();
        }
    }
    cout << "��������ɼ���" << min << endl;
}

//�����ѧ����������
void no_pass_math(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].math_output() < 60) {
            count++;
        }
    }
    cout << "��ѧ������" << count << endl;
}

//���Ӣ�ﲻ��������
void no_pass_english(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].english_output() < 60) {
            count++;
        }
    }
    cout << "Ӣ�ﲻ����" << count << endl;
}

//������������������
void no_pass_programming(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].programming_output() < 60) {
            count++;
        }
    }
    cout << "�����������" << count << endl;
}

//�����ѧ60~69������
void l_math(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].math_output() >= 60 && a[i].math_output() <= 69) {
            count++;
        }
    }
    cout << "��ѧ60~69�֣�" << count << endl;
}

//���Ӣ��60~69������
void l_english(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].english_output() >= 60 && a[i].english_output() <= 69) {
            count++;
        }
    }
    cout << "Ӣ��60~69�֣�" << count << endl;
}

//��������60~69������
void l_programming(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].programming_output() >= 60 && a[i].programming_output() <= 69) {
            count++;
        }
    }
    cout << "�����60~69�֣�" << count << endl;
}

//�����ѧ70~79������
void q_math(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].math_output() >= 70 && a[i].math_output() <= 79) {
            count++;
        }
    }
    cout << "��ѧ70~79�֣�" << count << endl;
}

//���Ӣ��70~79������
void q_english(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].english_output() >= 70 && a[i].english_output() <= 79) {
            count++;
        }
    }
    cout << "Ӣ��70~79�֣�" << count << endl;
}

//��������70~79������
void q_programming(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].programming_output() >= 70 && a[i].programming_output() <= 79) {
            count++;
        }
    }
    cout << "�����70~79�֣�" << count << endl;
}

//�����ѧ80~89������
void b_math(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].math_output() >= 80 && a[i].math_output() <= 89) {
            count++;
        }
    }
    cout << "��ѧ80~89�֣�" << count << endl;
}

//���Ӣ��80~89������
void b_english(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].english_output() >= 80 && a[i].english_output() <= 89) {
            count++;
        }
    }
    cout << "Ӣ��80~89�֣�" << count << endl;
}

//��������80~89������
void b_programming(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].programming_output() >= 80 && a[i].programming_output() <= 89) {
            count++;
        }
    }
    cout << "�����80~89�֣�" << count << endl;
}

//�����ѧ����90������
void j_math(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].math_output() >= 90 && a[i].math_output() <= 100) {
            count++;
        }
    }
    cout << "��ѧ����90�֣�" << count << endl;
}

//���Ӣ�ﳬ��90������
void j_english(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].english_output() >= 90 && a[i].english_output() <= 100) {
            count++;
        }
    }
    cout << "Ӣ�ﳬ��90�֣�" << count << endl;
}

//������������90������
void j_programming(Student *a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].programming_output() >= 90 && a[i].programming_output() <= 100) {
            count++;
        }
    }
    cout << "���������90�֣�" << count << endl;
}

//�˵�
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
    system("color A");
    delete_fold();
    create_fold();
    cout << "��ӭʹ��ѧ���ɼ�����ϵͳ��" << endl;
    cout << "���Ƿ�֪��ѧ��������y/n����" << endl;
    char c;
    int n = 0;
    cin >> c;
    if (c == 'y') {
        cout << "������ѧ��������";
        retry:
        cin >> n;
        getchar();
        if (n == 0) {
            cout << "����������������룡" << endl;
            goto retry;
        }
        cout << "�밴��ѧ�š���������ѧ��Ӣ��������˳������ѧ���ɼ���" << endl;
        cout << "�����磺001 ���� 78 77 90��" << endl;
    } else if (c == 'n') {
        create_folds();
        cout << "��������ģʽ��" << endl;
        cout << "�밴��ѧ�š���������ѧ��Ӣ��������˳������ѧ���ɼ���" << endl;
        cout << "�����磺001 ���� 78 77 90��,idΪ0ʱֹͣ����" << endl;
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