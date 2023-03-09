#include"std_lib.cpp"

class NameValue {
    public:
        string name;
        double value;
        NameValue(string name)
        :name(name), value(0) {}
        NameValue(string name, double score)
        :name(name), value(score) {}
    };

using namespace std;
int main()
{
    
    vector<NameValue>nameScore, temp;
    bool finish = false, name_twice = false;
    double score;
    string name;
    while(!finish && cin>>name>>score)
    {
        for(int i=0;i<nameScore.size();++i)
            if(name==nameScore[i].name) name_twice = true;
        if(name_twice)    
            error("You have entered a name twice");
        if(name == "noName"||score==0) 
            finish = true;
        else 
            nameScore.push_back({name, score});  
    } 
    cout<<"Enter the score to get names with that score : ";
    cin>>score;
    for(int x=0;x<nameScore.size();++x)
    {
        if(score==nameScore[x].value)
        {   
            temp.push_back({nameScore[x].name, nameScore[x].value});
        }
    }
    for(int i=0;i<temp.size();++i)
        cout<<temp[i].name<<", ";
    return 0;
}
