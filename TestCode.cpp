#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    bool Login();

    void Controller();

    if(Login() == false)
    {
        cout<<"Logged In Faild!"<<endl;
        return 0;
    }
    cout<<"Successfully Logged In"<<endl;

    Controller();
    return 0;
}

void Controller()
{
    void ViewCompanyDetails();
    int DisplayMenu();
    void AddNewCorse();
    void DisplayCorses();
    void SearchCourse();
    void DeleteCourse();
    void AddStudentDetails();
    void DisplayStudents();
    void SearchStudent();
    void DeleteStudent();

    int SelectedMenuNumber = DisplayMenu();
    switch(SelectedMenuNumber)
    {
        case 0 : cout<<"Wrong Selection Number"<<endl;
        break;
        case 1 : ViewCompanyDetails();
        break;
        case 2 : AddNewCorse();
        break;
        case 3 : DisplayCorses();
        break;
        case 4 : SearchCourse();
        break;
        case 5 : DeleteCourse();
        break;
        case 6 : AddStudentDetails();
        break;
        case 7 : DisplayStudents();
        break;
        case 8 : SearchStudent();
        break;
        case 9 : DeleteStudent();
        break;
    }
}

bool Login()
{
    string UserName;
    string UserPassword;

    cout<<"===[System Started]==="<<endl;
    cout<<"Enter Your Account Details Below"<<endl;
    cout<<"User Name : ";
    cin>>UserName;
    cout<<"Password : ";
    cin>>UserPassword;


    ifstream ReadFile("LoginData.txt");
    string LineText;
    string CheckingInfo = UserName + " "+ UserPassword;
    while(getline(ReadFile, LineText))
    {
        if(LineText == CheckingInfo)
        {
            ReadFile.close();
            return true;
        }
    }
    ReadFile.close();
    return false;
}

int DisplayMenu()
{
     void SearchCourse();

     int SelectedNumber;
     cout<<"===[Action Menus]==="<<endl;
     cout<<"1. VIEW COMPANY DETAILS"<<endl;
     cout<<"2. REGISTER A NEW COURSE "<<endl;
     cout<<"3. DISPLAY AVAILABLE COURSES"<<endl;
     cout<<"4. SEARCH COURSE "<<endl;
     cout<<"5. DELETE COURSE "<<endl;
     cout<<"6. REGISTER STUDENTS DETAILS "<<endl;
     cout<<"7. DISPLAY STUDENT DETAILS "<<endl;
     cout<<"8. SEARCH STUDENT DETAILS "<<endl;
     cout<<"9. DELETE STUDENT DETAILS "<<endl;

     cout<<"==================="<<endl;

     cout<<"Select Sub Menu : ";
     cin >> SelectedNumber;

     return SelectedNumber;
}

void ViewCompanyDetails()
{
    void Controller();

    cout<<"Address: Mastermind Institute \n 123 Main Street \n Newyork, USA 202"<<endl;
    cout<<"\nMastermind Institute offers high-quality courses with dynamic learning environments,\n taught by experienced instructors. Choose from a wide range of courses in programming,\n data science, business, and marketing, designed for today's job market. We believe in your\n potential and are committed to helping you achieve your goals. Unlock your potential today\n and join Mastermind Institute.\n\n\n"<<endl;

    Controller();
}

void AddNewCorse()
{
    string CourseID,CourseName,CourseDuration,CourseFee;

    cout<<"===[Add Course]==="<<endl;
    cout<<"Enter Course ID : ";      cin >> CourseID;
    cout<<"Enter Course Name : ";    cin >> CourseName;
    cout<<"Enter Course Duration : ";cin >> CourseDuration;
    cout<<"Enter Course Fee : ";     cin >> CourseFee;

    string WriteString = CourseID + " " + CourseName + " " + CourseDuration + " " + CourseFee;

    ofstream FileToWrite("CourseDetails.txt",ios::app);
    FileToWrite << WriteString << endl;
    FileToWrite.close();

    cout<<"CourseSaved"<<endl;
    Controller();
}

void DisplayCorses()
{
    void Controller();
    ifstream ReadFile("CourseDetails.txt");

    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"|CourseID  |CourseName          |CourseDuration |CourseFee  |"<<endl;
    cout<<"-------------------------------------------------------------"<<endl;

    string CourseID,CourseName,CourseDuration,CourseFee;

    while (ReadFile >> CourseID >> CourseName >> CourseDuration >> CourseFee)
    {
        cout<<"|"+CourseID+"  |"+CourseName+"          |"+CourseDuration+" |"+CourseFee+"  |"<<endl;
    }

    ReadFile.close();
    Controller();
}

