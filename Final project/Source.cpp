#include<iostream>
#include<string>
using namespace std;

class date {
private:
	int day;
	int month;
	int year;
public:
	date();
	date(int tday, int tmonth, int tyear);
	void setdate(int tday, int tmonth, int tyear);
	int getday();
	int getmonth();
	int getyear();
	void display();
};
date::date() :day(1), month(1), year(2002)
{}
date::date(int tday, int tmonth, int tyear) : day(tday), month(tmonth), year(tyear)
{}
void date::setdate(int tday, int tmonth, int tyear)
{
	day = tday;
	month = tmonth;
	year = tyear;
}
int date::getday()
{
	return day;
}
int date::getmonth()
{
	return month;
}
int date::getyear()
{
	return year;
}
void date::display()
{
	cout << day << " /" << month << " /" << year << endl;
}

class person {
protected:
	string first_name;
	string last_name;
	string Fathers_firstname;
	string Fathers_lastname;
	string CNIC;
	string Telephone;
	date date_of_birth;
public:
	person(string Tfirst_name = "NONE", string Tlast_name = "NONE", string tFathers_firstname = "NONE", string tFathers_lastname = "NONE", string tCNIC = "****-********-*", string Ttelephone = "000000", int tday = 1, int tmonth = 1, int tyear = 2000) :date_of_birth(tday, tmonth, tyear), first_name(Tfirst_name),
		last_name(Tlast_name), Fathers_firstname(tFathers_firstname), Fathers_lastname(tFathers_lastname), CNIC(tCNIC), Telephone(Ttelephone)
	{

	}
	virtual void setPerson(string Tfirst_name, string Tlast_name, string tFathers_firstname, string tFathers_lastname, string tCNIC, string Ttelephone, const date& tobj) = 0;

	string getfirst_name()
	{
		return first_name;
	}
	string getLast_name()
	{
		return last_name;
	}
	string getFather_first_name()
	{
		return Fathers_firstname;
	}
	string getFather_last_name()
	{
		return Fathers_lastname;
	}
	string getCNIC()
	{
		return CNIC;
	}
	string getTelephone()
	{
		return Telephone;
	}
	date getBirth()
	{
		return date_of_birth;
	}
	virtual void display() = 0;
};
class assesment {
private:
	string type;
	date date_of_assesment;
	int total_marks;
	float percentage;
	float* marks;
	int size;
	int count;
public:
	assesment(string Ttype = "NONE", int tday = 1, int tmonth = 1, int tyear = 2000, int tsize = 2, int ttotalmarks = 0, float Tpercentage = 0.0) :type(Ttype), date_of_assesment(tday, tmonth, tyear), size(tsize), count(0), total_marks(ttotalmarks), percentage(Tpercentage)
	{
		marks = new float[size];
	}
	void setAssesment(string Ttype, int tsize, int ttotalMark, const date& tobj)
	{
		type = Ttype;
		size = tsize;
		marks = new float[size];
		date_of_assesment = tobj;
		total_marks = ttotalMark;
	}
	void setMarks(float mark)
	{
		if (size > count)
		{
			marks[count] = mark;
			count++;
		}
		else
			cout << "You cannot Add more Student marks" << endl;
	}
	float getMarks(int index)
	{
		return marks[index];
	}
	int getFullmarks()
	{
		return total_marks;
	}
	string getType()
	{
		return type;
	}
	date getDate()
	{
		return date_of_assesment;
	}
	void DisplayAssesment(int index)
	{
		for (int i = 0; i < size; i++)
		{
			cout << "Assesment Name  " << type << endl;
			cout << "Date of Assesment" << endl;
			date_of_assesment.display();
				cout << marks[index] << endl;
			
		}
	}
};

