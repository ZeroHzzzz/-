#include "List.h"
int main()
{
	Student student;
	StudentList studentlist;
	studentlist.loadFromFile("student.txt");
	string ID, password;
	int fh = 0;
	int i1 = 0, i2,i;
	while (i1 != -1)
	{
		i1 = 0, i2 = 0;
		i = 0;
		cout << "    ------------------------------------------------------\n";
		cout << "    |           ��ӭ����ѧ���ɼ�����ϵͳ                 |" << endl;
		cout << "    |           1.��ѯѧ����Ϣ                           |" << endl;
		cout << "    |           2.��¼                                   |" << endl;
		cout << "    ------------------------------------------------------\n";
		cout << "               ��ѡ��1/2,-1Ϊ��������";
		cin >> i1;
		switch (i1)
		{
		case 1:
			while (i != -1)
			{
				cout << "---------------------�Ƿָ���Ŷ------------------" << endl;
				cout << "1.����ѧ�Ų���" << endl;
				cout << "2.������������" << endl;
				cout << "3.��ѯ�ɼ�����" << endl;
				cout << "��ѡ��1/2/3������-1�����ϲ�ṹ����" << endl;
				cin >> i;
				switch (i)
				{
				case 1:
					while (fh != -1)
					{
						studentlist.find(i);
						cout << "�����������ַ���" << endl;
						cin >> fh;
						fh = -1;
					}
					break;
				case 2:
					while (fh != -1)
					{

						studentlist.find(i);
						cout << "�����������ַ���" << endl;
						cin >> fh;
						fh = -1;
					}
					break;
				case 3:
					while (fh != -1)
					{
						cout << "�������밴��һ�ſγ̽��н�������0�������ģ�1������ѧ��2����Ӣ�3��������" << endl;
						int n;
						cin >> n;
						studentlist.SortStudent(n);
						studentlist.display();
						cout << "�����������ַ���" << endl;
						cin >> fh;
						fh = -1;
					}
				}
			    fh = 0;
			}
			break;
		case 2:
			while (i2 != -1)
			{
				cout << "---------------------�Ƿָ���Ŷ------------------" << endl;
				cout << "�û�ѡ��" << endl;
				cout << "1.��ʦ��¼" << endl;
				cout << "2.������Ա��¼" << endl;
				cout << "��ѡ��1/2������-1�����ϲ�ṹ��" << endl;
				cin >> i2;
				if (i2 != -1)
				{
					if (i2 >= 3 || i2 <= 0)
						cout << "�������" << endl;
					else
					{
						cout << "�˺ţ�" << endl;
						cin >> ID;
						cout << "���룺" << endl;
						cin >> password;
					}
				}
			}
		default:
			cout << "�������" << endl;
			i1 = -1;
			break;
		}
	}
}




//	StudentList studentlist;
//	studentlist.loadFromFile("student.txt");//���ļ��м���ѧ����Ϣ
//	int choice;
//	do {
//		cout << "Student Grade Management System" << endl;
//		cout << "1.Add Student" << endl;
//		cout << "2.Modify Student Information" << endl;
//		cout << "3.Delete Student" << endl;
//		cout << "4.Search Student by ID" << endl;
//		cout << "5.Search Student by Name or Class" << endl;
//		cout << "6.Display All Students" << endl;
//		cout << "7.Save to File" << endl;
//		cout << "8.Exit" << endl;
//		cout << "Enter your choice:";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//		{
//			string name, classname;
//			char gender;
//			string ID;
//			double scores[4];
//			cout << "Enter student name:";
//			cin >> name;
//			cout << "Enter student gender(M/F):";
//			cin >> gender;
//			cout << "Enter studentID:";
//			cin >> ID;
//			cout << "Enter classname:";
//			cin >> classname;
//			cout << "Enter scores for 4 subjects:";
//			for (int i = 0; i < 4; i++)
//			{
//				cin >> scores[i];
//			}
//			Student* student = new Student(name, ID, gender, classname, scores);
//			studentlist.addStudent(student);
//			break;
//		}
//		case 2:
//		{
//			{
//				string id;
//				cout << "Enter student ID to modify:";
//				cin >> id;
//				Student* student = studentlist.findStudentID(id);
//				if (student != nullptr)
//				{
//					
//				}
//			}
//		}
//		}
//	} 
//	while (choice != 8);
//	return 0;
//}