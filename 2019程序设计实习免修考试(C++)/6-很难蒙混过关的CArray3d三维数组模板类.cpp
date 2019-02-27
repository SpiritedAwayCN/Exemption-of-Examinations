#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
template <class T>
class CArray3D
{
// �ڴ˴�������Ĵ���
public:
    class CArray2D{
    public:
        void set_func(int xx,int yy){
            x=xx;y=yy;
            p = new T[xx*yy];
        }
        T* operator[](int index){
            return p+y*index;
        }
        operator T*(){
            return p;
        }
    private:
        int x,y;
        T *p;
    };

    CArray3D(int a,int b,int c)
    : layer(a)
    {
        ptr = new CArray2D[a];
        for(int i=0;i<a;i++)
            ptr[i].set_func(b,c);
    }
    CArray2D& operator[](int index){
        return ptr[index];
    }
private:
    int layer;
    CArray2D* ptr;
};

CArray3D<int> a(3,4,5);
CArray3D<double> b(3,2,2);
void PrintA()
{
	for(int i = 0;i < 3; ++i) {
		cout << "layer " << i << ":" << endl;
		for(int j = 0; j < 4; ++j) {
			for(int k = 0; k < 5; ++k)
				cout << a[i][j][k] << "," ;
			cout << endl;
		}
	}
}
void PrintB()
{
	for(int i = 0;i < 3; ++i) {
		cout << "layer " << i << ":" << endl;
		for(int j = 0; j < 2; ++j) {
			for(int k = 0; k < 2; ++k)
				cout << b[i][j][k] << "," ;
			cout << endl;
		}
	}
}

int main()
{

	int No = 0;
	for( int i = 0; i < 3; ++ i ) {
		a[i];
		for( int j = 0; j < 4; ++j ) {
			a[j][i];
			for( int k = 0; k < 5; ++k )
				a[i][j][k] = No ++;
			a[j][i][i];
		}
	}
	PrintA();
	memset(a[1],-1 ,20*sizeof(int));
	memset(a[1],-1 ,20*sizeof(int));
	PrintA();
	memset(a[1][1],0 ,5*sizeof(int));
	PrintA();

	for( int i = 0; i < 3; ++ i )
		for( int j = 0; j < 2; ++j )
			for( int k = 0; k < 2; ++k )
				b[i][j][k] = 10.0/(i+j+k+1);
	PrintB();
	int n = a[0][1][2];
	double f = b[0][1][1];
	cout << "****" << endl;
	cout << n << "," << f << endl;

	return 0;
}
