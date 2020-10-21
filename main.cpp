/***********************************************
Name : Elton Wong Chun Meng
Id: 1181203056
Section: TC02
Title: Human Resource
***********************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

/*************************************Base Class : HrCrm*************************************/

//Comment : A superclass for the system.
class HrCrm {

protected:
    int id, selection;

public:
    HrCrm() {
        id = 0;
        selection = 0;
    }

    //Comment : virtual function that can share among the derived class and override by them.

    virtual void showSelection() {
        cout<<"Hello! Welcome to Elton's Human Resources Management System"<<endl;
        cout<<"************************************************************"<<endl<<endl;
    };

    //Comment : Feature of the system.

    void displayMenu() {
        cout<<"1. Add A New Staff"<<endl;
        cout<<"2. View Staff"<<endl;
        cout<<"3. Delete Staff"<<endl;
        cout<<"4. Update Staff"<<endl;
    }

    //Comment : Ask user to key in the selection of menu.

    void displayMenuSelection() {
        cout<<"Please key-in the number of the feature that you would like to access : "<<endl;
        cin>>selection;
        cout<<endl<<endl;

        if(selection<1 || selection>4) {
            cout<<"Invalid input of number !";
            exit(1);
        }
    }

    int getSelection() {
        return selection;
    }
};

/*************************************Derived Class : KeyInNewStaff*************************************/

//Comment : Derived class that ask user to key in the new staff information.
class KeyInNewStaff: public HrCrm {

private:
    int age, number;
    string name;
    float salary;

public:
    KeyInNewStaff() {
        age = 0;
        salary = 0.00;
        number = 0;
    }

    //Comment : Howmany staff information user would like to key in at the time.

    int keyInEnterNumber() {
        cout<<"How many times you would like to key in the new staff details ? "<<endl;
        cin>>number;

        return number;
    }

    int getkeyInEnterNumber() {
        return number;
    }

    //Comment : Overriding the virtual function to ask user to enter the new staff record.
    void showSelection() {

        cout<<"                     Add New Staff Record                         "<<endl;
        cout<<"************************************************************"<<endl<<endl;

        cout<<"Enter an ID : ";
        cin>>id;

        cin.ignore();

        cout<<"Enter the new employee's name : ";
        getline(cin, name);
        cout<<"Enter the new employee's age : ";
        cin>>age;
        cout<<"Enter the new employee's salary : ";
        cin>>salary;
    }

    int getkeyInID() {
        return id;
    }

    string getkeyInName() {
        return name;
    }

    int getkeyInAge() {
        return age;
    }

    float getkeyInSalary() {
        return salary;
    }

};

/*************************************Derived Class : ViewStaff*************************************/
//Comment : Derived class use to view staff in the system.
class ViewStaff: public HrCrm {

public:
    //Comment : Default constructor have no parameter and empty inside.
    ViewStaff() = default;

    void showSelection() {

        //Comment : Overriding the virtual function to output the staff record.
        cout<<"                       View Staff Record                           "<<endl;
        cout<<"************************************************************"<<endl<<endl;

        cout<<"Below is the list of employee in your company :";
        cout<<endl;
        cout<<endl;
    }
    //Comment : Header of the staff record.
    void showHeader() {
        cout<<"ID"<<setw(20)<<"Name"<<setw(20)<<"Age"<<setw(20)<<"Salary"<<endl;
        cout<<"--------------------------------------------------------------------"<<endl;
    }

};

/*************************************Derived Class : DeleteStaff*************************************/
//Comment : Derived class use to delete staff in the system.
class DeleteStaff: public HrCrm {

private:
    int deletestaff_id;

public:
    DeleteStaff() {
        deletestaff_id = 0;
    }

    void showSelection() {

        //Comment : Overriding the virtual function to delete the staff record.
        cout<<"                       Delete Staff Record                         "<<endl;
        cout<<"************************************************************"<<endl<<endl;

        cout<<"Enter the ID of employee that you wish to delete from the employee list : ";
        cin>>deletestaff_id;
    }

    int getdeleteStaffID() {
        return deletestaff_id;
    }
};

/*************************************Derived Class : UpdateStaff*************************************/
//Comment : Derived class use to update staff in the system.

