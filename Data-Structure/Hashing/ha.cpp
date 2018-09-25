#include<bits/stdc++.h>
using namespace std;


class Make
{
    public:
    string Name;

    Make(string name)
    {
      Name = name;
    }

    bool operator()(const Make &make) const
    {
      return Name == make.Name;
    }
};


class Model
{
    public:
    string Name;
    int Year;

    Model(string name, int year)
    {
      Name = name;
      Year = year;
    }

    bool operator==(const Model &model) const
    {
      return (Name == model.Name && Year == model.Year);
    }
};


class ModelHash
{
 public:
    size_t operator()(const Model &model) const
    {
       return hash<string>()(model.Name) ^ hash<int>()(model.Year);
    }
};

int main()
{
   unordered_map<Model, Make, ModelHash> model2make;


    Model camry2005("Camry", 2005);
    Model tercel1993("Tercel", 1993);

    Make toyota("Toyota");

    model2make.emplace(camry2005, toyota);
    model2make.emplace(tercel1993, toyota);


    for (auto &itr : model2make)
    {
       cout << itr.first.Name << " " << itr.first.Year << ": " << itr.second.Name << endl;
    }

    return 0;
}

/*
Reference :  //https://www.element14.com/community/community/code_exchange/blog/2013/05/24/c-tutorial--hash-tables
*/
