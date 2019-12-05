#include <iostream>
#include<string>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include<fstream>
using namespace std;
#include "customdate.h"

template <typename Node, typename object>
class ListOfObjPtr {
private:
	Node* head;
public:
	ListOfObjPtr();
	ListOfObjPtr(ListOfObjPtr& obj);
	Node* getHead();
	void insertHead(object* insert);
	void setHead(Node* newhead);
	void deleteHead();

	object* getById(string id);
	void reverse();
	void print();
	~ListOfObjPtr();


};


template <typename Node,typename object>
class ListOfObj {
private:
	Node* head;
public:
	ListOfObj();
	ListOfObj(ListOfObj& obj);
	Node* getHead();
	void insertHead(object* insert); 
	void setHead(Node* newhead);
	void deleteHead();
	void reverse();
	object* getById(string id);
		
	void print();
	~ListOfObj();

};

class user;
class Post;
class page;
class List;
/////////////////////////
struct comment
{
	string text;    //Our data at an index. We can have any data type here, we are using int
	string id;
	string user_id;
	string post_id;
	string name;


	comment* next;        //The next pointer to point to the next index of the list.

	comment() {
		next = NULL;
	}
	comment(string txt, string i, string na, string uid, string pid) {
		text = txt;
		id=i;
		 name=na;
		 user_id=uid;
		 post_id=pid;

	}
	void setName(string n) {
		name = n;
	}


	void print()
	{
		cout << "\t\t";
		cout << name <<" wrote:\""<<text<<"\""<< endl;
	}
};
class list_of_comments
{

private:
	comment* head;
public:
	list_of_comments() {    //set the head pointer to null
		head = NULL;
	}
	comment* getHead() {
		return head;
	}

	list_of_comments(list_of_comments& obj) {
		comment* temp = obj.getHead();
		while (temp != NULL) {
			insertHead(*temp);
			

			temp = temp->next;
		}
	}

	void insertHead(comment insert) {
		comment* temp = new comment;
		temp->text = insert.text;
		temp->id = insert.id;
		temp->name = insert.name;
		temp->user_id = insert.user_id;
		temp->post_id = insert.post_id;
		temp->next = head;
		head = temp;
	}
	void setHead(comment* newhead) {
		head = newhead;
	}
	comment getById(string c) {
		comment* temp = head;
		while (temp != NULL) {

			if (temp->id == c) {
				return *temp;
			}

			temp = temp->next;
		}
	}
	void deleteHead() {
		if (head == NULL) {
			return;
		}

		comment* dlt = head;
		head = head->next;
		delete dlt;
	}
	void reverse()
	{
		// Initialize current, previous and 
		// next pointers 
		comment* current = head;
		comment* prev = NULL, * next = NULL;

		while (current != NULL) {
			// Store next 
			next = current->next;

			// Reverse current node's pointer 
			current->next = prev;

			// Move pointers one position ahead. 
			prev = current;
			current = next;
		}
		head = prev;
	}
	void print() {
		reverse();

		comment* temp = head;
		while (temp != NULL) {

			temp->print();

			temp = temp->next;
		}
		cout << endl;
		reverse();
	}

	void deleteAll() {
		if (head == NULL)
			return;
		comment* curr = head;
		comment* prev = NULL;
		while (curr != NULL) {
			prev = curr;
			curr = curr->next;
			delete prev;
		}
		head = NULL;
	}

	~list_of_comments() {            //Destructor that deletes every element in the list and then removes head also
		if (head == NULL)
			return;
		comment* curr = head;
		comment* prev = NULL;
		while (curr != NULL) {
			prev = curr;
			curr = curr->next;
			delete prev;
		}
		head = NULL;
	}

};

////////////////////////
struct Activity {
	int type;
	string value;
	string type_choices[4] = { "feeling","thinking about","Making","celebrating" };

	string type_description;
	Activity() {
		type = -1;
		value = "";
		type_description = "";


	}

	string getStrActivity() {
		string tmp = type_description + " " + value;
		return tmp;
	}

	void printActivity() {
		cout << type_description << " " << value;
	}

	void setActivity(int t, string v) {
		value = v;
		type = t;
		type_description = type_choices[t];
	}


};
struct userptrNode {
	user* ptr;
	userptrNode* next;
};
class List
{
private:
	struct Node
	{
		string id;
		string name;
		Node* next = NULL;		//The next pointer to point to the next index of the list.
	};

