#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int p;
    int n;
    vector<int> v;
    for (;;)
    {
        cin>>p;
        if(p==0){
            break;
        }    
        else{
            for(int i=0;i<p;i++){
                cin>>n;
                v.push_back(n);
            }
            int min=v[0];
            int max=v[0];
            for(int j=0;j<p;j++){
                if(v[j]<min){
                    min=v[j];
                }
                if(v[j]>max){
                    max=v[j];
                }
            }
            if(p<2){
                cout<<v[0]<<endl;
            }
            else{
                cout<<(min+max)<<endl;
            }
            
            v.clear();
        }
    }
    return 0;
}