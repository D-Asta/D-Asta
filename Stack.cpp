#include<iostream>
using namespace std;
class Stack
{
	private:
		  enum{max=5
		  };
		 int a[max],s,value,x;
		 int top=-1;

	public:
		         	void push()
 		 
		   {
		   	if( top>max)
		   	    cout<<"Stack is full";
		   	else{
		   	     cout<<"Ener the number:";
		   	     cin>>value;
	            top=top+1;
		   	     a[top]=value;}
			} 
		int pop(){
			if(top==-1)
			   cout<<"Empty:";
			else{
			    cout<<"The popped element:"<<a[top]<<endl;
			     top--;
			   }
		}
		void peek()
		   {
		   	 cout<<"Enter the element you want search :";
		   	 cin>>s;
		   	 for(int i=0;i<top;i++)
		   	    {
				   if(s==a[i])
		   	          cout<<"The element is found: ";
		   	       else
		   	           cout<<"THe element is not found:";
		    	}
		   }
		void show()
		     { 
		        if(top==-1)
			      cout<<"Empty:";
		    	else{
				
                   cout<<"The element present in the stack:";
                   for( int i=0;i<=top;i++)
                    cout<<a[i]<<endl;}
   }         
   
};
  int main()
    {
    	int n;
    	Stack l;
    	char c=0;
    	while(c!=5)
		  {
		    cout<<"\n1.push\n2.pop\n3.peek\n4.Show\n5.Exit\n";
		    cin>>c;
		    
		       switch(c)
		         {
		  	        case 1:l.push();break;
		                case 2:l.pop();break;
		  	        case 3:l.peek();break;
		          	case 4:l.show();break;
                                case 5:cout<<"Exiting..";break;
		  	
			     }

		   } 	
	}
  
