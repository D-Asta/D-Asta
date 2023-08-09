#include<iostream>
using namespace std;
class Stack
{
	private:
		  enum{max=5
		  };
		 int a[max],s,value,x;
		 int front=-1,rear=-1;

	public:
		void enqueue()
 		 
		   {
		   	if(front>max)
		   	    cout<<"Queue is full";
		   	else{
		   	     cout<<"Ener the number:";
		   	     cin>>value;
	             rear=rear+1;
	             front=front+1;
		   	     a[rear]=value;}
			} 
		int dequeue(){
			if(rear==-1)
			   cout<<"Empty:";
			else{
			    cout<<"The popped element:"<<a[front]<<endl;
			     front--;
			   }
		}
			void peek()
		   {
		   	 cout<<"Enter the element you want search :";
		   	 cin>>s;
		   	 for(int i=rear;i<=front;i++)
		   	    {
				   if(s==a[i])
		   	          cout<<"The element is found: ";
		   	       else
		   	           cout<<"THe element is not found:";
		    	}
		   }
		void show()
		     { 
		        if(front==-1 && rear==-1)			     
				  cout<<"Empty:";
		    	else{
				       cout<<"The number of person in the quee is :";
                      for( int i=front;i<=rear;i++)
                           cout<<a[i]<<endl;}
   }         
   
};
  int main()
    {
    	int n;
    	Stack l;
    	char c;
    	do
		  { 
		    cout<<"\n1.Insert element\n2.Delete\n3.peek\n4.Show\n5.Exit\n";
		    cin>>n;
		       switch(n)
		         {
		  	        case 1:l.enqueue();break;
		            case 2:l.dequeue();break;
		  	        case 3:l.peek();break;
		          	case 4:l.show();break;
		  	        default: cout<<"Invalid:";
		  	
			     }
			cout<<"You want to continue press yes means 'y' no means 'n':";
     		cin>>c;  

		   } while(c=='y');	
	}
  