class attendance 
{
private:
	char* attend;
	int size;
	date d;
	int count;
public:
	attendance(int tday = 1, int tmonth = 1, int tyear = 2000, int tsize = 2) : size(tsize), d(tday, tmonth, tyear), count(0)
	{
		attend = new char[size];
	}
	void setAttendance(int tsize)
	{
		size = tsize;
		attend = new  char[size];

	}
	void Setattendance_date(const date& tobj)
	{
		d = tobj;
	}
	void MarkAttendance(char t)
	{
		if (count < size)
		{
			attend[count] = t;
			count++;
		}
		else
			cout << "You cannot Mark more students Attendance" << endl;
	}
	char getAttendance(int index)
	{
		return attend[index];
	}
	date getDate()
	{
		return d;
	}
	void Display(int index)
	{
		d.display();
			
			cout  << attend[index] << endl;
		
	}
};
class student :public person
{
private:
	string student_ID;
	string field;
	int size;
	float CGPA;
	int matric_marks;
	string stu_password;
	int semester; 
	char* grade;
	int Fsc_marks;
	int *subject_grade_record;
	string* myCourse;
	int courselistSize;
	int gradecount;
	int record_count;
public:
	student(string Tstudent_ID = "000", string Tstu_password = "NONE", int tsemester=1, string tfield = "Pre-Engineering", float tcgpa = 0.0, int tsize = 2, int Tmatric = 0, int tFscMark = 0, string Tfirst_name = "NONE", string Tlast_name = "NONE", string tFathers_firstname = "NONE", string tFathers_lastname = "NONE", string tCNIC = "****-********-*", string Ttelephone = "000000", int tday = 1, int tmonth = 1, int tyear = 2000) : person(Tfirst_name, Tlast_name, tFathers_firstname, tFathers_lastname, tCNIC, Ttelephone, tday, tmonth, tyear), student_ID(Tstudent_ID), field(tfield), size(tsize), matric_marks(Tmatric), Fsc_marks(tFscMark), courselistSize(0), gradecount(0), stu_password(Tstu_password), record_count(0), CGPA(tcgpa),semester(tsemester)
	{
		myCourse = new string[size];
		grade = new char[size];
		subject_grade_record = new int[size];
	}
	void setPerson(string Tfirst_name, string Tlast_name, string tFathers_firstname, string tFathers_lastname, string tCNIC, string Ttelephone, const date& tobj)
	{
		first_name = Tfirst_name;
		last_name = Tlast_name;
		Fathers_firstname = tFathers_firstname;
		Fathers_lastname = tFathers_lastname;
		CNIC = tCNIC;
		Telephone = Ttelephone;
		date_of_birth = tobj;
	}
	void setStudent(string tid, string tfield, int Tmatric, int tFscMark, int tsize, string Tstu_password,int tsemester)
	{
		student_ID = tid;
		field = tfield;
		matric_marks = Tmatric;
		Fsc_marks = tFscMark;
		size = tsize;
		stu_password = Tstu_password;
		myCourse = new string[size];
		grade = new char[size];
		subject_grade_record = new int[size];
		semester = tsemester;
	}
	void setGPA(float t)
	{
		CGPA = t;
	}
	float getCGPA()
	{
		return CGPA;
	}
	void setMyCourse(string cid)
	{
		if (courselistSize < size)
		{
			myCourse[courselistSize] = cid;
			courselistSize++;
		}
		else
			cout << "You cannot Add More Courses to This Student" << endl;
	}
	void setCourseGrade(char g)
	{
		if (gradecount < size)
		{
			grade[gradecount] = g;
			gradecount++;
		}
		else
			cout << "All Courses Grades are assigned" << endl;
	}
	void SetgradeRecord(int t)
	{
		subject_grade_record[record_count] = t;
		record_count++;
	}
	int GetgradeRecord(int index)
	{
		return subject_grade_record[index];
	}
	int getsemester()
	{
		return semester;
	}
	int getRecordCount()
	{
		return record_count;
	}
	string getField()
	{
		return field;
	}
	string getStudentID()
	{
		return student_ID;
	}
	int GetCourseArraySize()
	{
		return size;
	}
	int getlistCount()
	{
		return courselistSize;
	}
	string getPassword()
	{
		return stu_password;
	}
	string getMycourse(int index)
	{
		return myCourse[index];
	}
	char getGrade(int index)
	{
		return grade[index];
	}
	int getGradecount()
	{
		return gradecount;
	}
	void dropcourse(int index)
	{

		for (int i = index, j = index + 1; i < courselistSize; i++, j++)
		{
			myCourse[i] = myCourse[j];
		}
		courselistSize--;
	}
	void display()
	{
		cout << "<------- Student Information ------->" << endl;
		cout << "Student Name: \t" << first_name << "\t" << last_name << endl;
		cout << "Student Father Name: \t" << Fathers_firstname << "\t" << Fathers_lastname << endl;
		cout << "Student ID :\t" << student_ID << endl;
		cout << "Qualification :\t" << field << endl;
		cout << "FSC Marks :\t" << Fsc_marks << endl;
		cout << "Matric Marks :\t" << matric_marks << endl;
		cout << "Semester :\t" << semester << endl;
		cout << "Date OF Birth :\t";
		date_of_birth.display();
		cout << "CNIC :\t" << CNIC << endl;
		cout << "Telephone Number :\t" << Telephone << endl;
	}
};
class attendance;
class assesment;
class Course {
private:
	string courseName;
	string courseCode;
	date startdate;
	string* stulist;
	assesment* assignment;
	attendance* lectureAttendance;
	string *Course_Teacher_id;
	int course_teacher_size;
	int size;
	int assignment_size;
	int attendance_size;
	int assignment_count;
	int attendance_count;
	int teacherCourse_count;
	int scount;
	int Credit_hour;
	
public:
	Course() :courseName("NONE"), courseCode("NONE"), startdate(1, 1, 2000), scount(0), size(2), assignment_size(1), attendance_size(30), course_teacher_size(2), assignment_count(0), attendance_count(0),teacherCourse_count(0),Credit_hour(0)
	{
		stulist = new string[size];
		assignment = new assesment[assignment_size];
		Course_Teacher_id = new string[course_teacher_size];
		lectureAttendance = new attendance[attendance_size];
	}
	Course(string cname, string  ccode, int tsize,int tcredit_h,int Tassignment_size, int tday, int tmonth, int tyear, int Tattendance_size, int Tcourse_teacherSIZE) : startdate(tday, tmonth, tyear), size(tsize), courseName(cname), assignment_size(Tassignment_size), attendance_size(Tattendance_size), courseCode(ccode), course_teacher_size(Tcourse_teacherSIZE),Credit_hour(tcredit_h)
	{
		if (size < 40)
		{
			stulist = new string[size];
		}
		else
		{
			cout << "The Limit of Student is 40. You can not exceed this limit!" << endl;
		}
		assignment = new assesment[assignment_size];
		attendance_size = Tattendance_size;
		lectureAttendance = new attendance[attendance_size];
		Course_Teacher_id = new string[course_teacher_size];
	}
	void setCourse(string cname, string  ccode, int tsize, const date& tobj,int tcredit_h)
	{
		courseName = cname;
		courseCode = ccode;
		startdate = tobj;
		Credit_hour = tcredit_h;
		size = tsize;
		if (size < 40)
		{
			stulist = new string[size];
		}
		else
		{
			cout << "You cannot add more than 40 Students in any Course" << endl;
			cin >> size;
			stulist = new string[size]; 
		}

	}
	void setCourseTeacherSize(int Tteacher_size)
	{
		course_teacher_size = Tteacher_size;
		Course_Teacher_id = new string[course_teacher_size];
	}
	void SetFacultyCourse(string tid)
	{
		if (teacherCourse_count < course_teacher_size)
		{
			Course_Teacher_id[teacherCourse_count] = tid;
			teacherCourse_count++;
		}
		else
			cout << "You can not ADD more Teacher in this Course" << endl;
	}
	