	Node* head;
public:
	List() {	//set the head pointer to null
		head = NULL;
	}
	Node* getHead() {
		return head;
	}

	List(List& obj) {
		Node* tmp = obj.getHead();
		while (tmp != NULL) {
			insertHead(tmp->id, tmp->name);
			tmp = tmp->next;
		}
	}

	void insertHead(string i, string nm) {
		Node* temp = new Node;

		temp->id = i;
		temp->name = nm;

		temp->next = head;
		head = temp;
	}
	void setHead(Node* tmp) {
		head = tmp;
	}
	void deleteAll() {
		if (head == NULL)
			return;
		Node* curr = head;
		Node* prev = NULL;
		while (curr != NULL) {
			prev = curr;
			curr = curr->next;
			delete prev;
		}
		head = NULL;
	}

	void deleteHead() {
		if (head == NULL) {
			return;
		}

		Node* dlt = head;
		head = head->next;
		delete dlt;
	}



	List(string txt, string i, string nm) { //initialize head node and set it equal to d
		head = new Node;
		head->id = i;
		head->name = nm;

		head->next = NULL;
	}

	void print() {
		Node* tmp = head;
		while (tmp != NULL) {
			cout << tmp->id << " - " << tmp->name << endl;
			tmp = tmp->next;
		}
	}
	~List() {			//Destructor that deletes every element in the list and then removes head also
		if (head == NULL)
		return;
		Node* curr = head;
		Node* prev = NULL;
		while (curr != NULL) {
			prev = curr;
			curr = curr->next;
			delete prev;
		}
		head = NULL;
	}
};
class Post {
private:


	string id;
	string byName;
	string content;
	int numberOfLikes;
	List peopleWhoLiked;
	Date date;
	int numberOfComments;
	list_of_comments comments;
public:
	Activity activity;

	Post() {
		id = "";
		content = "";
		numberOfLikes = 0;
		numberOfComments = 0;
	}
	Post(string i,string by,Date d, string text, Activity a) {
		id = i;
		byName = by;
		content = text;
		date = d;
		activity = a;
	}

	int getNumberOfComments() {
		return numberOfComments;
	}

	string getId() {
		return id;
	}
	void setByName(string by) {
		byName = by;
	}
	string getContent() {
		return content;
	}
	/*string getStrPost() {
		string tmp = byName;

		if (activity.value != "") {
			tmp = tmp + " is " + activity.getStrActivity();
		}
		tmp = tmp + '\n';
		tmp = tmp + "\t\"" + content + "\"";
		cout << endl;
		comments.print();
	}*/
	int getNumberOfLikes() {
		return numberOfLikes;
	}
	void setActivity(int t, string s) {
		activity.setActivity(t, s);
	}
	string getByName() {
		return byName;
	}
	string getActivity() {
		return activity.getStrActivity();
	}
	void setId(string i) {
		id = i;
	}
	void setContent(string c) {
		content = c;
	}
	void addLike(string id, string name) {
		peopleWhoLiked.insertHead(id, name);
		numberOfLikes++;
	}
	void viewLikes() {
		peopleWhoLiked.print();
	}
	void deleteLikes() {
		peopleWhoLiked.deleteAll();
	}
	void addComment(comment c) {
		comments.insertHead(c);
		numberOfComments++;
	}

	Date getDate() {
		return date;
	}

	void deleteComments() {
		comments.deleteAll();
	}
	void view() {
		cout << byName ;
		if (activity.value != ""){
			cout << " is ";
		}

		activity.printActivity();
		cout << endl;
		cout << "\t\"" << content << "\"";
		cout << endl;
		comments.print();

	}
	

};
struct postptrNode
{
	Post* ptr;
	postptrNode* next = NULL;

};
class page
{

	string  title;
	string id;
	ListOfObjPtr<postptrNode,Post> list;
public:

	page()
	{
		title = "";
		id = "";
	}

	page(string i, string s)
	{
		title = s;
		id = i;

	}

	void set_title(string s)
	{
		title = s;
	}
	void set_id(string i)
	{
		id = i;
	}
	string getId()
	{
		return id;

	}
	string  get_title()
	{
		return title;

	}
	void printPosts() {
		list.print();

	}

