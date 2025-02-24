#include <iostream>
using namespace std;

class EMP {
public:
    string name;
    int id;
    double salary;
    EMP* left;
    EMP* right;

    EMP(string n, int i, double s) {
        name = n;
        id = i;
        salary = s;
        left = NULL;
        right = NULL;
    }
}*next1;

EMP* root = NULL;

void insert(EMP*& root, EMP* next) {
    if (root == NULL) {
        root = next; 
        return;
    }

    if (next->id < root->id) {
        insert(root->left, next);
    } else {
        insert(root->right, next);
    }
}

void create() {
    string n1;
    int i1, c;
    double s1;

    do {
        cout << "Enter the name, id, salary of emp: ";
        cin >> n1 >> i1 >> s1;

        EMP* next = new EMP(n1, i1, s1);
        insert(root, next);  // Ensure `root` is updated correctly

        cout << "\nWant to insert more? (0 to stop): ";
        cin >> c;
    } while (c != 0);
}



EMP* search1(EMP* root,int key)
{
    if(root==NULL)return NULL;
    if(root->id==key)
    {
        return root;
    }
    else if(root->id>key)
    {
        search1(root->left,key);
    }
    else if(root->id<key){
        search1(root->right,key);
    }
    else{
        return NULL;
    }

}


void update(EMP* root,int key)
{
    int i1;
    string n1;
    double s1;
    if(root==NULL) return;
if(search1(root,key))
{
    cout << "Enter the name, id, salary of emp: ";
        cin >> n1 >> i1 >> s1;
        root->name=n1;
        root->id=i1;
        root->salary=s1;
        cout<<"\nRecoed Updated!";

}
}


void display(EMP* root) {
    if (root == NULL) return;

    display(root->left);
    cout << "Name: " << root->name << "\nID: " << root->id << " \nSalary: " << root->salary << endl;
    display(root->right);
}





void maxsal(EMP* root)
{
   if(root==NULL) return;


    while (root->right!=NULL) 
    { 
        root=root->right;
    }
    cout << "Employee with Minimum Salary:\n";
    cout << "Name: " << root->name<< " ID: " << root->id<< " Salary: "<< root->salary << endl;

   
}




void minsal(EMP* root)
{
   if(root==NULL) return;

    while (root->left!=NULL) 
    { 
        root=root->left;
    }
    cout << "Employee with Minimum Salary:\n";
    cout << "Name: " << root->name<< " ID: " << root->id<< " Salary: "<< root->salary << endl; 
}


void avgsal(EMP* root)
{
if(root==NULL) return;

double total=0;
int cnt=0,top=-1;
EMP* stack[100];


while(root!=NULL||top!=-1)
{
    while(root!=NULL)
    {
        stack[++top]=root;
        root=root->left;
    }

    root=stack[top--];
    total+=root->salary;
    cnt++;

    root=root->right;
}
cout<<"AverageSalary: "<<(total/cnt)<< endl;
}


int countNodes(EMP* root) {
    if (root == NULL) 
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    int ch,val;

    do {
        cout<<"\n1. Create\n2. Search\n3. Update\n4. Display\n5. Minimum salary\n6. Maximum salary\n7. Find Average Salary\n8. Total number of employees\n9. exit\n Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                create();
                break;

            case 2:
            cout<<"Enter the id that you want to search: ";
            cin>>val;
            next1 = search1(root, val);
            display(next1);
            break;

            case 3:
            cout<<"Enter the id that you want to search: ";
            cin>>val;
            update(root, val);
                break;

                case 4:
                cout << "Displaying Employees:\n";
                display(root);
                break;
            
                case 5:
                minsal(root);
                break;
            
                case 6:
                maxsal(root);
                break;
            
                case 7:
                avgsal(root);
                break;
            
                case 8:
                cout<<countNodes(root)<<" number of emp are there";
                break;
            
                case 9:
                cout<<"\nExiting from the code!";
                break;
            
                 default:
                 cout<<"\nInvalid case!";
            
               }
                }while(ch!=9);
                return 0;
        }

