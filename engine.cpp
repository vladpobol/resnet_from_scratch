#include <iostream>
#include <Eigen/Dense>
#include <unsupported/Eigen/CXX11/Tensor>


using namespace std;
using namespace Eigen;

class Tensor{
public:
    Matrix <double, 3,3> value;
    void zeros(int a, int b, int c, int d){
        value = 
    }
}

int main(){
    Matrix <float, 3,3,3,3> matrix_A;
    matrix_A.setZero();

    cout<<"Go build Conv net!"<<endl;
    cout<<matrix_A<<endl;
    return 0;

}