	void addpost(Post *input)
	{
		list.insertHead(input);
	}

	void viewPage() {
		cout << title << endl;
		list.print();
	}

	postptrNode* getPostListHead() {
		return list.getHead();
	}

	void view()
	{
		cout  << id << " - " << title << endl;
		//list.print();

	}


};
struct pageptrNode {
	page* ptr;
	pageptrNode* next;
};
class user
{
private:
	string userID;
	string first_name;
	string last_name;
	//objects to be added after inclusion of classes ListOfFriends & ListOfPages
	ListOfObjPtr<userptrNode, user> LOF;
	//ListOfPtrPeople LOF;
	ListOfObjPtr<postptrNode, Post> LOP;
	ListOfObj<postptrNode, Post> sharedPosts;
	ListOfObjPtr<pageptrNode,page> pageList;;


public:

	//print function will be changed according to file reading afterwards. This is just a tentative function atm
	user()
	{
		userID = "";
		first_name = "";
		last_name = "";

	}
	user(string uIDs, string fn, string ln)
	{
		userID = uIDs;
		first_name = fn;
		last_name = ln;
		//here the parametrized constructors for the LOP and LOF objects can be called
	}
	void setuserID(string ID)
	{
		userID = ID;
	}
	void setfirstname(string fname)
	{
		first_name = fname;
	}
	userptrNode* getFriendListHead() {
		return LOF.getHead();
	}
	postptrNode* getPostListHead() {
		return LOP.getHead();
	}
	pageptrNode* getPageListHead() {
		return pageList.getHead();
	}
	void setlastname(string lname)
	{
		last_name = lname;
	}
	string getId(void)
	{
		return userID;
	}
	string getfirstname(void)
	{
		return first_name;
	}
	string getlastname(void)
	{
		return last_name;
	}
	void addFriend(user* fr) {
		LOF.insertHead(fr);
	}
	void addPost(Post* p) {
		LOP.insertHead(p);
	}
	void addPage(page* p) {
		pageList.insertHead(p);
	}
	void printFriendList() {
		LOF.print();
	}

	void sharePost(Post *p) {
		sharedPosts.insertHead(p);
		Post* p1 = sharedPosts.getById(p->getId());
		p1->deleteComments();
		p1->deleteLikes();
		string name = first_name + " " + last_name;
		string tmp ;
		tmp = p1->getByName() + " is " + p1->getActivity();
		p1->setContent(tmp);
		p1->setByName(name);
		p1->setActivity(-1, "");
		
	}

	void printPageList() {
		pageList.print();
	}
	void printPosts() {
		LOP.print();
		sharedPosts.print();
	}
	void view() {
		cout << userID << " - " << first_name << " " << last_name << endl;
	}
	//void print()
	//{
	////	cout << left << setw(9) << userID << "\t" << left << setw(11) << first_name << "\t" << left << setw(10) << last_name << "\n";
	//}
};


template <typename Node, typename object>
ListOfObj<Node, object>::ListOfObj() {
	head = NULL;
}
template <typename Node, typename object>
ListOfObj<Node,object>::ListOfObj(ListOfObj& obj) {
	Node* tmp = obj.head;
	while (tmp != NULL) {
		insertHead(tmp->ptr);
		tmp = tmp->next;
	}
}
template <typename Node, typename object>
Node* ListOfObj<Node, object>::getHead() {
	return head;
}
template <typename Node, typename object>
void ListOfObj<Node, object>::insertHead(object* insert) {
	Node* temp = new Node;
	temp->ptr = new object(*insert);
	//temp->post = insert;
	temp->next = head;
	head = temp;
}
template <typename Node, typename object>
void ListOfObj<Node, object>::setHead(Node* newhead) {
	head = newhead;
}
template <typename Node, typename object>
void ListOfObj<Node, object>::deleteHead() {
	if (head == NULL) {
		return;
	}

	Node* dlt = head;
	head = head->next;
	delete dlt;
}
template <typename Node, typename object>
object* ListOfObj<Node, object>::getById(string id) {
	Node* temp = head;
	while (temp != NULL) {
		if (temp->ptr->getId() == id) {
			return temp->ptr;
		}
		temp = temp->next;
	}
	EXIT_FAILURE;
}
template <typename Node, typename object>
void ListOfObj<Node, object>::reverse() {
	// Initialize current, previous and 
		// next pointers 
	Node* current = head;
	Node* prev = NULL, * next = NULL;

	while (current != NULL) {
		// Store next 
		next = current->next;

		// Reverse current node's pointer 
		current->next = prev;

		// Move pointers one position ahead. 
		prev = current;
		current = next;
	}
	head = prev;
}
template <typename Node, typename object>
void ListOfObj<Node, object>::print() {
	reverse();
	Node* temp = head;
	while (temp != NULL) {
		temp->ptr->view();

		temp = temp->next;
	}
	cout << endl;
	reverse();
}
template <typename Node, typename object>
ListOfObj<Node, object>:: ~ListOfObj() {            //Destructor that deletes every element in the list and then removes head also
	if (head == NULL)
		return;
	Node* curr = head;
	Node* prev = NULL;
	while (curr != NULL) {
		prev = curr;
		curr = curr->next;
		delete prev->ptr;
		delete prev;
	}
	head = NULL;
}

