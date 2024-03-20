#include<iostream>
#include<string>
using namespace std;

//������ϵ�˽ṹ��
struct ContactPerson {
	string name;
	string sex;
	int age;
	string phoneNumber;
	string address;
};

//���ܺ�����

//�˵�
void menu() {
	cout << "****************************************" << endl;
	cout << "**************1�������ϵ��*************" << endl;
	cout << "**************2����ʾ��ϵ��*************" << endl;
	cout << "**************3��ɾ����ϵ��*************" << endl;
	cout << "**************4��������ϵ��*************" << endl;
	cout << "**************5���޸���ϵ��*************" << endl;
	cout << "**************6�������ϵ��*************" << endl;
	cout << "**************0���˳�ͨѶ¼*************" << endl;
	cout << "****************************************" << endl;
}

//�����ϵ��
int insertContactPerson(ContactPerson contactPerson[]) {
	string inName;
	string inSex;
	int inAge;
	string inPhoneNumber;
	string inAddress;
	int i = 0;
	cout << "������"<<endl;
	cin >> inName;
	cout << "�Ա�" << endl;
	cin >> inSex;
	cout << "���䣺" << endl;
	cin >> inAge;
	cout << "�绰���룺" << endl;
	cin >> inPhoneNumber;
	cout << "��ַ��" << endl;
	cin >> inAddress;
	while (contactPerson[i].name != "") {
		i++;
	}
	if (i >= 0 && i <= 1000) {
		contactPerson[i].name = inName;
		contactPerson[i].sex = inSex;
		contactPerson[i].age = inAge;
		contactPerson[i].phoneNumber = inPhoneNumber;
		contactPerson[i].address = inAddress;
	}
	else {
		cout << "�����޶�����ϵ����1000����ɾ����ϵ�˺�����ӣ�" << endl;
	}
	return 0;
}

//��ʾ��ϵ��
void printContactPerson(ContactPerson contactPerson[]) {
	for (int i = 0; i < 1000;i++) {
		if (contactPerson[0].name=="") {
			cout << "��ϵ��Ϊ�գ�" << endl;
			break;
		}
		if (contactPerson[i].name!="") {
			cout << "������" << contactPerson[i].name << "\t�Ա�" << contactPerson[i].sex << "\t���䣺" << contactPerson[i].age
				<< "\t�绰��" << contactPerson[i].phoneNumber << "\t��ַ��" << contactPerson[i].address << endl;
		}
	}
}

//ɾ����ϵ��
int deleteContactPerson(ContactPerson contactPerson[]) {
	string delName;
	cout << "������Ҫɾ����ϵ�˵�������" << endl;
	cin >> delName;
	for (int i = 0; i < 1000;i++) {
		if (contactPerson[i].name == delName) {
			if (i == 999) {
				contactPerson[i] = {};
			}
			else {
				while (contactPerson[i + 1].name != "") {
					contactPerson[i] = contactPerson[i + 1];
					i++;
				}
				contactPerson[i] = {};
				break;
			}	
		}
		if (i==999& contactPerson[i].name != delName) {
			cout << "û������ɾ������ϵ�ˣ�" << endl;
			return 1;
		}
	}
	return 0;
}

//������ϵ��
void searchContactPerson(ContactPerson contactPerson[]) {
	string searName;
	cout << "������Ҫ������ϵ�˵�������" << endl;
	cin >> searName;
	if (contactPerson[0].name == "") {
		cout << "��ϵ��Ϊ�գ��������ϵ��!" << endl;
	}
	else {
		for (int i = 0; i < 1000;i++) {
			if (contactPerson[i].name == searName) {
				cout << "������" << contactPerson[i].name << "\t�Ա�" << contactPerson[i].sex << "\t���䣺" << contactPerson[i].age
					<< "\t�绰��" << contactPerson[i].phoneNumber << "\t��ַ��" << contactPerson[i].address << endl;
				break;
			}
			if (i == 999 && contactPerson[i].name != searName) {
				cout << "���޴��ˣ�" << endl;
			}
		}
	}
}

//�޸���ϵ��
int updateContactPerson(ContactPerson contactPerson[]) {
	string updName;
	cout << "������Ҫ�޸���ϵ�˵�������" << endl;
	cin >> updName;
	string newName;
	string newSex;
	int newAge;
	string newPhoneNumber;
	string newAddress;

	if (contactPerson[0].name == "") {
		cout << "��ϵ��Ϊ�գ��޷��޸�!" << endl;
	}
	else {
		for (int i = 0; i < 1000; i++) {
			if (contactPerson[i].name == updName) {
				cout << "������������" << endl;
				cin >> newName;
				cout << "�������Ա�" << endl;
				cin >> newSex;
				cout << "���������䣺" << endl;
				cin >> newAge;
				cout << "������绰��" << endl;
				cin >> newPhoneNumber;
				cout << "�������ַ��" << endl;
				cin >> newAddress;
				contactPerson[i].name = newName;
				contactPerson[i].sex = newSex;
				contactPerson[i].age = newAge;
				contactPerson[i].phoneNumber = newPhoneNumber;
				contactPerson[i].address = newAddress;
				break;
			}
			if (i == 999 && contactPerson[i].name != updName) {
				cout << "ͨѶ¼�в�������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
			}
		}
	}
	return 0;
}

//�����ϵ��
void clearContactPerson(ContactPerson contactPerson[]) {
	memset(contactPerson, 0, 1000);
	cout << "����գ�" << endl;
}


//������
int main() {
	
	//��ϵ�˶���
	ContactPerson contactPerson[1000] = {};

	
	int FLAG = 0;
	//����ѭ����
	while (1) {
		system("cls");
		menu();
		int functionNumber;
		cin >> functionNumber;

		switch (functionNumber) 
		{
		case 1: {
			int status1 = insertContactPerson(contactPerson);
			if (status1 == 0) {
				cout << "��ӳɹ���" << endl;
			}
			else {
				cout << "���ʧ�ܣ�" << endl;
			}
			system("pause");
			break;
		}
			
		case 2:
			printContactPerson(contactPerson);
			system("pause");
			break;
		case 3: {
			int status2 = deleteContactPerson(contactPerson);
			if (status2 == 0) {
				cout << "ɾ���ɹ���" << endl;
			}
			else {
				cout << "ɾ��ʧ�ܣ�" << endl;
			}
			system("pause");
			break;
		}
		case 4:
			searchContactPerson(contactPerson);
			system("pause");
			break;
		case 5: {
			int status3 = updateContactPerson(contactPerson);
			if (status3 == 0) {
				cout << "�޸ĳɹ���" << endl;
			}
			else {
				cout << "�޸�ʧ�ܣ�" << endl;
			}
			system("pause");
			break;
		}
		case 6:
			clearContactPerson(contactPerson);
			system("pause");
			break;
		case 0:
			FLAG = 1;
			break;
		default:
			cout << "��Ǹ��û����������Ĺ�����ţ���ȷ��������Ĺ��������0-6��Χ�ڣ����������룡"<<endl;
			system("pause");
			break;
		}

		if (FLAG == 1) {
			break;
		}
	}
	
	return 0;
}