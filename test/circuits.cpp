#include "../include/qSim.h"

using namespace qsim;
using namespace math;
using namespace std;

int main() {
    Ket k1 = states::z1;
    Ket k2 = states::z1;
    Ket k3 = states::z0;

    Matrix H = gates::H;
    Matrix CX = control(gates::X);
    Matrix T = gates::T;
    Matrix Td = T.adjoint();
    Matrix S = gates::S;
    Matrix X = gates::X;
    Matrix I = gates::I;

    Ket* q1 = &k1;
    Ket* q2 = &k2;
    Ket* q3 = &k3;


    circuit::Circuit balls;

    balls.setQubits({q1, q2, q3});

    //balls.setCircuit({ { H, {q3}},
    //                   {CX, {q2, q3}},
    //                   {Td, {q3}},
    //                   {CX, {q1, q3}},
    //                   { T, {q3}},
    //                   {CX, {q2, q3}},
    //                   {Td, {q3}},
    //                   {CX, {q1, q3}},
    //                   {Td, {q2}},
    //                   { T, {q3}},
    //                   {CX, {q1, q2}},
    //                   { H, {q3}},
    //                   {Td, {q2}},
    //                   {CX, {q1, q2}},
    //                   { T, {q1}},
    //                   { S, {q2}} });


    Matrix piano = tensorProduct(I, tensorProduct(control(H), I));

    Ket b0 = states::z0;
    Ket b1 = states::z1;
    Ket b2 = states::z0;
    Ket b3 = states::z0;

    b2 *= H;


    Ket total = b0 * b1 * b2;

    total.print();
    //total *= piano;

    total.print();
    
}