/////List of Obj Pointer defnination

template <typename Node, typename object>
ListOfObjPtr<Node, object>::ListOfObjPtr() {
	head = NULL;
}
template <typename Node, typename object>
ListOfObjPtr<Node, object>::ListOfObjPtr(ListOfObjPtr& obj) {
	Node* tmp = obj.head;
	while (tmp != NULL) {
		insertHead(tmp->ptr);
		tmp = tmp->next;
	}
}
template <typename Node, typename object>
Node* ListOfObjPtr<Node, object>::getHead() {
	return head;
}
template <typename Node, typename object>
void ListOfObjPtr<Node, object>::insertHead(object* insert) {
	Node* temp = new Node;
	temp->ptr = insert;
	//temp->post = insert;
	temp->next = head;
	head = temp;
}
template <typename Node, typename object>
void ListOfObjPtr<Node, object>::setHead(Node* newhead) {
	head = newhead;
}
template <typename Node, typename object>
void ListOfObjPtr<Node, object>::deleteHead() {
	if (head == NULL) {
		return;
	}

	Node* dlt = head;
	head = head->next;
	delete dlt;
}
template <typename Node, typename object>
object* ListOfObjPtr<Node, object>::getById(string id) {
	Node* temp = head;
	while (temp != NULL) {
		if (temp->ptr->getId() == id) {
			return temp->ptr;
		}
		temp = temp->next;
	}
	EXIT_FAILURE;
}
template <typename Node, typename object>
void ListOfObjPtr<Node, object>::reverse() {
	// Initialize current, previous and 
		// next pointers 
	Node* current = head;
	Node* prev = NULL, * next = NULL;

	while (current != NULL) {
		// Store next 
		next = current->next;

		// Reverse current node's pointer 
		current->next = prev;

		// Move pointers one position ahead. 
		prev = current;
		current = next;
	}
	head = prev;
}
template <typename Node, typename object>
void ListOfObjPtr<Node, object>::print() {
	reverse();
	Node* temp = head;
	while (temp != NULL) {
		temp->ptr->view();

		temp = temp->next;
	}
	cout << endl;
	reverse();
}
template <typename Node, typename object>
ListOfObjPtr<Node, object>:: ~ListOfObjPtr() {            //Destructor that deletes every element in the list and then removes head also
	if (head == NULL)
		return;
	Node* curr = head;
	Node* prev = NULL;
	while (curr != NULL) {
		prev = curr;
		curr = curr->next;
		delete prev;
	}
	head = NULL;
}















/*
Required Functionality:
1- Set Current User (5 marks)
a. Ask user about his ID and set him as current user of application. Now everything that we see in the system will be view of this user.
2- View Home of Current User (10 marks)
a. Display posts of all his friends shared in last 24 hours.
b. Display posts of all his liked pages shared in last 24 hours.
3- Like a post (10 marks)
a. Ask user about ID of post and like it. A post can be liked by 10 users at max.
4- View the list of People who liked a post (10 marks)
a. Take Post ID from user and display list of people who have liked it
5- Comment on a Post (10 marks)
a. Take post ID and comment from the user and add this comment in the post
6- View a Post (10 marks)
a. Take post ID and Display the post with its Comments
7- Share a Post (10 marks)
a. Take post ID from user and share it on current user’s timeline
8- View User’s Timeline (10 marks)
a. Display User Name
b. Display user’s posts in his timeline
9- View Friend List (10 marks)
a. Take ID of a user and display his friends list
10- View Page (10 marks)
a. Take Page ID and display all its posts
11- Search (15 marks)
a. Take a keyword from user and display all the People, Pages and Posts having this keyword in their name, title or description respectively.
*/

