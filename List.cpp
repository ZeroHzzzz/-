#include "List.h"
//����ѧ��
void StudentList::find(int i)
{
	string name = "null", ID = "null";
	Student* current = head;		
	bool flag = false;
	switch (i)
	{
	case 1:
		cout << "������ѧ��:";
		cin >> ID;	
		while (current != nullptr)
		{
			if (current->ID == ID)
			{
				cout << "�ҵ���ѧ��,";
				current->display();
				flag = true;
			}
			current = current->next;
		}
		if (flag == false)
		{
			cout << "δ�ҵ���ѧ��" << endl;
		}
		break;
	case 2:
		cout << "������������";
		cin >> name;
		while (current != nullptr)
		{
			if (current->name == name)
			{
				cout << "�ҵ���ѧ��,";
				current->display();
				flag = true;
			}
			current = current->next;
		}
		if (flag == false)
		{
			cout << "δ�ҵ���ѧ����" << endl;
		}
		break;
	default:
		cout << "�������" << endl;
		break;
	}
}
//���ѧ��
void StudentList::addStudent(Student* student)
{
	if (head == nullptr)
		head = student;
	else
	{
		Student* current = head;
		while (current != nullptr && current->next != nullptr)
		{
			current = current->next;
		} 
		current->next = student;
	}
}
//ɾ��ѧ��
void StudentList::deleteStudentID(string id)
{
	if (head == nullptr)//���ͷ�ڵ�Ϊ��
	{
		return;
	}
	if (head->ID == id)//���Ҫɾ���ڵ�Ϊͷ�ڵ�
	{
		Student* temp = head;
		head = head->next;
		delete temp;
		tihuanFile("student.txt");//�ļ�������ͬ��
		return;
	}
	Student* current = head;//Ҫɾ���ڵ㲻��ͷ�ڵ�
	while (current->next != nullptr && current->next->ID != id)
	{
		current = current->next;
	}
	if (current->next == nullptr)//���û�з��ϵ�ɾ���ڵ�
	{
		return;
	}
	//�ҵ���ɾ���Ľڵ�
	Student* temp = current->next;
	current->next = current->next->next;
	delete temp;
	tihuanFile("student.txt");//�ļ�������ͬ��
	return;
}
void StudentList::tihuanFile(string filename)
{
	ofstream infile(filename,ios::out);
	if (!infile)
	{
		cerr << "open error!" << endl;
		abort();
	}
	else
	{
		Student* current = head;
		while (current != nullptr)
		{
			infile << current->name << " " << current->gender << " " << current->ID << " " << current->classname << " ";
			for (int i = 0; i < 4; i++)
			{
				infile << current->score[i] << " ";
			}
			infile << endl;
			current = current->next;
		}
		infile.close();
	}
}
///д���ı�
void StudentList::saveToFile(string filename)
{
	ofstream infile(filename);
	if (!infile)
	{
		cerr << "open error!" << endl;
		abort();
	}
	else
	{
		Student* current = head;
		while (current != nullptr)
		{
			infile << current->name << " " << current->gender << " " << current->ID << " " << current->classname << " ";
			for (int i = 0; i < 4; i++)
			{
				infile << current->score[i] << " ";
			}
			infile << endl;
			current = current->next;
		}
		infile.close();
	}
}
//�ļ��м���ѧ����Ϣ
void StudentList::loadFromFile(string filename)
{
	ifstream infile(filename);
	if (!infile)
	{
		cerr << "open error!" << endl;
		abort();
	}
	else
	{
		string name, classname;
		char gender;
		string ID;
		double score[4];
		while (infile >> name >> gender >> ID >> classname)
		{
			for (int i = 0; i < 4; i++)
			{
				infile >> score[i];
			}
			Student* student = new Student(name,ID, gender, classname, score);
			addStudent(student);
		}
		infile.close();
	}
}
//��ʾѧ����Ϣ
void StudentList::display()
{
	Student* current = head;
	while (current != nullptr)
	{
		cout << "Name:" << current->name << ",Gender:" << current->gender << ",StudentID:" << current->ID << ",Class:" << current->classname << ",Score:";
		for (int i = 0; i < 4; i++)
		{
			cout << current->score[i] << " ";
		}
		cout << ",Total Score:" << current->totalScore << ",Average Score:";
		cout<< current->averageScore << endl;
		current = current->next;
	}
}
void StudentList::swapData(Student* a, Student* b) {
	// ���������ڵ��ȫ������
	Student temp = *a;
	*a = *b;
	*b = temp;
}
void StudentList::SortStudent(int n)
{
	if (head == nullptr)
	{
		return;
	}
	else {
		for (Student* current = head; current != nullptr; current = current->next)
		{
			Student* temp;
			Student* p = current;
			for (temp = current->next; temp != nullptr; temp = temp->next)
			{
				if (p->score[n] < temp->score[n]) 
				{
					p = temp;
				}
			}
			if (p != current) 
			{
				swapData(p, current);
			}
		}
	}
}
void StudentList::SortID()
{
	Student* current=head;
	Student* temp;
	if (current == nullptr)
		return;
	else
	{
		for (current = head; current->next; current = current->next)
		{
			Student* p = current;
			for (temp = current->next; temp; temp = temp->next)
			{
				if (p->ID  > temp->ID)
					p = temp;
			}
			if (p != current)
				swap(p, current);
		}
	}
	display();
}
StudentList::~StudentList()
{
	while (head != nullptr)
	{
		Student* temp = head;
		head = head->next;
		delete temp;
	}
}
////////////////////////////////////////////
//���ҽ�ʦ��Ϣ
Teacher* Teacherlist::find(Teacher& a)
{
	for (Teacher* m = head; m; m = m->next)
	{
		if (m->ID == a.ID)
			return m;
	}
	return nullptr;
}
Teacher* Teacherlist::yanzhengfind(Teacher& a)
{
	for (Teacher* m = head; m; m = m->next)
	{
		if (*m == a)
		{
			return m;
		}
	}
	return nullptr;
}
//��¼��ʦ�˻�
void Teacherlist::load(Teacher& a, StudentList& student)
{
	if (yanzhengfind(a))
	{
		Teacher* teacher;
		teacher = find(a);
		cout << "��¼�ɹ�" << endl;
		teacher->display();
		int n = 0, fh = 0;
		while (n != -1)
		{
			n = 0;
			fh = 0;
			cout << "---------------------�Ƿָ���Ŷ------------------" << endl;
			cout << "1.��ʾ������Ϣ" << endl;
			cout << "2.�޸�����" << endl;
			cout << "3.�޸�����" << endl;
			cout << "4.����ѧ�Ų�ѯѧ����Ϣ" << endl;
			cout << "5.�����������༶��ѯѧ����Ϣ" << endl;
			cout << "5.��ѯ�ɼ�ƽ����" << endl;
			cout << "";
		}
	}

}
/////////////////////////////////////
//���ҹ���Ա����Ϣ
Manager* Managerlist::find(Manager& a)
{
	for (Manager* m = head; m; m = m->next)
	{
		if (m->ID == a.ID)
		{
			return m;
		}
	}
}
//��֤�Ƿ��ҵ�
bool Managerlist::yanzhengfind(Manager& a)
{
	for (Manager* m = head; m; m = m->next)
	{
		if (*m == a)
		{
			return true;
		}
	}
	return false;
}
//��¼����Ա�˻�
void Managerlist::load(Manager& a, StudentList& studentlist)
{
	int fh = 0;
	if (yanzhengfind(a))
	{
		Manager* z;
		Student stu;
		Teacher tea;
		z = find(a);
		cout << "��¼�ɹ�" << endl;
		int n = 0, n4 = 0;
		while (n != -1)
		{
			n4 = 0;
			z->display();
			cout << "1.��ʾ������Ϣ" << endl;
			cout << "2.�޸�����" << endl;
			cout << "3.�޸�����" << endl;
			cout << "4.����ѧ���ɼ�" << endl;
			cout << "5.ά��ѧ����Ϣ" << endl;
			cout << "6.ά����ʦ��Ϣ" << endl;
			cout << "��ѡ������-1������һ��ṹ����" << endl;
			cin >> n;
			fh = 0;
			switch (n)
			{
			case 1:
				while (fh != -1)
				{
					z->display();
					cout << "�������������ַ���" << endl;
					cin >> fh;
					fh = -1;
				}
				break;
			case 2:
			{
				while (fh != -1)
				{
					z->changepass();
					cout << "�޸ĺ������Ϊ��" << z->getpass() << endl;
					write();
					cout << "�����������ַ���" << endl;
					cin >> fh;
					fh = -1;
				}
				break;
			case 3:
				while (fh != -1)
				{
					z->changeName();
					write();
					cout << "�޸ĺ������Ϊ��" << z->getname() << endl;
					cout << "�����������ַ���" << endl;
					cin >> fh;
					fh = -1;
				}
				break;
			}
			if (n == 4)
			{
				while (n4 != -1)
				{
					fh = 0;
					cout << "1.���ѧ��" << endl;
					cout << "2.ɾ��ѧ��" << endl;
					cout << "3.�޸�ѧ����Ϣ" << endl;
					cout << "��ѡ��1/2/3������-1�����ϲ�ṹ��";
					cin >> n4;
					switch (n4)
					{
					case1:
						while (fh != -1)
						{
							//				cout << "�������¼���ѧ����������";
						}
					}
				}
			}
			}
		}
	}
}
void Managerlist::display()
{
	for (Manager* p = head; p; p = p->next)
	{
		p->display();
	}
}
void Managerlist::write()
{
	ofstream out("manager.txt");
	for (Manager* p = head; p; p = p->next)
	{
		out << p->name << " " << p->ID << " " << p->getpass() << endl;
	}
}
Managerlist::~Managerlist()
{
	for (Manager* p = head; p = head; delete p)
	{
		head = head->next;
	}
}
