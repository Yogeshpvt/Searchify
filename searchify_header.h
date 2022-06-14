#include<iostream>
#include<time.h>
#include<string.h>
using namespace std;
int flag=1;
int flag_s=1;
int flag_p=1;
int minf=0,maxf=0;


//CREATING KEY USING TIME
string create_key()
{
    time_t now = time(0);
    string dt = ctime(&now);
    string key="";
    
     for(int i=11;i<19;i++)
	    key+=dt[i];
	
	return key;
}


class search_engine 
{
     struct node
     {
          string key;
          node *left;
          node *right;
          string search;
          int freq;
          int count;
          node( string x,node *l,node *r,string s ):left(l),right(r)
          { 
               key=x;
               search=s;
               freq=0;
               count=0;
          }
          node():left(NULL),right(NULL)
          { 
               key="";
               search="";
               freq=0;
               count=0;
          }
     };

     node *root;
     node *nullnode;

     void singlerotatewithleft(node *&k2)
     {
          node *k1=k2->left;
          k2->left=k1->right;
          k1->right=k2;
          k2=k1;
     }
     void singlerotatewithright(node *&k2)
     {
          node *k1=k2->right;
          k2->right=k1->left;
          k1->left=k2;
          k2=k1;
     }

     void max_freq(node* &t)
     {
          if(t!=nullnode)
          {
               if(maxf<=t->freq)
               {
                    maxf=t->freq;
               }
               max_freq(t->left);
               max_freq(t->right);
          }
     }

     void min_freq(node* &t)
     {

          if(t!=nullnode)
          {
               if(minf>=t->freq)
               {
                    minf=t->freq;
               }
               min_freq(t->left);
               min_freq(t->right);
          }
     }

     void print_max(node* &t)
     {
          if(t!=nullnode)
          {    
               if(maxf==t->freq)       
                    cout<<"\n\t"<<t->search<<" :: "<<t->key<<" searched  "<<t->freq<<" times."<<endl;
               print_max(t->left);
               print_max(t->right);
          }     
     }
    void print_min(node* &t)
     {
          if(t!=nullnode)
          {    

               if(minf==t->freq)
                    cout<<"\n\t"<<t->search<<" :: "<<t->key<<" searched  "<<t->freq<<" times.";
               print_min(t->left);
               print_min(t->right);
          }     
     }

     void find_key( string &s,node *&t)
     {  
          if(t!=nullnode)
          {
               if(t->count!=1)
               {
                    if(search_sub(s,t->search))
                    {
                         remove(t->key);
                         flag=0;
                         t->count=1;            
                    }
               }
               
               find_key(s,t->left);
               find_key(s,t->right);
               t->count=0;
          }   
     }

     void search_(string &s,node* &t)
     {
          

          if(t!=nullnode)
          {
               if(t->count!=1)
               {

               
                    if(search_sub(s,t->search))
                    {
                         t->freq++;
                         cout<<"\t\t"<<t->search<<" :: "<<t->key<<endl;
                         flag_s=0;
                         t->count=1;                    
                    }
               }
               search_(s,t->left);
               search_(s,t->right);
               t->count=0;
               
          }

     }


     void print(node *&t)
     {
          if(t!=nullnode)
          {           
               cout<<"\t\t"<<t->search<<" :: "<<t->key<<endl;
               print(t->left);
               print(t->right);
          }
          else
          {
               return;
          }


     }



     //CHECKING PRESENCE OF SUB-STRING

     bool search_sub(string &s,string &t)
     {
          int flag_sub=0;
          for(int i=0;;i+=s.length())
          {
               i=t.find(s,i);
               if(i==string::npos)
               {
                    break;
               }
               flag_sub=1;
               return true;
               
          }
          if(flag_sub==0)
          {
               return false;
          }
          return false;
     }



     bool checking(string &c,string &d)
     {
         if(c[0]==d[0]&&c[1]==d[1]&&c[2]==d[2])
         return true;
         else
         return false;
     }

     void partialcheck(string &c,node *&t)
     { 
          if(t!=nullnode)
          {
               if(t->count!=1)
               {
                    if(checking(c,t->search))
                    {
                         cout<<t->search<<"  ::  "<<t->key<<endl;
                         flag_p=0;
                    }
               
                   
               }
               partialcheck(c,t->left);
               partialcheck(c,t->right);
               t->count=0;
               
          }
     }