class SocialMediaApp {

private:

	ListOfObj<userptrNode, user> allUsers;
	ListOfObj<pageptrNode,page> allPages;
	ListOfObj<postptrNode, Post> allPosts;
	user* currentUser;
	Date systemDate;

public:

	SocialMediaApp() {
		ifstream fin;
		fin.open("Project-2-Users.txt");
		string userIn;
		string tmp = "";
		char curr;
		user* tmpUser;
		string first, last, uid;
		//getline(fin, userIn);
		int count = 0;
		//loop initializes all the users
		while (!fin.eof()) {
			getline(fin, userIn);
			for (int i = 0; i < userIn.length(); i++) {
				curr = userIn[i];
				if (userIn[i] != ' ' && userIn[i] != '\t') {
					tmp = tmp + curr;
				}
				if ((curr == ' ' || curr == '\t' || i == userIn.length() - 1) && tmp != "") {
					count++;
					if (count == 1) {
						uid = tmp;

					}
					if (count == 2) {
						first = tmp;
					}
					if (count == 3) {
						last = tmp;
						tmpUser = new user(uid, first, last);
						allUsers.insertHead(tmpUser);
						tmp = "";
						delete tmpUser;
						count = 0;
						break;
					}
					tmp = "";
				}

			}
		}
		fin.clear();
		fin.seekg(0);
		user tempUser2, userFriend;
		count = 0;
		int pageFlag=0;
		page* tmpPage;
		tmp = "";
		userIn = "";
		count = 0;
		uid = "";
		fin.close();
		////////////loading pages///////////////
		fin.open("Project-2-Pages.txt");
		string pageId;
		string title;
		while (!fin.eof()) {
			string t;
			fin >> pageId;
			getline(fin, title);
			for (int i = 0; i < title.length(); i++) {
				if (title[i] != '\t') {
					t = t + title[i];
				}
			}
			tmpPage = new page(pageId, t);
			allPages.insertHead(tmpPage);

			//tmpPage->view();
			delete tmpPage;
		}
		//allPages.print();
		/////////////////////////
		fin.close();
		fin.open("Project-2-Users.txt");
		//adding friends to friend lists
		while (!fin.eof()) {
			getline(fin, userIn);
			//cout << userIn << endl;
			for (int i = 0; i < userIn.length(); i++) {
				curr = userIn[i];
				if (userIn[i] != ' ' && userIn[i] != '\t') {
					tmp = tmp + curr;
				}
				if ((curr == ' ' || curr == '\t' || i == userIn.length() - 1) && tmp != "") {
					count++;
					
					//cout <<"user:" <<tmp<<endl;
					if (count == 1) {
						uid = tmp;
						//cout << uid<<endl;

					}
					if (count > 3 && tmp != "-1") {

						if (tmp[0] == 'p') {
							tmpUser = allUsers.getById(uid);
							tmpUser->addPage(allPages.getById(tmp));
						}
						if(tmp[0] =='u'){
						tmpUser = allUsers.getById(uid);
						tmpUser->addFriend(allUsers.getById(tmp));
						}
					}
					if (tmp == "-1") {
						pageFlag++;
						if(pageFlag == 2){
							tmp = "";
							count = 0;
							break;
						}
					}
					tmp = "";
					//count = 0;
				}

			}
			count = 0;

		}
		//allUsers.print();
		tmpUser = allUsers.getById("u7");
		//tmpUser->printPageList();
		//tmpUser->printFriendList();
		Post* tmpPost;
		string pid;
		Date* dt = NULL;
		string txt;
		Activity *a;
		fin.close();
		fin.open("Project+2-Post-format.txt");
		//load posts
		while (!fin.eof()) {
			tmp = "";
			getline(fin, userIn);
			getline(fin, userIn);
			for (int i = 0; i < userIn.length(); i++) {
				curr = userIn[i];
				//cout << "-----------------\n";
				if (curr == '/') {
					break;
				}
				if (userIn[i] != ' ' && userIn[i] != '\t' && curr != '-') {
					tmp = tmp + curr;
				}
				if ((curr == ' ' || curr == '\t' || curr == '-' || i == userIn.length() - 1) && tmp != "") {
					pid = tmp;
					tmp = "";
					break;
				}
			}
			getline(fin, userIn);
			count = 0;
			int d = 0, m = 0, y = 0;
			for (int i = 0; i < userIn.length(); i++) {
				curr = userIn[i];
				//cout << "-----------------\n";
				if (curr == '/') {
					break;
				}
				if (userIn[i] != ' ' && userIn[i] != '\t' && curr != '-') {
					tmp = tmp + curr;
				}
				if ((curr == ' ' || curr == '\t' || curr == '-' || i == userIn.length() - 1) && tmp != "") {
					count++;
					if (count == 1) {
						d = stoi(tmp);
						tmp = "";
					}
					if (count == 2) {
						m = stoi(tmp);
						tmp = "";
					}
					if (count == 3) {
						y = stoi(tmp);
						tmp = "";
						count = 0;
						break;

					}
					tmp = "";
				}
			}
			getline(fin, userIn);
			txt = userIn;
			string val;
			int tp = -1;
			getline(fin, userIn);
			for (int i = 0; i < userIn.length(); i++) {
				curr = userIn[i];
				//cout << "-----------------\n";
				if (curr == '/') {
					break;
				}
				if (userIn[i] != ' ' && userIn[i] != '\t' && curr != '-') {
					tmp = tmp + curr;
				}
				if ((curr == ' ' || curr == '\t' || curr == '-' || i == userIn.length() - 1) && tmp != "") {
					count++;
					if (count == 1) {
						tp = stoi(tmp);
						tmp = "";
					}
					if (tp == 0) {
						val = "";
						count = 0;
						break;
					}
					if (curr == '/') {
						count = 0;
						break;
					}
					if (count != 1) {
						val = val + " " + tmp;
						tmp = "";
					}

				}
			}
			a = new Activity();
			a->setActivity(tp-1 , val);
		//	a->printActivity();
			string sharedID = "";
			getline(fin, userIn);
			for (int i = 0; i < userIn.length(); i++) {
				curr = userIn[i];
				//cout << "-----------------\n";
				if (curr == '/') {
					break;
				}
				if (userIn[i] != ' ' && userIn[i] != '\t' && curr != '-') {
					tmp = tmp + curr;
				}
				if ((curr == ' ' || curr == '\t' || curr == '-' || i == userIn.length() - 1) && tmp != "") {
					sharedID = tmp;
				}
			}
			//cout << sharedID << endl;

			tmp = "";
			dt = new Date(d, m - 1, y);
			tmpPost = new Post(pid,"", *dt, txt, *a);
			getline(fin, userIn);
			//cout << userIn<<endl;
			for (int i = 0; i < userIn.length(); i++) {

				curr = userIn[i];
				if (curr == '/') {
					break;
				}
				if (userIn[i] != ' ' && userIn[i] != '\t') {
					tmp = tmp + curr;
				}
				if (tmp == "-1") {
					break;
				}
				if ((curr == ' ' || curr == '\t' || i == userIn.length() - 1) && (tmp != "" || tmp != "-1")) {
					string name;
					//cout << tmp << endl;
					if (tmp[0] == 'u') {
						tmpUser = allUsers.getById(tmp);
						name = tmpUser->getfirstname() + " " + tmpUser->getlastname();
						//cout << tmp << " - " << name<<endl;
						tmpPost->addLike(tmp, name);

					}
					if (tmp[0] == 'p') {
						tmpPage = allPages.getById(tmp);
						name = tmpPage->get_title();
						//cout << tmp << " - " << name<<endl;
						tmpPost->addLike(tmp, name);
					}
					tmp = "";
					name = "";

				}
			}
			if(sharedID[0] == 'u'){
			
				tmpUser = allUsers.getById(sharedID);
				tmpPost->setByName(tmpUser->getfirstname()+" "+tmpUser->getlastname());
				allPosts.insertHead(tmpPost);
				Post* post = allPosts.getById(pid);
				tmpUser->addPost(post);
			
			}
			if (sharedID[0] == 'p') {
			
				tmpPage = allPages.getById(sharedID);
				tmpPost->setByName(tmpPage->get_title());
				allPosts.insertHead(tmpPost);
				Post* post = allPosts.getById(pid);
				tmpPage->addpost(post);

			}


			delete dt;
			delete tmpPost;

		}
		fin.close();
		//load comments
		fin.open("project-2-comments.txt");
		comment* c;
		string na;
		string id, p_id, u_id, text;
		while (!fin.eof()) {
			fin >> id;
			fin >> p_id;
			fin >> u_id;
			getline(fin, text);
			string t;
			if(u_id[0] == 'u'){
			tmpUser = allUsers.getById(u_id);
			na = tmpUser->getfirstname() + " " + tmpUser->getlastname();
			}
			if (u_id[0] == 'p') {
				tmpPage = allPages.getById(u_id);
				na = tmpPage->get_title();
			}
			for (int i = 0; i < text.length(); i++) {
				if (text[i] != '\t') {
					t = t + text[i];
				}
			}
			c = new comment(t,id,na,u_id,p_id);
			Post* p = allPosts.getById(c->post_id);
			p->addComment(*c);
			delete c;

		}
		fin.close();
		

	}

