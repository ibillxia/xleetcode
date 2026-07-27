#include<iostream>
#include<vector>

using namespace std;

class SubrectangleQueries {
public:
    vector<vector<int>> rect;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        this->rect = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int i=row1;i<=row2;i++){
            for(int j=col1;j<=col2;j++){
                this->rect[i][j]=newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        return this->rect[row][col];
    }

    void printRect(){
        int m=this->rect.size();
        int n = this->rect[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<rect[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>> rectangle(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>rectangle[i][j];
        }
    }
    SubrectangleQueries* obj = new SubrectangleQueries(rectangle);

    // tests
    cout<<"Test 1, input row,col:"<<endl;
    int row,col;
    cin>>row>>col;
    int param_1 = obj->getValue(row,col);
    cout<<param_1<<endl;

    cout<<"Test 2, intput row1,col1,row2,col2,newValue:"<<endl;
    int row1,col1,row2,col2,newValue;
    cin>>row1>>col1>>row2>>col2>>newValue;
    obj->updateSubrectangle(row1,col1,row2,col2,newValue);
    cout<<"After update:"<<endl;
    obj->printRect();

    cout<<"Test 3, input row,col:"<<endl;
    cin>>row>>col;
    int param_2 = obj->getValue(row,col);
    cout<<param_2<<endl;
    return 0;
}