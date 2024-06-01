#include "People.h"
class StudentList
{
private:
	int size;
	Student* head;
public:
	StudentList() :head(nullptr),size(0){}//���캯����ʼ��
	void addStudent(Student* student);//���ѧ����Ϣ
	void deleteStudentID(string id);//����ѧ��ɾ��ѧ����Ϣ
	void find(int i);//����
	//Student* findStudent(int i);//����ѧ��
	void saveToFile(string filename);//��ѧ����Ϣд���ļ���
	void tihuanFile(string filename);//�����ı���Ϣ
    void loadFromFile(string filename);	//���ļ��м���ѧ����Ϣ
	void display();//��ʾѧ����Ϣ
	void SortStudent(int n);//����ѧ���ɼ����н�������0�������ģ�1������ѧ��2����Ӣ�3��������
	void SortID();//����ѧ�Ž�����������
	void swapData(Student* a, Student* b);//���������ڵ�����
	//��������
	~StudentList();
};
class Managerlist
{
private:
	int size;
	Manager* head;
public:
	Managerlist() :head(nullptr),size(0) {}
	//void remove(string rmv);//�Ƴ�
	//void add(Manager& manager);//�����Ϣ��������
	void load(Manager& manager, StudentList& studentlist);//��¼
	void display();
	Manager* find(Manager& a);//����
	void write();//д���ļ�
	bool yanzhengfind(Manager& a);
	~Managerlist();
};
class Teacherlist
{
private:
	int size;
	Teacher* head;
	Teacherlist():head(nullptr),size(0){}
	Teacher* find(Teacher& a);
	Teacher* yanzhengfind(Teacher& a);
	void remove(string rmv);//�Ƴ�
	void add(Teacher& a);//�����Ϣ��������
	void load(Teacher& a,StudentList& student);//��¼
	void Teacherdisplay();
	~Teacherlist();
};