	void viewFriendList() {					 //working
		currentUser->printFriendList();
	};


	void viewPost(string id) {               //working
		Post* p = allPosts.getById(id);
		p->view();
	};

	void setCurrentUser(string id) {		//working
		currentUser = allUsers.getById(id);
	};
	
	void likePost(string id) {				 //working
		Post* p = allPosts.getById(id);
		string name = currentUser->getfirstname() + " " + currentUser->getlastname();
		p->addLike(currentUser->getId(), name);
	};

	void peopleWhoLikedPost(string id) {	 //working
		Post* p = allPosts.getById(id);
		p->viewLikes();
	};

	void setSystemDate(Date d) {			//working
		systemDate = d;
		systemDate.print();
	}

	void viewLikedPages() {					//working
		currentUser->printPageList();
	}
	
	void viewTimeline() {					//working
		currentUser->printPosts();
	}; //should be in User class





	void viewPage(string id) {				//working
		page* p = allPages.getById(id);
		p->viewPage();
	};

	void sharePost(string id) {				//working
		Post* p = allPosts.getById(id);
		currentUser->sharePost(p);
	};


	void commentOnPost(string id, string comm) {	//working
		Post* p = allPosts.getById(id);
		string name = currentUser->getfirstname() + " " + currentUser->getlastname();
		comment com(comm, "", name, currentUser->getId(), id);
		p->addComment(com);

	};
///////////////////////////////////////////////////////////////////////////

	
	