class UpdateStaff: public HrCrm {

private:
    int updatestaff_id;
    int update_age;
    string update_name;
    float update_salary;

public:
    UpdateStaff() {
        updatestaff_id = 0;
    }

    void showSelection() {

        //Comment : Overriding the virtual function to update the staff record and ask user to key in the id that they wish to update.
        cout<<"                       Update Staff Record                         "<<endl;
        cout<<"************************************************************"<<endl<<endl;

        cout<<"Enter the ID of employee that you wish to update from the employee list : ";
        cin>>updatestaff_id;

        cin.ignore();
    }

    int getupdateStaffID() {
        return updatestaff_id;
    }

    //Comment : Enter all the new details to update the record.
    void updatestaffInput() {
        cout<<"Enter the new name for the existing staff : ";
        getline(cin, update_name);
        cout<<"Enter the new age for the existing staff : ";
        cin>>update_age;
        cout<<"Enter the new amount of salary for the existing staff : ";
        cin>>update_salary;
    }

    string getupdatestaffName() {
        return update_name;
    }

    int getupdatestaffAge() {
        return update_age;
    }

    float getupdatestaffSalary() {
        return update_salary;
    }

};

int main() {

    int number = 0;
    int file_keyin_id, file_keyin_age;
    float file_keyin_salary;
    string file_keyin_name;

    ofstream keyin_outfile;

    HrCrm hrcrm_obj;
    hrcrm_obj.showSelection();
    hrcrm_obj.displayMenu();
    hrcrm_obj.displayMenuSelection();

    //Comment : Create a dynamic memory allocation to the object of class KeyInNewStaff.
    KeyInNewStaff *keyin_obj = new KeyInNewStaff;

    /*************************************KeyInNewStaff*************************************/

    if(hrcrm_obj.getSelection() == 1) {

        //Comment : Object to access the function where ask user to key in how many number of staff they would like to key in.
        keyin_obj->keyInEnterNumber();

        //Comment : Return the number of how many.
        number = keyin_obj->getkeyInEnterNumber();

        //Comment : Create an object of the base class so that can use point to the address of key in object and use the virtual function.
        HrCrm *keyin_access_obj = &(*keyin_obj);

        //Comment : Open the file for writting.
        keyin_outfile.open("employee-d.txt", std::ios_base::app);

        if (!keyin_outfile) {
            cout << "File is not found !" << endl;
            exit(1);
        } else {
            for (int x = 0; x < number; x++) {

                //Comment : If the file is found, then return the id, name, age and salary data that user key in just now, so it can be wrote into the file.
                file_keyin_id = keyin_obj->getkeyInID();
                file_keyin_name = keyin_obj->getkeyInName();
                file_keyin_age = keyin_obj->getkeyInAge();
                file_keyin_salary = keyin_obj->getkeyInSalary();

                keyin_access_obj->showSelection();
                keyin_outfile << file_keyin_id << setw(15) << file_keyin_name << setw(15) << file_keyin_age << setw(15)
                              << file_keyin_salary << endl;
            }

            keyin_outfile.close();
        }

        delete keyin_obj;

        /*************************************ViewStaff*************************************/

    } else if (hrcrm_obj.getSelection() == 2) {

        //Comment : Create a dynamic memory allocation to the object of class ViewStaff.
        ViewStaff *viewstaff_obj = new ViewStaff;

        //Comment : Create an object of the base class so that can use point to the address of view staff object and use the virtual function.
        HrCrm *viewstaff_access_obj = &(*viewstaff_obj);
        viewstaff_access_obj -> showSelection();

        //Comment : Open the file for reading.
        ifstream viewstaff_infile;
        viewstaff_infile.open("employee-d.txt");

        file_keyin_id = keyin_obj -> getkeyInID();
        file_keyin_name = keyin_obj -> getkeyInName();

        //Comment : If the file is existed, then scan through the file and get all the information to be display on screen.
        if(viewstaff_infile.is_open()) {

            viewstaff_obj ->showHeader();
            while(viewstaff_infile>>file_keyin_id , getline(viewstaff_infile, file_keyin_name)) {
                cout<<file_keyin_id<<"\t"<<file_keyin_name<<endl;
            }

            viewstaff_infile.close();

        } else {
            cout<<"File is not found !"<<endl;
            exit(1);
        }

        delete viewstaff_obj;

        /*************************************DeleteStaff*************************************/

    } else if (hrcrm_obj.getSelection() == 3) {

        int deletestaff_id;

        //Comment : Create a dynamic memory allocation to the object of class DeleteStaff.
        DeleteStaff *deletestaff_obj = new DeleteStaff;

        //Comment : Create an object of the base class so that can use point to the address of delete staff object and use the virtual function.
        HrCrm *deletestaff_access_obj = &(*deletestaff_obj);
        deletestaff_access_obj ->showSelection();

        //Comment : To get the staff id that user key in to delete.
        deletestaff_id = deletestaff_obj->getdeleteStaffID();

        //Comment : Open one file for reading, another temp file for writting.
        ifstream deletestaff_infile;
        ofstream deletestaff_outfile;
        deletestaff_infile.open("employee-d.txt");
        deletestaff_outfile.open("temp_delete.txt", std::ios_base::app);

        if(deletestaff_infile.is_open()) {

            //Comment : If the id that user key in is not matched with the id that had key in inside the text file, the information
            // will be remain insde the text file, otherwise it will be deleted.
            while(deletestaff_infile>>file_keyin_id , getline(deletestaff_infile, file_keyin_name)) {

                if(file_keyin_id !=  deletestaff_id) {
                    deletestaff_outfile<<file_keyin_id<<setw(15)<<file_keyin_name<<endl;
                }
            }

            deletestaff_infile.close();
            deletestaff_outfile.close();
            //Comment : Remove the employee text file and replace with the temperoary text file
            // file will then rename back to original file name, so the file will be overwrite.
            remove("employee-d.txt");
            rename("temp_delete.txt", "employee-d.txt");

            cout<<"Delete Successfully ! Please proceed to view the latest employee list";
        } else {
            cout<<"File is not found !";
            exit(1);
        }

        delete deletestaff_obj;

        /*************************************UpdateStaff*************************************/

    } else if (hrcrm_obj.getSelection() == 4) {

        int updatestaff_id = 0;
        string update_name;
        int update_age;
        float update_salary;

        //Comment : Create a dynamic memory allocation to the object of class UpdateStaff.
        UpdateStaff *updatestaff_obj = new UpdateStaff;

        //Comment : Create an object of the base class so that can use point to the address of update staff object and use the virtual function.
        HrCrm *updatestaff_access_obj = &(*updatestaff_obj);
        updatestaff_access_obj ->showSelection();

        //Comment : Call the function that ask user to enter the new detail that update the existing info.
        updatestaff_obj->updatestaffInput();

        //Comment : Return all what user had inputted.
        update_name = updatestaff_obj->getupdatestaffName();
        update_age = updatestaff_obj->getupdatestaffAge();
        update_salary = updatestaff_obj->getupdatestaffSalary();

        //Comment : Open one file for reading, another temp file for writting.
        ifstream updatestaff_infile;
        ofstream updatestaff_outfile;
        updatestaff_infile.open("employee-d.txt");
        updatestaff_outfile.open("temp_update.txt", std::ios_base::app);

        if(updatestaff_infile.is_open()) {

            //Comment : If the id that user key in is not matched with the id that had key in inside the text file, the information
            // will be remain insde the text file, otherwise it will be updated with the latest informationof what user key in.
            while(updatestaff_infile>>file_keyin_id , getline(updatestaff_infile, file_keyin_name)) {

                if(file_keyin_id ==  updatestaff_id) {
                    updatestaff_outfile<<file_keyin_id<<setw(15)<<update_name<<setw(15)
                                       <<update_age<<setw(15)
                                       <<update_salary<< endl;
                } else {
                    updatestaff_outfile<<file_keyin_id<<setw(15)<<file_keyin_name;
                }

                updatestaff_outfile.close();
                updatestaff_infile.close();

                remove("employee-d.txt");
                rename("temp_update.txt", "employee-d.txt");
            }

            cout<<endl;
            cout<<"Update Successfully ! Please proceed to check the latest employee list";

            delete updatestaff_obj;

        } else {
            cout<<"File is not found !";
        }
    } else {
        cout<<"Invalid input !";
        exit(1);
    }

    return 0;
}