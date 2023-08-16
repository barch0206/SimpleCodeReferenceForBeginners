//template

#include <iostream>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

template<typename T>
T add(T a,T b){
    return a+b;
}


int main() {
    int x=add(2,3);
    float f=add(2.1,3.2);
    cout<<x<<" "<<f<<endl;
    
return 0;
}


//abstraction using override


#include <iostream>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

class Job{
    public:
    virtual void getjob()=0;
};

class Bigjob : public Job{
  public:
  void getjob() override{
      cout<<"got job";
  }
};

int main() {
    Bigjob bj;
    bj.getjob();
    
return 0;
}

//creating class


#include <iostream>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

class Node{
    private:
    Node *left,*right;
    int val;
    public:
    Node(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
  
  Node(){
      val=0;
      left=NULL;
      right=NULL;
  }  
  
  int getval() const{
      return val;
  }
};

int main() {
    Node *root=new Node(5);
    cout<<root->getval();
return 0;
}



//function overloading- compile time polymorphism


#include <iostream>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
class Calculs{
    public:
    int add(int a,int b){return a+b;}
    double add(double a,double b){return a+b;}
};

int main() {
    Calculs cal;
    int res1=cal.add(2,3);
    double res2=cal.add(1.3,7.1);
    cout<<res1<<" "<<res2<<endl;
    
return 0;
}


//function overriding - run time polymorphism


#include <iostream>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
class Normal{
    public:
    virtual void getjob(){
        cout<<"normal shitty job";
    }
};

class Bigboys: public Normal{
    public:
    void getjob(){
        cout<<"get good job";
    }
};

int main() {
    Bigboys sankalp;
    sankalp.getjob();
    
return 0;
}

//simple exception handling

#include <iostream>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    try{
        if(b==0)throw runtime_error("divide by 0");  
        cout<<a/b;
    }
    catch(const exception& runtime_error){
        cout<<runtime_error.what()<<endl;
    }
    catch(...){
        cout<<"smthing wrong.error/.asbhdjkre sjj  ./exit case !(!!28110!***!*)";
    }
return 0;
}