	void setCourseAssesmentSize(int Tattendance_size)
	{
		attendance_size = Tattendance_size;
		lectureAttendance = new attendance[attendance_size];
	}
	void SetCourseAttendanceSize(int Tassignmentsize)
	{
		assignment_size = Tassignmentsize;
		assignment = new assesment[assignment_size];

	}
	void setStulist(string sid)
	{
		if (scount < size)
		{
			stulist[scount] = sid;
			scount++;
		}
	}
	void setassesment(const assesment& tobj)
	{
		if (assignment_count < assignment_size)
		{
			assignment[assignment_count] = tobj;
			assignment_count++;
		}
		else
			cout << "You cannot Mark more Assesments" << endl;
	}
	void setAttendance(const attendance& tobj)
	{
		if (attendance_count < attendance_size)
		{
			lectureAttendance[attendance_count] = tobj;
			attendance_count++;
		}
		else
			cout << "You cannot Mark more Lectures Attendace" << endl;
	}
	int getTeacherCourse_count()
	{
		return teacherCourse_count;
	}
	int getAssignmentSize()
	{
		return assignment_size;
	}
	int getAssignmentCount()
	{
		return assignment_count;
	}
	int getAttendanceSize()
	{
		return attendance_size;
	}
	int getAttendancetCount()
	{
		return attendance_count;
	}
	assesment Getassesment(int index)
	{
		return assignment[index];
	}
	attendance getAttendance(int index)
	{
		return lectureAttendance[index];
	}
	string getname()
	{
		return courseName;
	}
	string getCode()
	{
		return courseCode;
	}
	date getdate()
	{
		return startdate;
	}
	string getStudentList(int index)
	{
		return stulist[index];
	}
	int getStudentListSize()
	{
		return size;
	}
	int getStudentListCount()
	{
		return scount;
	}
	int getCreditHours()
	{
		return Credit_hour;
	}
	string GetTeacherCourse(int index)
	{
		return Course_Teacher_id[index];
	}
	void dropstudent(string id)
	{
		for (int i = 0; i < scount; i++)
		{
			if (stulist[i] == id)
			{
				for (int j = i, k = i + 1; j < scount; j++, k++)
				{
					stulist[j] = stulist[k];
				}
				scount--;
				break;
			}
		}
	}
	void displayCourseInfo()
	{

		cout << "Course Name: " << courseName << "\nCourse Code:" << courseCode << endl;
		cout << "Starting Date of COURSE :" << endl;
		startdate.display();
	}
};
class Faculty :public person
{
private:
	string Teacher_ID;
	string qualification;
	string *course_id;
	string password;
	int course_size;
	int Course_count;

public:
	Faculty(string tTeacher_id = "NONE", string Tqualification = "NONE",string tpassword="NONE", int tcourse_size = 2, string Tfirst_name = "NONE", string Tlast_name = "NONE", string tFathers_firstname = "NONE", string tFathers_lastname = "NONE", string tCNIC = "****-********-*", string Ttelephone = "000000", int tday = 1, int tmonth = 1, int tyear = 2000) : person(Tfirst_name, Tlast_name, tFathers_firstname, tFathers_lastname, tCNIC, Ttelephone, tday, tmonth, tyear), Teacher_ID(tTeacher_id), qualification(Tqualification), course_size(tcourse_size), Course_count(0),password(tpassword)
	{
		course_id = new string[course_size];
	}
	void setPerson(string Tfirst_name, string Tlast_name, string tFathers_firstname, string tFathers_lastname, string tCNIC, string Ttelephone, const date& tobj)
	{
		first_name = Tfirst_name;
		last_name = Tlast_name;
		Fathers_firstname = tFathers_firstname;
		Fathers_lastname = tFathers_lastname;
		CNIC = tCNIC;
		Telephone = Ttelephone;
		date_of_birth = tobj;
	}
	void setFaculty(string tTeacher_id, string Tqualification,string tpassword,int tsize)
	{
		Teacher_ID = tTeacher_id;
		qualification = Tqualification;
		password = tpassword;
		course_size = tsize;
		course_id = new string[course_size];
	}
	void setTeachercourse(string Tcourse_id)
	{
		if (Course_count < course_size)
		{
			course_id[Course_count] = Tcourse_id;
			Course_count++;
		}
		else
			cout << "You cannot Assign more Course to this Teacher" << endl;
	}
	int getCOurseSize()
	{
		return course_size;
	}
	string getTeacherid()
	{
		return Teacher_ID;
	}
	string getTeacherQualification()
	{
		return qualification;
	}
	int getCourse_Count()
	{
		return Course_count;
	}
	string getTeacherCourse(int index)
	{
		return course_id[index];
	}
	string getTeachPassword()
	{
		return password;
	}
	void display()
	{
		cout << "<------- Faculty Information ------->" << endl;
		cout << "Teacher Name: \t" << first_name << "\t" << last_name << endl;
		cout << "Teacher Father Name: \t" << Fathers_firstname << "\t" << Fathers_lastname << endl;
		cout << "Teacher ID :\t" << Teacher_ID << endl;
		cout << "Qualification :\t" << qualification << endl;
		cout << "Date OF Birth";
		date_of_birth.display();
		cout << "CNIC :\t" << CNIC << endl;
		cout << "Telephone Number :\t" << Telephone << endl;
	}
};
class resolving {
private:
	Course* courselist;
	student* studentlist;
	Faculty* facultylist;
	int course_size;
	int student_size;
	int faculty_size;
	int scount = 0, ccount, fcount;
public:
	resolving(int Ctsize = 2, int Stsize = 2, int Ftsize = 2) :course_size(Ctsize), student_size(Stsize), faculty_size(Ftsize), scount(0), ccount(0), fcount(0)
	{
		courselist = new Course[course_size];
		studentlist = new student[student_size];
		facultylist = new Faculty[faculty_size];
	}
	void set(int Ctsize, int Stsize, int Ftsize)
	{
		course_size = Ctsize;
		student_size = Stsize;
		faculty_size = Ftsize;
		
		studentlist = new student[student_size];
		facultylist = new Faculty[faculty_size];
		courselist = new Course[course_size];
	}
	student getStudent(int index)
	{
		return studentlist[index];
	}
	Course getCourse(int index)
	{
		return courselist[index];

	}
	Faculty getFaculty(int index)
	{
		return facultylist[index];
	}
	int getStudentSize()
	{
		return student_size;
	}
	int getCourseSize()
	{
		return course_size;
	}
	int getFacultySize()
	{
		return faculty_size;
	}
	int getStudentCount()
	{
		return scount;
	}
	int getCourseCount()
	{
		return ccount;
	}
	int getFacultyCount()
	{
		return fcount;
	}
	void RegisterStudent(const student& tobj)
	{
		if (scount < student_size)
		{
			studentlist[scount] = tobj;
			++scount;
			
		}
		else
			cout << "SPACE FULL!\n You can not add more Students" << endl;
	}
	void RegisterCourse(const Course& tobj)
	{
		if (ccount < course_size)
		{
			courselist[ccount] = tobj;
			++ccount;
		}
		else
			cout << "SPACE FULL!\n You can not add more Course" << endl;
	}
	void RegisterFaculty(const Faculty& tobj)
	{
		if (fcount < faculty_size)
		{
			facultylist[fcount] = tobj;
			++fcount;
		}
		else
			cout << "SPACE FULL!\n You can not add more Faculty Members" << endl;
	}
	void RegisterStudentCourse(string sid)
	{
		int flag = 0;
		for (int i = 0; i < scount; i++)
		{
			int max = 0;
			// when student found
			if (studentlist[i].getStudentID() == sid)
			{

				flag = 1;
				for (int j = 0; j < ccount; j++)
				{
					int choice;
					courselist[j].displayCourseInfo();
					cout << "Do you want to register this course ?" << endl;
					cout << "IF yes Press 1 else Press 0" << endl << endl;
					cin >> choice;
					if (choice == 1)
					{
						if (max < studentlist[i].GetCourseArraySize())
						{
							studentlist[i].setMyCourse(courselist[j].getCode());
							courselist[j].setStulist(studentlist[i].getStudentID());
							max++;
						}
						else
						{
							cout << "You can only register  " << studentlist[i].GetCourseArraySize() << "  courses" << endl;
							break;
						}
					}
				}
			}
		}
		if (flag == 0)
		{
			cout << "There is no such ID of Student exist" << endl;
		}
	}
	void dropCourse(string sid)
	{
		int flag = 0;
		int index, choice;
		string id;
		for (int i = 0; i < scount; i++)
		{
			
			if (studentlist[i].getStudentID() == sid)
			{
				 flag = 1;
				index = studentlist[i].getlistCount();
				cout << "Your register courses  Are:" << endl;
				for (int j = 0; j < index; j++)
				{
					for (int n = 0;n < ccount;n++)
					{

						if (studentlist[i].getMycourse(j) == courselist[n].getCode())
						{

							cout << "\tDo you want to remove this course" << endl << endl;
							cout << "\tIF yes Press 1 else Press 0" << endl << endl;
							cin >> choice;
							if (choice == 1)
							{
								studentlist[i].dropcourse(j);
								courselist[j].dropstudent(sid);

							}
						}
					}
				}
				break;
			}
		}
		if (flag == 0)
		{
			cout << "There is no such ID of Student exist" << endl;
		}
	}
	void AssignFaculty(string fid)
	{
		int flag = 0;
		for (int i = 0; i < fcount; i++)
		{
			
			if (facultylist[i].getTeacherid() == fid)
			{
				flag = 1;
				for (int j = 0; j < ccount; j++)
				{
					int choice;
					courselist[j].displayCourseInfo();
					cout << "Do you want to take this course ?" << endl;
					cout << "IF yes Press 1 else Press 0" << endl << endl;
					cin >> choice;
					if (choice == 1)
					{
						if (facultylist[i].getCourse_Count() < facultylist[i].getCOurseSize())
						{
							facultylist[i].setTeachercourse(courselist[j].getCode());
							courselist[j].SetFacultyCourse(facultylist[i].getTeacherid());
						}
						else
						{
							cout << "You can not Assign more course to this teacher" << endl;
							break;
						}
					}
					
				}

			}
		}
		if (flag == 0)
		{
			cout << "There is no such ID of Faculty exist" << endl;
		}
	}
	void Mark_Attendance(string id, string Course_id,int size)
	{
		int tday, tmonth, tyear, flag = 0;
		date d;
		char t;
		for (int i = 0; i < fcount; i++)
		{
			//Finding Teacher
			if (facultylist[i].getTeacherid() == id)
			{
				//Find if Teacher teaches this course or not
				for (int l = 0; l < facultylist[i].getCourse_Count(); l++)
				{
					if (facultylist[i].getTeacherCourse(l) == Course_id)
					{
						flag = 1;
						//matching course ID with course List
						for (int j = 0; j < ccount; j++)
						{
							if (courselist[j].getCode() == Course_id)
							{
								courselist[j].SetCourseAttendanceSize(size);
								attendance object;
								for (int h = 0;h < courselist[j].getAttendanceSize();h++)
								{
									object.setAttendance(courselist[j].getStudentListSize());
									cout << "Enter Date" << endl;
									cout << "Enter Day :\n";
									cin >> tday;
									cout << "Enter Month :\n";
									cin >> tmonth;
									cout << "Enter Year :\n";
									cin >> tyear;
									d.setdate(tday, tmonth, tyear);
									object.Setattendance_date(d);
									for (int k = 0; k < courselist[i].getStudentListCount(); k++)
									{
										cout << "Enter Attendance of Student ID   " << courselist[i].getStudentList(k) << "  Attendance (P \ A)" << endl;
										cin >> t;
										object.MarkAttendance(t);
									}
									courselist[j].setAttendance(object);
								}
							}
						}
					}
				}
				if (flag == 0)
				{

					cout << "You are not Teaching such course with ID  " << Course_id << endl;

				}
			}
		}
	}
	void DisplayAttendance(string CourseID,string sid)
	{
		int size;
		int k = 0;
		int flag = 0;
		for (int i = 0; i < ccount; i++)
		{
			flag = 1;
			if (courselist[i].getCode() == CourseID)
			{
				for (;k < courselist[i].getStudentListSize();k++)
				{
					if (sid == courselist[i].getStudentList(k))
					{
						
					}
				}
				size = courselist[i].getAttendanceSize();
				if (size == 0)
				{
					cout << "Sorry! NO Attendance Mark for your this Course" << endl;
				}

				else
				{
					for (int j = 0; j < size; j++)
					{
						cout << "Lecture " << j + 1 << "Attendance Of Student\t" << sid << endl << endl;
						courselist[i].getAttendance(j).Display(k);
					}
				}
			}
		}
		if (flag == 0)
		{

			cout << "You are not Studying such course of ID  " << CourseID << endl;

		}
	}
	void MarkAssignment(string fid,string Course_id,int size)
	{
		assesment a;
		int tday, tmonth, tyear, tmark, flag = 0;
		string type;
		date d;
		float m;
		for (int i = 0; i < fcount; i++)
		{
			//Finding Teacher
			if (facultylist[i].getTeacherid() == fid)
			{
				//Find if Teacher teach this course or not
				for (int l = 0; l < facultylist[i].getCourse_Count(); l++)
				{
					if (facultylist[i].getTeacherCourse(l) == Course_id)
					{
						flag = 1;
						
						//matching course ID with course List
						for (int j = 0; j < ccount; j++)
						{
							if (courselist[j].getCode() == Course_id)
							{
								courselist[j].setCourseAssesmentSize(size);
								for (int h = 0;h < courselist[j].getAssignmentSize();h++)
								{
									cout << "Enter the Name Of Assesment" << endl;
									cin.ignore();
									getline(cin, type);
									cout << "Enter the Total Marks Of Assesment" << endl;
									cin >> tmark;
									cout << "Enter Date of Assesment" << endl;
									cout << "Enter Day :\n";
									cin >> tday;
									cout << "Enter Month :\n";
									cin >> tmonth;
									cout << "Enter Year :\n";
									cin >> tyear;
									d.setdate(tday, tmonth, tyear);
									a.setAssesment(type, courselist[j].getStudentListSize(), tmark, d);

									for (int n = 0; n < courselist[i].getStudentListCount(); n++)
									{
										cout << "Enter Student of ID " << courselist[i].getStudentList(n) << "  MARKS" << endl;
										cin >> m;
										a.setMarks(m);
									}
									courselist[j].setassesment(a);
								}
							}
						}
					}
				}
				if (flag == 0)
				{
					
						cout << "You are not Teaching such course with ID  " << Course_id << endl;
					
				}
			}
		}
	}
	void DisplayAssignment(string CourseID,string sid)
	{
		int size, k = 0,  flag = 0;
		for (int i = 0; i < ccount; i++)
		{
			if (courselist[i].getCode() == CourseID)
			{
				flag = 1;
				size = courselist[i].getAssignmentCount();
				if (size == 0)
				{
					cout << "Sorry! NO Assesment Mark for your this Course" << endl;
				}
				for (;k < courselist[i].getStudentListCount();k++)
				{
					if (sid == courselist[i].getStudentList(k))
					{
						for (int j = 0; j < size; j++)
						{
							cout << "Assesment  " << j + 1 << "  Marks Of Student\t" << sid << endl << endl;

							courselist[i].Getassesment(j).DisplayAssesment(k);
						}
					}
				}
			}
		}
		if (flag == 0)
		{

			cout << "You are not Studying such course of ID  " << CourseID << endl;

		}
	}
	void DeleteStudent(string sid)
	{
		for (int i = 0; i < scount; i++)
		{
			// when student found
			if (studentlist[i].getStudentID() == sid)
			{
				for (int j = i, k = i + 1; j < scount; j++, k++)
				{
					studentlist[j] = studentlist[k];
				}
				scount--;
			}
		}
	}
	void DeleteTeacher(string fid)
	{
		for (int i = 0; i < fcount; i++)
		{
			// when teacher found
			if (facultylist[i].getTeacherid() == fid)
			{
				for (int j = i, k = i + 1; j < fcount; j++, k++)
				{
					facultylist[j] = facultylist[k];
				}
				fcount--;
			}
		}
	}
	void DeleteCourse(string cid)
	{
		for (int i = 0; i < ccount; i++)
		{
			// when teacher found
			if (courselist[i].getCode() == cid)
			{
				for (int j = i, k = i + 1; j < ccount; j++, k++)
				{
					courselist[j] = courselist[k];
				}
				ccount--;
			}
		}
	}
	void updateStudent(const student& tobj, string sid)
	{
		
		for (int i = 0; i < scount; i++)
		{
			// when student found
			if (studentlist[i].getStudentID() == sid)
			{
				studentlist[i] = tobj;
				
			}
		}
	}
	void updateCourse(const Course& tobj, string cid)
	{
		
		for (int i = 0; i < ccount; i++)
		{
			// when course found
			if (courselist[i].getCode() == cid)
			{
				courselist[i] = tobj;
				
			}
		}
	}
	void updateFaculty(const Faculty& tobj, string fid)
	{
		
		for (int i = 0; i < fcount; i++)
		{
			// when teacher found
			if (facultylist[i].getTeacherid() == fid)
			{
				facultylist[i] = tobj;
			
			}
		}
	}
	void viewStudentINCourse(string fid)
	{
		for (int i = 0; i < fcount; i++)
		{
			int x;
			// when teacher found
			if (facultylist[i].getTeacherid() == fid)
			{
				for (int l = 0; l < facultylist[i].getCourse_Count(); l++)
				{
					for (int j = 0; j < ccount; j++)
					{
						if (facultylist[i].getTeacherCourse(l) == courselist[j].getCode())
						{
							cout << "Students enrolled in course   " << facultylist[i].getTeacherCourse(l) << "  are:" << endl;
							x = courselist[j].getStudentListCount();
							for (int k = 0; k < x; k++)
							{
								for (int m = 0; m < scount; m++)
								{
									if (courselist[j].getStudentList(k) == studentlist[m].getStudentID())
									{
										studentlist[m].display();
									}
								}
							}
						}
					}
				}
			}
		}
	}
	void AssignGrades(string fid,string course_id)
	{
		int flag = 0;
		float obt_total = 0, percentage, total_mark = 0;
		char g;
		for (int i = 0;i < fcount;i++)
		{
			if (facultylist[i].getTeacherid() == fid)
			{
				//Find if Teacher teach this course or not
				for (int l = 0; l < facultylist[i].getCourse_Count(); l++)
				{
					if (facultylist[i].getTeacherCourse(l) == course_id)
					{
						flag = 1;
						for (int j = 0;j < ccount;j++)
						{
							if (courselist[j].getCode() == course_id)
							{
								
									for (int m = 0;m < courselist[j].getStudentListCount();m++)
									{
										for (int k = 0;k < courselist[j].getAssignmentCount();k++)
										{
											obt_total = obt_total + courselist[j].Getassesment(k).getMarks(m);
											total_mark = total_mark + courselist[j].Getassesment(k).getFullmarks();
										}
										percentage = obt_total / total_mark * 100;
										cout << "Student of ID" << courselist[j].getStudentList(m) << " Has Percentage\t" << percentage << endl;
										cout << "What grade do you want to assign to this Student" << endl;
										cin >> g;
										for (int t = 0;t < courselist[j].getStudentListCount();t++)
										{
											if (studentlist[t].getStudentID() == courselist[j].getStudentList(m))
											{
												studentlist[t].setCourseGrade(g);
												for (int y = 0;y < studentlist[t].getlistCount();y++)
												{
													if (studentlist[t].getMycourse(y) == courselist[j].getCode())
													{
														studentlist[t].SetgradeRecord(y);
													}
												}
											}

										}

									}
							}
						}
					}
				}
			}
		}
		if (flag == 0)
		{

			cout << "You are not Teaching such course with ID  " << course_id << endl;

		}
	}
	void displayStudent(string sid)
	{
		int flag = 0;
		for (int i = 0;i < scount;i++)
		{
			if (studentlist[i].getStudentID() == sid)
			{
				studentlist[i].display();

				cout << "Student Registered courses Are :" << endl;
				for (int j = 0;j < studentlist[i].getlistCount();j++)
				{
					for (int k = 0;k < ccount;k++)
					{
						if (studentlist[i].getMycourse(j) == courselist[k].getCode())
						{
							flag = 1;
							courselist[k].displayCourseInfo();
						}
					}
				}
			}
		}
		if (flag == 0)
		{
			cout << "NO COURSES ARE REGISTERED" << endl;
		}
	}
	void displayFaculty(string fid)
	{
		int index;
		int flag = 0;
		for (int i = 0;i < fcount;i++)
		{
			if (facultylist[i].getTeacherid() == fid)
			{
				facultylist[i].display();
				index = facultylist[i].getCourse_Count();
				cout << facultylist[i].getfirst_name() << " " << facultylist[i].getLast_name() << "  is teaching following COURSES:" << endl;
				for (int j = 0;j < index;j++)
				{
					for (int k = 0;k < ccount;k++)
					{
						if (facultylist[i].getTeacherCourse(j) == courselist[k].getCode())
						{
							courselist[k].displayCourseInfo();
							flag = 1;
						}
					}

				}
			}
		}
		if (flag == 0)
		{
			cout << "NO COURSES ARE REGISTERED" << endl;
		}
	}
	void displaycourse()
	{
		for (int i = 0;i < ccount;i++)
		{
			courselist[i].displayCourseInfo();
			cout << "<---------------Faculty Information--------------------->" << endl;
			for (int j = 0;j < courselist[i].getTeacherCourse_count();j++)
			{
				for (int k = 0;k < fcount;k++)
				{
					if (courselist[i].GetTeacherCourse(j) == facultylist[k].getTeacherid())
					{
						 facultylist[k].display() ; 
					}
				}
			}

		}
	}
	bool password_student(string password)
	{
		int flag = 0;
		for (int i = 0;i < scount;i++)
		{
			if (password == studentlist[i].getPassword())
			{
				flag = 1;
				return true;
			}
		}
		if(flag==0)
		{
			return false;
        }
	}
	bool password_teacher(string password)
	{
		int flag = 0;
		for (int i = 0;i < fcount;i++)
		{
			if (password == facultylist[i].getTeachPassword())
			{
				return true;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			return false;
		}
	}
	void MakeGPA(string sid)
	{
		int x;
		double* arr, Total = 0.0;
		float total_creditH=0.0, CGPA;
		for (int i = 0;i < scount;i++)
		{
			if (studentlist[i].getStudentID() == sid)
			{
				x = studentlist[i].getGradecount();
				if (x != 0)
				{
					arr = new double[x];

					for (int j = 0;j < studentlist[i].getGradecount();j++)
					{
						if (studentlist[i].getGrade(j) == 'A')
						{
							arr[j] = 4.0;
						}
						else if (studentlist[i].getGrade(j) == 'A-')
						{
							arr[j] = 3.7;
						}
						else if (studentlist[i].getGrade(j) == 'B')
						{
							arr[j] = 3.5;
						}
						else if (studentlist[i].getGrade(j) == 'B-')
						{
							arr[j] = 3.2;
						}
						else if (studentlist[i].getGrade(j) == 'C')
						{
							arr[j] = 3.0;
						}
						else if (studentlist[i].getGrade(j) == 'C-')
						{
							arr[j] = 2.7;
						}
						else if (studentlist[i].getGrade(j) == 'D')
						{
							arr[j] = 2.5;
						}
						else if (studentlist[i].getGrade(j) == 'D-')
						{
							arr[j] = 2.2;
						}
						else if (studentlist[i].getGrade(j) == 'F')
						{
							arr[j] = 0;
						}
					}

					for (int k = 0;k < studentlist[i].getRecordCount();k++)
					{
						for (int l = 0;l < ccount;l++)
						{
							if (studentlist[i].getMycourse(studentlist[i].GetgradeRecord(k)) == courselist[l].getCode())
							{
								total_creditH = total_creditH + courselist[l].getCreditHours();
								Total = courselist[l].getCreditHours() * arr[k];
							}
						}
					}
					CGPA = Total / total_creditH;
					studentlist[i].setGPA(CGPA);
				}
				else
				{
					cout << "\t**Your Teachers did not Assign you Any Grades yet**" << endl;
				}
			}
		}
	}
	void ViewDMC(string sid)
	{
		for (int i = 0;i < scount;i++)
		{
			if (studentlist[i].getStudentID() == sid)
			{
				if (studentlist[i].getGradecount() == 0)
				{
					cout << "No Grades are Assigned to You!" << endl;
				}
				else
				{
					for (int k = 0;k < studentlist[i].getRecordCount();k++)
					{
						for (int l = 0;l < ccount;l++)
						{
							if (studentlist[i].getMycourse(studentlist[i].GetgradeRecord(k)) == courselist[l].getCode())
							{
								cout << "\tYour Grade in  " << courselist[l].getname()<<"  is"<< studentlist[i].getGrade(k) << endl;
							}
						}
					}
					cout << "\t**Your CGPA is" << studentlist[i].getCGPA()<<"   **" << endl;
				}
			}
		}
	}
	bool search_Student(string sid)
	{
		int flag = 0;
		for (int i = 0;i < scount;i++)
		{
			if (studentlist[i].getStudentID() == sid)
			{
				flag = 1;
				studentlist[i].display();
				return false;
			}
		}
		if (flag == 0)
		{
			cout << "***Student Not Found****" << endl;
			return false;
		}
	}
	bool search_teacher(string fid)
	{
		int flag = 0;
		for (int i = 0;i < fcount;i++)
		{
			if (facultylist[i].getTeacherid() == fid)
			{
				flag = 1;
				facultylist[i].display();
				return true;
			}
		}
		if (flag == 0)
		{
			cout << "***Teacher Not Found****" << endl;
			return false;
		}
	}
	bool search_course(string cid)
	{
		int flag = 0;
		for (int i = 0;i < ccount;i++)
		{
			if (courselist[i].getCode() == cid)
			{
				flag = 1;
				courselist[i].displayCourseInfo();
				return true;
			}
		}
		if (flag == 0)
		{
			cout << "***Course Not Found****" << endl;
			return false;
		}
	}
};
class resolving;
class admin:public person
{
private:
	resolving r;
public:
	admin(string Tfirst_name = "NONE", string Tlast_name = "NONE", string tFathers_firstname = "NONE", string tFathers_lastname = "NONE", string tCNIC = "****-********-*", string Ttelephone = "000000", int tday = 1, int tmonth = 1, int tyear = 2000) : person(Tfirst_name, Tlast_name, tFathers_firstname, tFathers_lastname, tCNIC, Ttelephone, tday, tmonth, tyear)
	{

	}
	void setPerson(string Tfirst_name, string Tlast_name, string tFathers_firstname, string tFathers_lastname, string tCNIC, string Ttelephone, const date& tobj)
	{
		first_name = Tfirst_name;
		last_name = Tlast_name;
		Fathers_firstname = tFathers_firstname;
		Fathers_lastname = tFathers_lastname;
		CNIC = tCNIC;
		Telephone = Ttelephone;
		date_of_birth = tobj;
	}
	void RegStudent(const student& tobj)
	{
		r.RegisterStudent(tobj);
	}
	void RegFaculty(const Faculty& tobj)
	{
		r.RegisterFaculty(tobj);
	}
	void RegCourse(const Course& tobj)
	{
		r.RegisterCourse(tobj);
	}
	void UpdateStu(const student& tobj,string sid)
	{
		r.updateStudent(tobj,sid);
	}
	void UpdateCourse(const Course& tobj, string cid)
	{
		r.updateCourse(tobj, cid);
	}
	void UpdateFaculty(const Faculty& tobj, string fid)
	{
		r.updateFaculty(tobj, fid);
	}
	void DeleteStudent(string sid)
	{
		r.DeleteStudent(sid);
	}
	void DeleteCourse(string cid)
	{
		r.DeleteCourse(cid);
	}
	void DeleteFaculty(string fid)
	{
		r.DeleteTeacher(fid);
	}
	bool searchTeacher(string fid)
	{
		bool a;
		a=r.search_teacher(fid);
		return a;
	}
	bool searchStudent(string sid)
	{
		bool a;
		a=r.search_Student(sid);
		return a;
	}
	bool searchCourse(string cid)
	{
		bool a;
		a=r.search_course(cid);
		return a;
	}
	void AssignTeacher_course(string fid)
	{
		r.AssignFaculty(fid);
	}
	void display()
	{
		cout << "<------- Admin Information ------->" << endl;
		cout << "Admin Name: \t" << first_name << "\t" << last_name << endl;
		cout << "Admin Father Name : \t" << Fathers_firstname << "\t" << Fathers_lastname << endl;
		cout << "Date OF Birth";
		date_of_birth.display();
		cout << "CNIC :\t" << CNIC << endl;
		cout << "Telephone Number :\t" << Telephone << endl;
	}  
};



int AdminMenu();
int personChoice();
int StudentMenu();
int TeacherMenu();
int main()
{
	//resolving r;
	//admin ad;
	string first_name;
	string last_name;
	string Fathers_firstname;
	string Fathers_lastname;
	string CNIC, password;
	string Telephone;
	string id, qualification, id2;
	int month, year, day;
	string field, course_code;
	int size, credit_h, semester;
	int matric_marks;
	int Fsc_marks;
	bool status;
	date d;
	student s;
	Faculty f;
	Course c;
	admin a;
	resolving r;
	
	//string password;
	//bool status;
	int stu_size, tech_size, course_size;
	cout << "Enter MAX. Limit of Students in LMS" << endl;
	cin >> stu_size;
	cout << endl << endl;
	cout << "Enter MAX. Limit of Teachers in LMS" << endl;
	cin >> tech_size;
	cout << endl << endl;
	cout << "Enter MAX. Limit of Courses in LMS" << endl;
	cin >> course_size;
	cout << endl << endl;
	r.set(course_size, stu_size, tech_size);
	int choice = personChoice();
	while (choice != 4)
	{
		if (choice == 1)
		{
			//Admin_switch();
			int x = AdminMenu();
			while (x != 14)
			{

				switch (x)
				{
					case 1:
						if (r.getStudentCount() < r.getStudentSize())
						{
							cout << "Enter the First Name of the Student" << endl;
							cin.ignore();
							getline(cin, first_name);
							cout << "Enter the Last Name of the Student" << endl;
							//cin.ignore();
							getline(cin, last_name);
							cout << "Enter the First Name of  Student Father" << endl;
							//cin.ignore();
							getline(cin, Fathers_firstname);
							cout << "Enter the Last Name of  Student Father" << endl;
							//cin.ignore();
							getline(cin, Fathers_lastname);
							cout << "\nEnter the date of Birth" << endl;
							cout << "Enter Day :\n";
							cin >> day;
							cout << "Enter Month :\n";
							cin >> month;
							cout << "Enter Year :\n";
							cin >> year;
							cout << "Enter the CNIC of Student" << endl;
							cin.ignore();
							getline(cin, CNIC);
							cout << "ENTER the Telephone Number of Student" << endl;
							//cin.ignore();
							getline(cin, Telephone);
							cout << "Enter ID of Student" << endl;
							//cin.ignore();
							getline(cin, id);
							cout << "Enter Password/Cardential for Student" << endl;
							//cin.ignore();
							getline(cin, password);

							cout << "Enter Student Field" << endl;
							//cin.ignore();
							getline(cin, field);
							cout << "Enter Student Fsc Marks" << endl;
							cin >> Fsc_marks;
							cout << "Enter Student Matric Marks" << endl;
							cin >> matric_marks;
							cout << "Enter Student Semester" << endl;
							cin >> semester;
							cout << "How many Course A student can Register" << endl;
							cin >> size;
							d.setdate(day, month, year);
							s.setPerson(first_name, last_name, Fathers_firstname, Fathers_lastname, CNIC, Telephone, d);
							s.setStudent(id, field, matric_marks, Fsc_marks, size, password, semester);

							r.RegisterStudent(s);
						}
						else
						{
							cout << "\t**Student Limit has been reached**" << endl;
						}
						x = AdminMenu();
						break;

					case 2:
						if (r.getFacultyCount() < r.getFacultySize())
						{
							cout << "Enter the First Name of the Teacher" << endl;
							cin.ignore();
							getline(cin, first_name);
							cout << "Enter the Last Name of the Teacher" << endl;
							//cin.ignore();
							getline(cin, last_name);
							cout << "Enter the First Name of  Teacher Father" << endl;
							//cin.ignore();
							getline(cin, Fathers_firstname);
							cout << "Enter the Last Name of  Teacher Father" << endl;
							//cin.ignore();
							getline(cin, Fathers_lastname);
							cout << "\nEnter the date of Birth" << endl;
							cout << "Enter Day :\n";
							cin >> day;
							cout << "Enter Month :\n";
							cin >> month;
							cout << "Enter Year :\n";
							cin >> year;
							cout << "Enter the CNIC of Teacher" << endl;
							cin.ignore();
							getline(cin, CNIC);
							cout << "ENTER the Telephone Number of Teacher" << endl;
							//cin.ignore();
							getline(cin, Telephone);
							cout << "Enter ID of Teacher" << endl;
							//cin.ignore();
							getline(cin, id);
							cout << "Enter Password/Cardential for Teacher" << endl;
							//cin.ignore();
							getline(cin, password);
							cout << "Enter Your Qualification" << endl;
							//cin.ignore();
							getline(cin, qualification);
							cout << "How many Course A Teacher can Teach" << endl;
							cin >> size;
							d.setdate(day, month, year);
							f.setPerson(first_name, last_name, Fathers_firstname, Fathers_lastname, CNIC, Telephone, d);
							f.setFaculty(id, qualification, password, size);
							r.RegisterFaculty(f);
						}
						else
						{
							cout << "\t**Teacher Limit has been reached" << endl;
						}
						x = AdminMenu();
						break;

					case 3:
						if (r.getCourseCount() < r.getCourseSize())
						{
							cout << "Enter the Course Name" << endl;
							cin.ignore();
							getline(cin, first_name);
							cout << "Enter Course Code" << endl;
							//cin.ignore();
							getline(cin, id);
							cout << "\nEnter Starting  Date of Course" << endl;
							cout << "Enter Day :\n";
							cin >> day;
							cout << "Enter Month :\n";
							cin >> month;
							cout << "Enter Year :\n";
							cin >> year;
							d.setdate(day, month, year);
							cout << "Enter the Credit Hour Of Course" << endl;
							cin >> credit_h;
							cout << "Enter the Number of Students that can Study this Course" << endl;
							cin >> size;
							c.setCourse(first_name, id, size, d, credit_h);
							cout << "Enter the number of Teacher that can Teach this Course" << endl;
							cin >> size;
							c.setCourseTeacherSize(size);
							r.RegisterCourse(c);
						}
						else
						{
							cout << "\t**Course Limit has been reached**" << endl;
						}
						x = AdminMenu();
						break;
					case 4:
						cout << "Which Student You want to Update . Enter ID!" << endl;
						cin.ignore();
						getline(cin, id2);
						status = r.search_Student(id2);
						if (status == true)
						{
							cout << "Enter the First Name of the Student" << endl;
							cin.ignore();
							getline(cin, first_name);
							cout << "Enter the Last Name of the Student" << endl;
							//cin.ignore();
							getline(cin, last_name);
							cout << "Enter the First Name of  Student Father" << endl;
							//cin.ignore();
							getline(cin, Fathers_firstname);
							cout << "Enter the Last Name of  Student Father" << endl;
							//cin.ignore();
							getline(cin, Fathers_lastname);
							cout << "\nEnter the date of Birth" << endl;
							cout << "Enter Day :\n";
							cin >> day;
							cout << "Enter Month :\n";
							cin >> month;
							cout << "Enter Year :\n";
							cin >> year;
							cout << "Enter the CNIC of Student" << endl;
							cin.ignore();
							getline(cin, CNIC);
							cout << "ENTER the Telephone Number of Student" << endl;
							//cin.ignore();
							getline(cin, Telephone);
							cout << "Enter ID of Student" << endl;
							//cin.ignore();
							getline(cin, id);
							cout << "Enter Password/Cardential for Student" << endl;
							//cin.ignore();
							getline(cin, password);
							cout << "**" << password << endl;
							cout << "Enter Student Field" << endl;
							//cin.ignore();
							getline(cin, field);
							cout << "Enter Student Fsc Marks" << endl;
							cin >> Fsc_marks;
							cout << "Enter Student Matric Marks" << endl;
							cin >> matric_marks;
							cout << "Enter Student Semester" << endl;
							cin >> semester;
							cout << "How many Course A student can Register" << endl;
							cin >> size;
							d.setdate(day, month, year);
							s.setPerson(first_name, last_name, Fathers_firstname, Fathers_lastname, CNIC, Telephone, d);
							s.setStudent(id, field, matric_marks, Fsc_marks, size, password, semester);

							r.updateStudent(s, id2);
						}
					
						x = AdminMenu();
						break;
					case 5:
						cout << "Which Teacher You want to Update . Enter ID!" << endl;
						cin.ignore();
						getline(cin, id2);
						status = r.search_teacher(id2);

						if (status == true)
						{
							cout << "Enter the First Name of the Teacher" << endl;
							cin.ignore();
							getline(cin, first_name);
							cout << "Enter the Last Name of the Teacher" << endl;
							cin.ignore();
							getline(cin, last_name);
							cout << "Enter the First Name of  Teacher Father" << endl;
							cin.ignore();
							getline(cin, Fathers_firstname);
							cout << "Enter the Last Name of  Teacher Father" << endl;
							cin.ignore();
							getline(cin, Fathers_lastname);
							cout << "\nEnter the date of Birth" << endl;
							cout << "Enter Day :\n";
							cin >> day;
							cout << "Enter Month :\n";
							cin >> month;
							cout << "Enter Year :\n";
							cin >> year;
							cout << "Enter the CNIC of Teacher" << endl;
							cin.ignore();
							getline(cin, CNIC);
							cout << "ENTER the Telephone Number of Teacher" << endl;
							cin.ignore();
							getline(cin, Telephone);
							cout << "Enter ID of Teacher" << endl;
							cin.ignore();
							getline(cin, id);
							cout << "Enter Password/Cardential for Teacher" << endl;
							cin.ignore();
							getline(cin, password);
							cout << "Enter Your Qualification" << endl;
							cin.ignore();
							getline(cin, qualification);
							cout << "How many Course A Teacher can Teach" << endl;
							cin >> size;
							d.setdate(day, month, year);
							f.setPerson(first_name, last_name, Fathers_firstname, Fathers_lastname, CNIC, Telephone, d);
							f.setFaculty(id, qualification, password, size);
							r.updateFaculty(f, id2);
						}
						x = AdminMenu();
						break;
					case 6:
						cout << "Which Course You want to Update . Enter Course Code !" << endl;
						cin.ignore();
						getline(cin, id2);
						status = r.search_course(id2);

						if (status == true)
						{
							cout << "Enter Course Name " << endl;
							cin.ignore();
							getline(cin, first_name);
							cout << "Enter Course Code" << endl;
							cin.ignore();
							getline(cin, id);
							cout << "\nEnter Starting  Date of Course" << endl;
							cout << "Enter Day :\n";
							cin >> day;
							cout << "Enter Month :\n";
							cin >> month;
							cout << "Enter Year :\n";
							cin >> year;
							d.setdate(day, month, year);
							cout << "Enter the Credit Hour Of Course" << endl;
							cin >> credit_h;
							cout << "Enter the Number of Students that can Study this Course" << endl;
							cin >> size;
							c.setCourse(first_name, id, size, d, credit_h);
							cout << "Enter the number of Teacher that can study this Course" << endl;
							cin >> size;
							c.setCourseTeacherSize(size);
							r.updateCourse(c, id2);
						}
						x = AdminMenu();
						break;
					case 7:
						cout << "Which Student You want to Delete . Enter Student ID !" << endl;
						cin.ignore();
						getline(cin, id2);
						r.DeleteStudent(id2);
						x = AdminMenu();
						break;
					case 8:
						cout << "Which Teacher You want to Delete . Enter Teacher ID  !" << endl;
						cin.ignore();
						getline(cin, id2);
						r.DeleteTeacher(id2);
						x = AdminMenu();
						break;
					case 9:
						cout << "Which Course You want to Delete . Enter Course Code !" << endl;
						cin.ignore();
						getline(cin, id2);
						r.DeleteCourse(id2);
						x = AdminMenu();
						break;
					case 10:
						cout << "Enter the ID of Teacher of Which you want to Assign Courses" << endl;
						cin >> id;
						r.AssignFaculty(id);
						x = AdminMenu();
						break;
					case 11:
						cout << "Which Student You want to Search . Enter Student ID !" << endl;
						cin.ignore();
						getline(cin, id2);
						r.search_Student(id2);
						x = AdminMenu();
						break;
					case 12:
						cout << "Which Teacher You want to Search . Enter Teacher ID !" << endl;
						cin.ignore();
						getline(cin, id2);
						r.search_teacher(id2);
						x = AdminMenu();
					case 13:
						cout << "Which Course You want to Search . Enter Course Code !" << endl;
						cin.ignore();
						getline(cin, id2);
						r.search_course(id2);
						x = AdminMenu();
					default:
						cout << "Invalid Input!  Input Again" << endl;
						x = AdminMenu();
						break;
				}
			}
			
		}
		else if (choice == 2)
		{
			
			
			cout << "Enter your Password" << endl;
			cin.ignore();
			getline(cin,password);
			status = r.password_student(password);
			if (status == true)
			{
				int x=StudentMenu();
				while (x != 7)
				{
					switch (x)
					{
						case 1:
							if (r.getCourseCount() == 0)
							{
								cout << "There Are no Courses Registered in LMS" << endl;
								cout << "Consult Admin!" << endl;
							}
							else
							{
								cout << "Enter your ID..." << endl;
								cin.ignore();
								getline(cin, id);
								r.RegisterStudentCourse(id);
							}
							x = StudentMenu();
							break;
						case 2:
							
								cout << "Enter your ID..." << endl;
								cin.ignore();
								getline(cin, id);
								r.dropCourse(id);
							
							x = StudentMenu();
							break;
						case 3:
							cout << "Enter your ID..." << endl;
							cin.ignore();
							getline(cin, id);
							cout << "Enter your COURSE CODE of which You want to see Assignments" << endl;

							r.DisplayAssignment(course_code, id);
							x = StudentMenu();
							break;
						case 4:
							cout << "Enter your ID..." << endl;
							cin.ignore();
							getline(cin, id);
							cout << "Enter your COURSE CODE of which You want to see Attendance" << endl;
							cin >> course_code;
							r.DisplayAttendance(course_code, id);
							x = StudentMenu();
							break;
						case 5:
							cout << "Enter your ID..." << endl;
							cin.ignore();
							getline(cin, id);
							r.MakeGPA(id);
							r.ViewDMC(id);
							x = StudentMenu();
							break;
						case 6:
							cout << "Enter your ID..." << endl;
							cin.ignore();
							getline(cin, id);
							r.displayStudent(id);
							x = StudentMenu();
							break;
						default:
							cout << "Invalid Input!  Input Again" << endl;
							x = StudentMenu();
							break;
					}
				}
			}
			else
			{
				cout << "\tThere is no student exist with such PASSWORD" << endl << endl;
				cout << "\tPlease go to Admin Office to Register Yourself" << endl << endl;
				system("pause");
			}
		}
		else if (choice == 3)
		{
		
			cout << "Enter your Password" << endl;
			cin.ignore();
			cin>>password;
			status=r.password_teacher(password);
			if (status == true)
			{
				int x = TeacherMenu();
				while (x != 6)
				{
					switch (x)
					{
						case 1:
							cout << "Enter your ID..." << endl;
							cin.ignore();
							getline(cin, id);
							r.viewStudentINCourse(id);
							x = TeacherMenu();
							break;
						case 2:
							cout << "Enter your ID..." << endl;
							cin.ignore();
							getline(cin, id);
							r.displayFaculty(id);
							x = TeacherMenu();
							break;
						case 3:
							cout << "Enter your ID..." << endl;
							cin.ignore();
							getline(cin, id);
							cout << "How many Assessments do you want to Mark" << endl;
							cin >> size;
							cout << "Enter the Course ID of which You want to mark Assesment" << endl;
							cin >> course_code;
							r.MarkAssignment(id, course_code, size);
							x = TeacherMenu();
							break;
						case 4:
							cout << "Enter your ID..." << endl;
							cin.ignore();
							getline(cin, id);
							cout << "How many Lectures Attendance do you want to Mark" << endl;
							cin >> size;
							cout << "Enter the Course ID of which You want to mark Attendance" << endl;
							cin >> course_code;
							r.Mark_Attendance(id, course_code, size);
							x = TeacherMenu();
							break;
						case 5:
							cout << "Enter your ID..." << endl;
							cin.ignore();
							getline(cin, id);
							cout << "Enter the Course ID of which You want to mark Grades" << endl;
							cin >> course_code;
							r.AssignGrades(id, course_code);
							x = TeacherMenu();
							break;
						default:
							cout << "Invalid Input!  Input Again" << endl;
							x = TeacherMenu();
							break;
					}
				}
			}
			else
			{
				cout << "\tThere is no Teacher exist with such PASSWORD" << endl << endl;
				cout << "\tPlease go to Admin Office to Register Yourself" << endl << endl;
				system("pause");
			}
		}
		choice = personChoice();
	}
}
int personChoice()
{
	int  z;
	system("CLS");
	cout << "********LEARNING MANAGEMENT SYSTEM*******" << endl << endl;
	cout << "Press-1 If you are Admin" << endl;
	cout << "Press-2 If you are Student" << endl;
	cout << "Press-3 If you are Teacher" << endl;
	cout << "Press-4 to EXIT" << endl;
	cin >> z;
	
		if (z != 1 && z != 2 && z != 3&&z!=4)
		{
			cout << "Invalid Input!  INPUT AGAIN" << endl;
			cout << "********LEARNING MANAGEMENT SYSTEM*******" << endl << endl;
			cout << "Press-1 If you are Admin" << endl;
			cout << "Press-2 If you are Student" << endl;
			cout << "Press-3 If you are Teacher" << endl;
			cin >> z;
		}
	
	return z;
}

int AdminMenu()
{
	int y;
	cout << "Press 1 to Register Student" << endl; 
	cout << "Press 2 to Register Faculty" << endl;
	cout << "Press 3 to Register Course" << endl;
	cout << "Press 4 to Update Student" << endl;
	cout << "Press 5 to Update Faculty" << endl;
	cout << "Press 6 to Update Course" << endl;
	cout << "Press 7 to Delete Student" << endl;
	cout << "Press 8 to Delete Faculty" << endl;
	cout << "Press 9 to Delete Course" << endl;
	cout << "Press 10 to Assign Course to Faculty" << endl;
	cout << "Press 11 to Search Student" << endl;
	cout << "Press 12 to Search Teacher" << endl;
	cout << "Press 13 to Search Course" << endl;
	cout << "Press 14 to Log Out" << endl;
	cin >> y;
	system("CLS");
	return y;
	
}

int StudentMenu()
{
	int y;
	cout << "Press 1 to Register Course" << endl;
	cout << "Press 2 to Drop Course " << endl;
	cout << "Press 3 to View Your Assesments Marks" << endl;
	cout << "Press 4 to View Your Attendance" << endl;
	cout << "Press 5 to View Your DMC" << endl;
	cout << "Press 6 to View Your Information and Registered Courses" << endl;
	cout << "Press 7 to Log Out" << endl;
	cin >> y;
	system("CLS");
	return y; 
}

int TeacherMenu()
{
	int y;
	cout << "Press 1 to View Student enrolled in your Each Course" << endl;
	cout << "Press 2 to View Your Information and Registered Courses " << endl;
	cout << "Press 3 to Mark Assesments of your Courses" << endl;
	cout << "Press 4 to Mark Attendance of your Courses" << endl;
	cout << "Press 5 to Assign Grade To Students" << endl;
	cout << "Press 6 to Log Out" << endl;
	cin >> y;
	system("CLS");
	return y;
}
