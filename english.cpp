#include "std_lib.cpp"
using namespace std;

bool Error = true;
string getword()
{
    string word;
    cin>>word;
    return word;
}
string article()
{
    string left = getword();
    if(left != "a" || left != "A" || left != "the" || left != "The")    
        Error = true;
    return left;
}
string name()
{
    string left = getword();
    if(left != "birds" || left != "fish" || left != "c++" ||
        left != "Birds" || left != "Fish" || left != "C++")  Error = true;
    return left;
};
string verb()
{
    string left = getword();
    if(left != "rules" || left != "fly" || left != "swim")  Error = true;
    return left;
};
string conjunction()
{
    string left = getword();
    if(left != "and" || left != "but" || left != "or")  Error = true;
    return left;
}

bool sentence()
{
    string first = getword();
    if(first == "C++" || first == "Birds" || first == "Fish")  
    {
        string second = getword();
        if(second=="rules"||second=="fly"||second=="swim")
        {
            string third = getword();
            if(third==".")    Error = false;
            else if(third =="but" || third =="and" || third =="or")
            {
                string fourth = getword();
                if(fourth=="c++" || fourth=="birds" || fourth=="fish")
                {
                    string fifth = getword();
                    if(fifth=="rules"||fifth=="fly"||fifth=="swim")
                    {
                        string sixth = getword();
                        if(sixth == ".")   Error = false;
                        else Error = true;
                    }
                    else Error = true;
                }
                else Error = true;
            }
            else Error = true;
        }
        else Error = true;
    }
    else if(first=="The"|| first=="A")
    {
        string first = getword();
        if(first == "c++" || first == "birds" || first == "fish")  
        {
            string second = getword();
            if(second=="rules"||second=="fly"||second=="swim")
            {
                string third = getword();
                if(third==".")    Error = false;
                else if(third =="but" || third =="and" || third =="or")
                {   
                    string middle = getword();
                    if(middle=="a" || middle=="the")
                    {      
                        string fourth = getword();
                        if(fourth=="c++" || fourth=="birds" || fourth=="fish")
                        {
                            string fifth = getword();
                            if(fifth=="rules"||fifth=="fly"||fifth=="swim")
                            {
                                string sixth = getword();
                                if(sixth == ".")   Error = false;
                                else Error = true;
                            }
                            else Error = true;
                        }
                        else Error = true;
                    }
                    else Error = true;
                }
                else Error = true;
            }
            else Error = true;    
        }
    }
    else Error = true;
    return Error;
}


int main()
{
    there:
    if(sentence()==false) cout<<"OK";
    else cout<<"not OK";
    goto there;
    return 0;
}