	void viewHome() {
		string label = currentUser->getfirstname() + " " + currentUser->getlastname() + " --- Home Page\n\n\n";
		cout << label;
		userptrNode* tmp = currentUser->getFriendListHead();
		Date d1;
		postptrNode *post;
		while (tmp != NULL) {
			post = tmp->ptr->getPostListHead();
			while(post!=NULL){
				d1 = post->ptr->getDate();
				if (d1.month == systemDate.month && d1.year == systemDate.year) {
					if ((systemDate.day - d1.day) <= 1) {
						post->ptr->view();
					}
				}
				post = post->next;
			}
			tmp = tmp->next;
		}



		pageptrNode* tmp1 = currentUser->getPageListHead();
		while (tmp1 != NULL) {
			post = tmp1->ptr->getPostListHead();
			while (post != NULL) {
				d1 = post->ptr->getDate();
				if (d1.month == systemDate.month && d1.year == systemDate.year) {
					if ((systemDate.day - d1.day) <= 1) {
						post->ptr->view();
					}
				}
				post = post->next;
			}
			tmp1 = tmp1->next;
		}
	
	}; //should be in User class

	void search(string key) {
		userptrNode* temp = allUsers.getHead();

		cout << "USERS : \n";

		while (temp != NULL)
		{

			if (temp->ptr->getfirstname() == key)
			{
				temp->ptr->view();
			}

			else if (temp->ptr->getlastname() == key)
			{
				temp->ptr->view();
			}
			temp = temp->next;

		}



		pageptrNode* temp1 = allPages.getHead();


		cout << "PAGES : \n";

		while (temp1 != NULL)
		{
			string s = temp1->ptr->get_title();
			string word;

			int x = s.length();

			for (int i = 0; i < x; i++)
			{
				if (s[i] == ' ')
				{

					if (word == key)
					{
						temp1->ptr->view();
					}
					word = "";


				}
				else
				{
					word = word + s[i];
				}
			}


			temp1 = temp1->next;

		}

		postptrNode* temp2 = allPosts.getHead();

		cout << "POSTS : \n";

		while (temp2 != NULL)
		{

			string text = temp2->ptr->getContent();
			string words;

			int x = text.length();

			for (int i = 0; i < x; i++)
			{
				if (text[i] == ' ')
				{

					if (words == key)
					{
						cout << temp2->ptr->getId()<<" - ";
						temp2->ptr->view();
					}
					words = "";


				}
				else
				{
					words = words + text[i];
				}
			}


			temp2 = temp2->next;

		}
	};