     void makeempty(node *&t)
     {
          if(t!=nullnode)
          {
               makeempty(t->left);
               makeempty(t->right);
               delete t;
          } 
          t=nullnode;
     }

     void clear(node *&t)
     {
          if(t!=nullnode)
          {
               remove(t->key);
               clear(t->left);
               clear(t->right);
          } 
          t=nullnode;
     }
 public:
     search_engine()
     {
          nullnode=new node("",NULL,NULL,"");
          nullnode->left=nullnode->right=nullnode;
          root=nullnode;
     }
             
     

     void make_empty()
     {
          makeempty(root);
          delete nullnode;
     }
     
     void splayt(string &k,node *&t)
     {
          node *ltmax,*rtmin;
          static node header("",NULL,NULL,"");
          header.left=header.right=nullnode;
          ltmax=rtmin=&header;
          nullnode->key=k;
          for(;;)
               if(k.compare(t->key) < 0)
               {
                    if(k.compare(t->left->key) < 0)
                    singlerotatewithleft(t);
                    if(t->left==nullnode)
                         break;
                    rtmin->left=t;
                    rtmin=t;
                    t=t->left;
               }
               else if(k.compare(t->key) > 0)
               {
                    if(k.compare(t->right->key) > 0)
                         singlerotatewithright(t);
                    if(t->right==nullnode)
                         break;
                    ltmax->right=t;
                    ltmax=t;
                    t=t->right;
               }
               else
                    break;
          ltmax->right=t->left;
          rtmin->left=t->right;
          t->left=header.right;
          t->right=header.left;
     }
      

     //INSERTION
     void insert(string &k, string &s)
     {
          static node *newnode=NULL;
          if(newnode==NULL)
          {
               newnode=new node("",NULL,NULL,"");
          }
          newnode->key=k;
          newnode->search=s;           
          if(root==nullnode)
          {
               newnode->left=newnode->right=nullnode;
               root=newnode;
          }
          else
          {
               splayt(k,root);
               if(k.compare(root->key) < 0)
               {
                    newnode->left=root->left;
                    newnode->right=root;
                    root->left=nullnode;
                    root=newnode;
               }
               else if(k.compare(root->key) > 0)
               {
                    newnode->left=root;                             
                    newnode->right=root->right;
                    root->right=nullnode;
                    root=newnode;
               }                            
               else
                    return;
          }
          newnode=NULL;
     }

     // SEARCHING KEY FOR DELETION
    

     void find_key(string &s)
     {
          find_key(s,root);
     }


     //DELETION
     void remove(string &x)
     {
          node *newtree;
          if(root==nullnode)
               return;
          splayt(x,root);
          if(x.compare(root->key) != 0)  //not present
               return;
          if(root->left==nullnode)
               newtree=root->right;
          else
          {
               newtree=root->left;
               splayt(x,newtree);
               newtree->right=root->right;
          }
          delete root;
          root=newtree;
     }
    
      
     //SEARCHING ENTRIES 

     void search_(string &s)
     {
          search_(s,root);
     }

     
     //DISPLAY

     void display()
     {
          time_t now = time(0);
          string dt1 = ctime(&now);
          cout<<"\n\t\t-----Search History-----"<<endl;
          cout<<"\t\t";
          for(int i=0;i<11;i++)
	          cout<<dt1[i];
          cout<<"\n\n";
          print(root);
     }


     //FREQUENCIES OF ENTRIES

     void freq()
     {
          maxf=minf=root->freq;
          max_freq(root);
          min_freq(root);
     }


     
     void print_max_min()
     {   
          cout<<"\n\n\t\tThe most frequently browsed searches: ";
          print_max(root);
          cout<<"\n\n\t\tThe least frequently browsed searches: ";
          print_min(root);
     }
     



     // RECENTLY ACCESSED ENTRIES     

     void most_recently_searched()
     {
          cout<<"\n "<<root->search<<"==>"<<root->key;
     }


     //SUGGESTIONS
     void partialchecking(string &s)
     {
         partialcheck(s,root);
     }
     
     

     //EMPTY THE HISTORY
     void clear()
     {
          clear(root);
     }
};

