#include<iomanip>
#include<cmath>
using namespace std;
class Complex{
private:
    double real,img;

public:
    Complex(double real,double img){
        this->real=real;
        this->img=img;
    }
    Complex(){
        real=0;
        img=0;
    }
    double getModulus(){
        return sqrt(real*real+img*img);
    }
    bool operator>( Complex rhs){
        return this->getModulus()>rhs.getModulus();
    }
     bool operator<(Complex rhs){
        return this->getModulus()<rhs.getModulus();
    }
     bool operator==(Complex rhs){
        return this->getModulus()==rhs.getModulus();
    }
     bool operator!=(Complex rhs){
        return this->getModulus()!=rhs.getModulus();
    }
     bool operator>=(Complex rhs){
        return this->getModulus()>=rhs.getModulus();
    }
     bool operator<=(Complex rhs){
        return this->getModulus()<=rhs.getModulus();
    }
};
class StraightSelectionSort{
public:
static void sort(Complex *list, int length){
    for(int i=0;i<length;i++){
        double min=list[i].getModulus();
        int k=i;
        for(int j=i+1;j<length;j++){
            if(min>list[j].getModulus()){
                k=j;
                min=list[j].getModulus();
            }
        }
        Complex temp=list[i];
        list[i]=list[k];
        list[k]=temp;
    }
}
static void sort(Complex *list, int length, int left, int right){
    for(int i=left;i<=right;i++){
        double min=list[i].getModulus();
        int k=i;
        for(int j=i+1;j<=right;j++){
            if(min>list[j].getModulus()){
                k=j;
                min=list[j].getModulus();
            }
        }
        Complex temp=list[i];
        list[i]=list[k];
        list[k]=temp;
    }
}
};
class StraightInsertionSort{
    public:
    static void sort(Complex *list, int length){
        if (length > 1){
             int curr = 1;
             while (curr < length){
             Complex tmp = list[curr];
             int step = curr - 1;
                 while (step >= 0 && tmp < list[step]) {
                 list[step + 1] = list[step];
                 step = step -1 ;
                 }
                 list[step + 1] = tmp;
                 curr = curr + 1;
             }
        }
    }
     static void sort(Complex *list,  int length, int left, int right){
        if (length > 1){
             int curr = left;
             while (curr <= right){
             Complex tmp = list[curr];
             int step = curr - 1;
                 while (step >= 0 && tmp.getModulus() < list[step].getModulus()) {
                 list[step + 1] = list[step];
                 step = step -1 ;
                 }
                 list[step + 1] = tmp;
                 curr = curr + 1;
             }
        }
    }
};
class BubbleSort 
{
private:
    /* data */
public:
    static void sort(Complex *list, int length){
           int curr = 0;
            bool flag = false;
            while (curr < length && flag == false) {
                int step = length - 1;
                flag = true;
                while (step > curr) {
                    if (list[step].getModulus() < list[step - 1].getModulus()){
                        flag = false;
                        Complex temp=list[step];
                        list[step]=list[step-1];
                        list[step-1]=temp;
                    }
                    step = step - 1;
                }
                
                curr = curr + 1;
            }
    }
    static void sort(Complex *list, int length, int left, int right){
            int curr = left;
            bool flag = false;
            while (curr <= right && flag == false) {
                int step = right ;
                flag = true;
                while (step > curr) {
                    if (list[step].getModulus() < list[step - 1].getModulus()){
                        flag = false;
                        Complex temp=list[step];
                        list[step]=list[step-1];
                        list[step-1]=temp;
                    }
                    step = step - 1;
                }
                
                curr = curr + 1;
            }
    }
};
void sort_segment(int segment,int k, Complex*list,int count){
        int curr = segment + k;
        while (curr < count) {
            Complex tmp = list[curr];
            int step = curr - k;
            while (step >=0 && tmp.getModulus() < list[step].getModulus())
            {list[step + k] = list[step];
            step = step - k;
            }
         list[step + k] = tmp;
         curr = curr + k;
        }
}
class ShellSort{
    private:
    int*increments;
    int lengthOfIncrements;// length=8
    public:
    ShellSort(int *increments, int lengthOfIncrements){
        this->increments=increments;
        this->lengthOfIncrements=lengthOfIncrements;
    }
    static void sortSegment(Complex *list, int length, int increment, int segment = 0){
        int k = increment;
        while (k >= 1) {
             while (segment < k) {
             sort_segment(segment, k,list,length);
             segment = segment + 1;
            }k=k/2;
        }
    }
    void sort(Complex *list, int length){
        int i=0;
        while (i<lengthOfIncrements) {
            int k = increments[i];
            int segment=0;
             while (segment < k) {
             sort_segment(segment, k,list,length);
             segment = segment + 1;
            }
             i++;
        }

    }
};

