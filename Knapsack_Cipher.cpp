#include<iostream>
#include<cmath>

using namespace std;
int main(){
    int m,M,KC,L,Valid=1,MaxES;
    int ES['L'],ESA['L']={0};
    cout<<"Hello we are today going to find Solution of any knapsack cipher problem \n";
    cout<<"Enter modulus value m: ";
    cin>>m;
    cout<<"Enter Any Multipler M: ";
    cin>>M;
    cout<<"Enter Knapsack cipher one term KC: ";
    cin>>KC;
    cout<<"Enter how length of Enciphering sequence ES is L: ";
    cin>>L;
    cout<<"Enter your Enciphering sequence ES: \n";
    for(int i=0;i<L;i++){
        if(i==0){
            cout<<"Enter 1 st term of ES: ";
            cin>>ES[0];
        }else if(i==1){
            cout<<"Enter 2 nd term of ES: ";
            cin>>ES[1];
        }else if(i==2){
            cout<<"Enter 3 rd term of ES: ";
            cin>>ES[2];
        }else{
            cout<<"Enter "<<i<<" th term of ES: ";
            cin>>ES[i];
        }
    }
    float FiOfm,InversePower,InversePower2;
    unsigned long long int FinalInverse=1,Inverse,D,D1,InverseAns,Check=0,OkRPrime=1,WPower=2;
    long int Length=1024,PowerOf2[Length+1]={0},i;
    //Finding FiOf(m)
    if(m==1){
        FiOfm=1;
    }else if(m==2){
        FiOfm=1;
    }else if(m!=1){
         for (int i=2;i<m;i++){
            for(int j=1;j<=m;j++){
                if(i%j==0 && m%j==0){
                    Check++;
                }
            }
            if(Check==1){
                OkRPrime++;
            }
            Check=0;
     }
    }
    FiOfm=OkRPrime;
    //Puting Value of InversePower 
    InversePower=FiOfm-1;
    InversePower2=FiOfm-1;
    //Finding all Powers
    PowerOf2[1]=M;
    for(i=2;i<=InversePower;)
    {
           PowerOf2[i]=(PowerOf2[(i/2)])*(PowerOf2[(i/2)]);
           cout<<M<<" ki Power "<<i<<" is "<<PowerOf2[i];
           D=PowerOf2[i]/m;
           PowerOf2[i]=PowerOf2[i]-D*m;
           cout<<" And mod "<<m<<" is "<<PowerOf2[i]<<"\n";
           i=i*2;
           
    }
    //Finding Inverse Of M
    cout<<"Now we Have ";
        for(int j=Length;j>0;){
            if((PowerOf2[j])!=0){
                if(InversePower>j){
                    cout<<j<<" + ";
                FinalInverse=FinalInverse*PowerOf2[j];
                D1=FinalInverse/m;
                FinalInverse=FinalInverse-D1*m;
                PowerOf2[j]=0;
                InversePower=InversePower-j;
                }
            }
            j/=2;
        }
        if(InversePower==1){
            FinalInverse=FinalInverse*M;
            D1=FinalInverse/m;
            FinalInverse=FinalInverse-D1*m;
            InversePower--;
            PowerOf2[1]=0;
            cout<<" 1 = "<<InversePower2;
        }
        //finding KC Mod m
        KC=FinalInverse*KC;
        D1=KC/m;
        KC=KC-D1*m;
        cout<<"\n"<<KC;
        for(int i=0;i<L;i++){
            ES[i]=FinalInverse*ES[i];
            D1=ES[i]/m;
            ES[i]=ES[i]-D1*m;
        }
        while(KC!=0){
        for(int k=0;k<L;k++){
        if(KC>=ES[k] && ES[k]!=0){
                KC=KC-ES[k];
                ES[k]=0;
                ESA[k]=1;
        }
     }
     cout<<KC;
    }
    
    cout<<"\nInverse Power is : "<<InversePower;
    cout<<"\nPower Of M to L is : "<<PowerOf2[1]<<","<<PowerOf2[2]<<","<<PowerOf2[4]<<","<<PowerOf2[8]<<","<<PowerOf2[16]<<","<<PowerOf2[32]<<","<<PowerOf2[64]<<","<<PowerOf2[65]<<","<<PowerOf2[128];
    cout<<"\nFinalInverse is : "<<FinalInverse;
    cout<<"\nRequired Solution is ";
    for(int k=0;k<L;k++){
        cout<<ESA[k]<<"  ";
    }

    return 0;
}