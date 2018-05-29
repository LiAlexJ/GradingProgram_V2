#include "readInput.h"
using namespace std;

istream& read(istream& is, vector<string>& words)
{
    if(is){
       words.clear(); 
       string word;
       while(is >> word){
            words.push_back(word);
       }
       is.clear();
    }
    return is;
}

istream& read(istream& is, vector<double>& vals)
{
    if(is){
       vals.clear(); 
       double val;
       while(is >> val){
            vals.push_back(val);
       }
       is.clear();
    }
    return is;
}
//countWords will output the number of words in std::vector<string> words and the number of occurrences of each word
int countWords(vector<string>& words)
{
  sort(words.begin(), words.end());
   
  int max_len = 0; 
  vector<string>::iterator iter = words.begin();
  while(iter != words.end()){
      max_len = ((*iter).length() > max_len) ? (*iter).length() : max_len;
      ++iter;
  }
      
  int count = 1;
  const int padding = 5;
  const int col = padding + max_len;
  typedef vector<string>::size_type size;
  size i = 0;
  while(i < words.size()){
     if(i+1 < words.size() && words[i] == words[i+1]){
        count++;
     }
     else{
        int len = words[i].size();
        cout<<words[i]<<setw(col - len + padding)<<count<<endl;
        count = 1;
     }
     i++;

  }
  cout<<"Total Number of Words: " << words.size() << endl;

  return 0;

} 

double computeAverage(const vector<double>& vals)
{
    double sum;
    typedef vector<double>::size_type size;
    const size num_elem = vals.size();
    vector<double>::const_iterator iter = vals.begin();
    while(iter != vals.end())
    {
        sum += *iter;
        ++iter;
    }
    return sum/num_elem;
}


int main()
{
    /*
    vector<string> words;
    
    read(cin, words);

    int ret = countWords(words);
    if(ret == 1) return 1;
    else return 0;
    */
    vector<double> vals;
    read(cin, vals);
    double average = computeAverage(vals);
    cout << "Average is: " << average << endl;
    return 0;

}