	void run() {

		setCurrentUser("u7");
		cout << "command:\tsetCurrentUser(\"u7\")\n";
		string name = currentUser->getfirstname() + " " + currentUser->getlastname();
		cout << currentUser->getfirstname() + " " +currentUser->getlastname();
		cout << " successfully set as current user\n";
		cout << "\n\n";

		cout << "command:\t set current system date 15 11 2017\n";
		Date d(15,10,2017);

		cout << "System Date: \t";
		setSystemDate(d);
		cout << "\n\n";
		cout << "command:\tview Friend List\n";
		cout << "-----------------------------------------------------------------------------------\n";
		cout << name << " - friend List\n";
		cout << "\n\n";
		viewFriendList();
		cout << "-----------------------------------------------------------------------------------\n";
		cout << "command:\tview liked pages\n";
		cout << "-----------------------------------------------------------------------------------\n";
		cout << name << " - Liked Pages\n";
		cout << "\n\n";
		viewLikedPages();
		cout << "-----------------------------------------------------------------------------------\n";
		cout << "command:\tview home\n";
		cout << "\n\n";
		viewHome();
		cout << "-----------------------------------------------------------------------------------\n";
		cout << "command:\tview timeline\n";
		cout << "\n\n";
		viewTimeline();
		cout << "-----------------------------------------------------------------------------------\n";
		cout << "command:\tviewLikeList(post5)\n";
		cout << "\n\n";
		peopleWhoLikedPost("post5");
		cout << "-----------------------------------------------------------------------------------\n";
		cout << "command:\tLike Post(post5)\n";
		cout << "command:\tviewLikeList(post5)\n";
		cout << "\n\n";
		likePost("post5");
		peopleWhoLikedPost("post5");
		cout << "-----------------------------------------------------------------------------------\n";
		cout << "command:\tpostComment(post4,Good Luck for your result)\n";
		cout << "command:\tviewPost(post4)\n";
		cout << "\n\n";
		commentOnPost("post4", "Good Luck for your result HAHAH");
		viewPost("post4");
		cout << "-----------------------------------------------------------------------------------\n";
		cout << "command:\tpostComment(post8,thanks for the wishes)\n";
		cout << "command:\tviewPost(post8)\n";
		cout << "\n\n";
		commentOnPost("post8", "thanks for the wishes");
		viewPost("post8");
		cout << "-----------------------------------------------------------------------------------\n";
		cout << "command:\tsharePost(post5)\n";
		cout << "command:\tviewTimeline\n";
		cout << "\n\n";
		sharePost("post5");
		viewTimeline();
		cout << "-----------------------------------------------------------------------------------\n";
		cout << "command:\tviewPage(p1)\n";
		cout << "\n\n";
		viewPage("p1");
		cout << "-----------------------------------------------------------------------------------\n";
		cout << "command:\search(Birthday)\n";
		cout << "\n\n";
		search("Birthday");

		cout << "-----------------------------------------------------------------------------------\n";
		cout << "command:\search(Ali)\n";
		cout << "\n\n";
		search("Ali");
	}

};

int main()
{


	SocialMediaApp app;
	
	app.run();
	
	
	return 0;



}