void SearchCourse()
{
    void Controller();
    string InputCourseID;
    cout<<"Enter CourseID : ";
    cin >> InputCourseID;

    ifstream ReadFile("CourseDetails.txt");

    string CourseID,CourseName,CourseDuration,CourseFee;

    while (ReadFile >> CourseID >> CourseName >> CourseDuration >> CourseFee)
    {
        if(InputCourseID == CourseID)
        {
            cout<<"|"+CourseID+"  |"+CourseName+"          |"+CourseDuration+" |"+CourseFee+"  |"<<endl;
        }
    }

    ReadFile.close();
    Controller();
}

void AddStudentDetails()
{
    void Controller();
    string StudentID,StudentName,StudentPhoneNumber,StudentEmail;

    cout<<"===[Add Course]==="<<endl;
    cout<<"Enter Student ID : ";      cin >> StudentID;
    cout<<"Enter Student Name : ";    cin >> StudentName;
    cout<<"Enter Student PhoneNumber : ";cin >> StudentPhoneNumber;
    cout<<"Enter Student Email : ";     cin >> StudentEmail;

    string WriteString = StudentID + " " + StudentName + " " +StudentPhoneNumber + " " + StudentEmail;

    ofstream FileToWrite("StudentDetails.txt",ios::app);
    FileToWrite << WriteString << endl;
    FileToWrite.close();

    cout<<"Student Saved"<<endl;
    Controller();
}

void DisplayStudents()
{
    void Controller();
    ifstream ReadFile("StudentDetails.txt");

    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"|StudentID  |StudentName          |StudentPhoneNo |Student Email  |"<<endl;
    cout<<"-------------------------------------------------------------------"<<endl;

    string StudentID,StudentName,StudentNumber,StudentEmail;

    while (ReadFile >> StudentID >> StudentName >> StudentNumber >> StudentEmail)
    {
        cout<<"|"+StudentID+"  |"+StudentName+"          |"+StudentNumber+" |"+StudentEmail+"  |"<<endl;
    }

    ReadFile.close();
    Controller();
}

void SearchStudent()
{
    void Controller();
    string InputStudentID;
    cout<<"Enter StudentID : ";
    cin >> InputStudentID;

    ifstream ReadFile("StudentDetails.txt");

    string StudentID,StudentName,StudentNumber,StudentEmail;

    while (ReadFile >> StudentID >> StudentName >> StudentNumber >> StudentEmail)
    {
        if(InputStudentID == StudentID)
        {
            cout<<"|"+StudentID+"  |"+StudentName+"          |"+StudentNumber+" |"+StudentEmail+"  |"<<endl;
        }
    }

    ReadFile.close();
    Controller();
}

void DeleteCourse()
{
    void Controller();

    string InputCourseID;
    cout<<"Enter CourseID : ";
    cin >> InputCourseID;

    ifstream DataFile("CourseDetails.txt");
    ofstream TempFile("Temp-CourseDetails.txt",ios::app);

    string CourseID,CourseName,CourseDuration,CourseFee;
    bool IsFound = false;
    while(DataFile >> CourseID >> CourseName >> CourseDuration >> CourseFee)
    {
        if(InputCourseID == CourseID)
        {
            IsFound = true;
        }
        else
        {
            string WriteString = CourseID + " " + CourseName + " " + CourseDuration + " " + CourseFee;
            TempFile<<WriteString<<endl;
        }
    }

    DataFile.close();
    TempFile.close();

    remove("CourseDetails.txt");
    rename("Temp-CourseDetails.txt","CourseDetails.txt");

    if(IsFound)
        cout<<"Course Deleted.."<<endl;
    else
         cout<<"Course Not Found.."<<endl;

    Controller();
}

void DeleteStudent()
{
    void Controller();

    string InputStudentID;
    cout<<"Enter StudentID : ";
    cin >> InputStudentID;

    ifstream DataFile("StudentDetails.txt");
    ofstream TempFile("Temp-StudentDetails.txt",ios::app);

    string StudentID,StudentName,StudentNumber,StudentEmail;
    bool IsFound = false;
    while(DataFile >> StudentID >> StudentName >> StudentNumber >> StudentNumber)
    {
        if(InputStudentID == StudentID)
        {
            IsFound = true;
        }
        else
        {
            string WriteString = StudentID + " " + StudentName + " " + StudentNumber + " " + StudentNumber;
            TempFile<<WriteString<<endl;
        }
    }

    DataFile.close();
    TempFile.close();

    remove("StudentDetails.txt");
    rename("Temp-StudentDetails.txt","StudentDetails.txt");

    if(IsFound)
        cout<<"Student Deleted.."<<endl;
    else
         cout<<"Student Not Found.."<<endl;

    Controller();
}

