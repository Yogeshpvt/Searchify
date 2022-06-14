#include "searchify_header.h"
#include<iostream>
#include<iomanip>
#include<time.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

using namespace std;
int main()
{
    search_engine A;
    int opt;
    string val="";
    string key="";
    char c;
    system("Color 5E");
    cout<<"\t\t\t\t\t SEARCHIFY"<<endl;
    cout<<"\n\t SEARCHIFY is a software system that is designed to carry out web searches,\n\t which means to search the World Wide Web in a systematic way for particular information \n\t specified in a textual web search query.";
    cout<<"\n\n\nTHE FOLLOWING SITE HAS ALL SEARCHES MADE TODAY. \nTIME OF SEARCH ALONG WITH THE DATA CAN BE ACCESSED! \n";
    cout<<"\nENTER Y TO BEGIN:" ;
    cin>>c;
    if(c=='Y'|| c=='y')
{    
    do
    {
        cout<<"\n\n\t\tTASKS OF SEARCHIFY:";
        cout<<"\n\t\t-------------------------------------\n";
        cout<<"\n\t1.Make a search \n\t2.Remove your search from history \n\t3.Access your search history \n\t4.Most frequently browsed.\n\t5.Most recently browsed \n\t6.To give suggestions. \n\t7.Display search history \n\t8.Empty the browser history \n\t9.Clear browser history and Exit \n\t10.Exit \n";
        cout<<"\nEnter your option: ";
        cin>>opt;
        switch (opt)
        {
            case 1:
                //system("clear");
                cout<<"\nSearch or type a URL:  ";                        
                cin.ignore();
                getline(cin,val);
                key=create_key();
                A.insert(key,val);
                A.display();
                sleep(4);
                break;
            
            case 2:
                //system("clear");
                A.display();
                cout<<"\nEnter keyword or the entire URL: ";
                cin.ignore();
                getline(cin,val);
                A.find_key(val);
                if(flag==1)
                {
                    cout<<"\nSearch not found";
                }
                else
                {
                    cout<<"\n\nAfter deletion :\n"<<endl;
                    A.display();
                }
                
                flag=1;
                sleep(4);
                break;
            
            case 3:
                //system("clear");
                cout<<"\n\tAccess searches: ";
                cout<<endl;
                A.display();
                cout<<"\n\nEnter keyword: ";
                cin.ignore();
                getline(cin,val);
                A.search_(val);
                if(flag_s==1)
                {
                    cout<<"\nSearch not found";
                }
                
                flag_s=1;
                sleep(4);
                break;


            case 4:
                //system("clear");
                cout<<"\nTo check frequencies of searches made: \n"<<endl; 
                A.freq();
                A.print_max_min();
                sleep(4);
                break;

            case 5:
                //system("clear");
                cout<<"\n\n\t Most recently searched: ";
                A.most_recently_searched();
                sleep(4);
                break;

            case 6:
                //system("clear");
                cout<<"\n\tSUGGESTIONS: ";
                cout<<"\n\nEnter keyword (length 3)  :";
                cin.ignore();
                getline(cin,val);
                A.partialchecking(val);
                if(flag_p==1)
                {
                    cout<<"\nSearch not found";
                }
                
                flag_p=1;
                sleep(4);
                break;


            case 7:
                //system("clear");
                A.display();
                sleep(4);
                break;
            
            case 8:
                
                //system("clear");
                A.clear();
                cout<<"\n\n History is cleared!!!\n";
                A.display();
                sleep(4);
                break;

            case 9:
                //system("clear");
                A.make_empty();
                cout<<"\nBrowser History cleared! "<<endl;
                cout<<"\nTHANK YOU! VISIT LATER TO CHECK THE SEARCH HISTORY! :)\n";
                sleep(4);
                exit(0);
                break;

            case 10:
                cout<<"\nTHANK YOU! VISIT LATER TO CHECK THE SEARCH HISTORY! :)\n";
                exit(0);
                break;

            default:
                cout<<"\nEnter valid option!!";
                break;
        }

    } while (opt!=10);
}
else
{
    cout<<"\nTHANK YOU! VISIT LATER TO CHECK THE SEARCH HISTORY! :)";
}   
    return 0;     
}
