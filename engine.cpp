#include <iostream>
#include <Eigen/Dense>
#include <unsupported/Eigen/CXX11/Tensor>
#include <random>
#include <functional>


using namespace std;
using namespace Eigen;

class Tensor{
public:

    Eigen::Tensor<double, 4> tensor; /* создаем экземпляр класса тензор*/
    Eigen::Tensor<double, 4> grad;
    function<void()> _backward;

    Tensor(int a, int b, int c, int d): tensor(a,b,c,d), grad(a,b,c,d){
        tensor.setZero();
        grad.setZero();
    }

    void random(int a, int b, int c, int d){
        random_device rd;
        mt19937 gen(rd());
        normal_distribution<float> dist(0.0, 1.0);

        for(int i = 0; i < tensor.size(); ++i){
            tensor.data()[i] = dist(gen);
        }
    }

    Tensor operator+(const Tensor& other) const{
        Tensor result(tensor.dimension(0), tensor.dimension(1), tensor.dimension(2), tensor.dimension(3));
        result.tensor = tensor + other.tensor;
        result.grad.setZero();

        result._backward = [this, other, &result]() mutable{
            this->grad += result.grad;
            other.grad += result.grad;
        };

        return result;
    }

};

int main(){
    Matrix <float, 3,3,3,3> matrix_A;
    matrix_A.setZero();

    cout<<"Go build Conv net!"<<endl;
    cout<<matrix_A<<endl;
    return 0;

}
