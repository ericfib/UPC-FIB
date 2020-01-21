#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
  string name,language;
};

vector<Person> read_people()
{
  int n;
  cin>>n;
  vector<Person> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i].name >> v[i].language;
  }

  return v;
}

// Returns true if p1 is smaller than p2, by comparing first by language,
// and as a second criteria by name.
bool smaller(Person p1,Person p2)
{
  if (p1.language == p2.language) return p1.name < p2.name;
  return p1.language < p2.language;
}

// Add here other functions if you need them...

// Pre: v is sorted by language, and by name as a second criteria.
// Prints the information of v following the format of the statement.
void print(vector<Person> &v)
{
  int n = v.size();
  string comp = v[0].language;
  cout << v[0].language << ": " << v[0].name;
  for(int i = 1; i < n; i++){
    if (v[i].language != comp){
      cout << "." << endl;
      comp = v[i].language;
      cout << v[i].language << ":";
    }
    cout <<" " << v[i].name;

  }
  cout << "." << endl;

}

int main()
{
  vector<Person> v=read_people();
  sort(v.begin(),v.end(),smaller);
  print(v);
}
