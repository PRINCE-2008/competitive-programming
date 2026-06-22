#include <iostream>

using namespace std;

class vector{
    private:
        int size;
        double* data;
    public:
        vector(int s): size(s), data(new double[s]) {}
        ~vector() { delete[] data; }
        double& operator[](int i) { return data[i]; }
        double at(int i) {
            if (i<0 || i>=size) throw out_of_range("Index out of range");
            return data[i];
        }
        int size() const { return size; }
        int push(){
            double* newData = new double[size+1];
            for (int i=0; i<size;i++) newData[i] = data[i];
            delete[] data;
            data = newData;
            size++;
            return size-1;
        }
        void pop(){
            if(size==0) throw out_of_range("Vector is empty");
            double* newData = new double[size-1];
            for (int i=0; i<size-1;i++) newData[i] = data[i];
            delete[] data;
            data = newData;
            size--;
            return ;
        }
        void pop(int index){
            double* newData = new double[size-1];
            for(int i=0 ; i< size ;i++){
                if(i==index) continue;
                if(i<index) newData[i] = data[i];
                if(i>index) newData[i-1]=data[i];
            }
            delete[] data;
            data = newData;
            size--;
            return ;
        }


};