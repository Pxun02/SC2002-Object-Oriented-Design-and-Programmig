#include <iostream>
#include <iterator>
using namespace std;
class Bubble{
    public:
        int i, j, t;
        Bubble(int a[], int n) {
            _n = n;
            for(i=0;i<=n-1;i++){
                _a[i] = a[i];
            }
        }
        void bubble(){
            for(i=_n-2;i>=0;i--){
                for(j=0;j<=i;j++){
                    if(_a[j]>_a[j+1]){
                        t=_a[j];
                        _a[j]=_a[j+1];
                        _a[j+1]=t;
                    }
                }
            }
        }
        int* get_a(){ return _a; }
    private:
        int _n;
        int _a[100];
};
int main(){
    int a[100],n,i;
    cout << "\n\n Enter number of Integer elements to be sorted: " << endl;
    cin >> n;

    for(i=0;i<=n-1;i++){
        cout << "\n\n Enter integer value for element no." << i+1 << " : " << endl;
        cin >> a[i];
    }
    Bubble b(a, n);
    b.bubble();

    cout << "\n\n Finally sorted array is: " << endl;
    for(i=0;i<=n-1;i++){
        cout << b.get_a()[i] << " ";
    }
    cout << endl;
 }