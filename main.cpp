#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include <windows.h>

using namespace std;

const char* HOST = "localhost";
const char* USER = "root";
const char* PSW = " ";
const char* DB = "testdb";




int main() {

	MYSQL* conn;
	conn = mysql_init(NULL);

	if (!mysql_real_connect(conn, HOST, USER, PSW, DB, 3306, NULL, 0)) {

		cout << "error:" << mysql_errno << endl;

	}
	else
	{
		cout << "Logged in database";
		Sleep(2000);

	}



	bool exit = false;

	while (!exit) {

		int val;
		cout << endl << endl;
		cout << "<---------------------->" << endl;
		cout << "1. Insert Data: " << endl;
		cout << "2. Delete Data: " << endl;
		cout << "3. Update Data: " << endl;
		cout << "0. Exit" << endl;
		cout <<"<---------------------->" << endl;
		cout << "Enter value: ";
		cin >> val;
		cout << endl << endl;
		cout << "<---------------------->" << endl;
		

		if (val == 1) {
			string id, name, surname, department;

			cout << "Studentid: ";
			cin >> id;
			cout << "Name: ";
			cin >> name;
			cout << "Surname: ";
			cin >> surname;
			cout << "Department: ";
			cin >> department;

			string query = "INSERT INTO students(studentid,Name,Surname,Department) VALUES('" + id + "','" + name + "','" + surname + "','" + department + "')";

			if (mysql_query(conn, query.c_str())) {

				cout << mysql_error(conn) << endl;
				cout << "<---------------------->" << endl;

			}
			else {
				cout << "Data inserted: " << endl << endl;
				cout << "<---------------------->" << endl;
			}
			Sleep(3000);


		}
		else if (val == 2) {
			string id;
			cout << "Enter id for delete: ";
			cin >> id;

			string del = "DELETE FROM students WHERE studentid= '"+id+"'";

			if (mysql_query(conn, del.c_str())) {

				cout << "Error: " << mysql_error(conn) << endl;
				cout << "<---------------------->" << endl;


			}
			else {
				cout << "Data deleted" << endl;
				cout << "<---------------------->" << endl;
			}
			Sleep(3000);


		}
		else if (val == 3) {

			string id;
			
			int val1;
			cout << "ENTER Students id: ";
			cin >> id;
			cout << "<---------------------->" << endl;
			cout << "1.Update Name:" << endl;
			cout << "2.Update Surname:" << endl;
			cout << "3.Update Department:" << endl;
			cout << "Enter value: ";
			cin >> val1;
			cout << endl;
			cout << "<---------------------->" << endl;


			if (val1 == 1) {
				string  name;

			
				cout << "Enter new name: ";
				cin >> name;

				string upd = "UPDATE students SET NAME ='" + name + "' WHERE studentid='" + id + "'";


				if (mysql_query(conn, upd.c_str())) {

					cout << "error:" << mysql_error << endl;

				}
				else
				{
					cout << "Data updated.";
				}

				Sleep(3000);





			}
			else if (val1 == 2) {

				string  surname;

			
				cout << "Enter new surname: ";
				cin >> surname;

				string upd = "UPDATE students SET Surname ='" + surname + "' WHERE studentid='" + id + "'";

				if (mysql_query(conn, upd.c_str())) {

					cout << "error:" << mysql_error << endl;

				}
				else
				{
					cout << "Data updated.";
				}

				Sleep(3000);



			}
			else if (val1 == 3) {
				string  department;

				cout << "Enter new Department: ";
				cin >> department;

				string upd = "UPDATE students SET Department ='" + department + "' WHERE studentid='" + id + "'";
				if (mysql_query(conn, upd.c_str())) {

					cout << "error:" << mysql_error << endl;

				}
				else
				{
					cout << "Data updated.";
				}

				Sleep(3000);


			}




		}

		else if (val == 0) {

			cout << "Good bye" << endl;
			cout << "<---------------------->" << endl;
			
			return 0;

		}



	}
}
