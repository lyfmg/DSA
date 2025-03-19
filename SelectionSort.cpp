/*
====Thuật toán sắp xếp chọn====
_ Ý tưởng chính:
    Thuật toán sắp xếp chọn (Selection Sort) lấy ý tưởng là tìm phần tử nhỏ nhất (hoặc lớn nhất) trong phần chưa được sắp xếp và đưa nó về đúng vị trí ở đầu mảng.
    Ta chia mảng thành hai phần: phần đã được sắp xếp (nửa trái, ban đầu rỗng) và phần chưa được sắp xếp (nửa còn lại).
    Ta tiến hành duyệt các phần tử trong nửa chưa được sắp xếp, tìm phần tử nhỏ nhất và hoán đổi nó với phần tử đầu tiên của nửa chưa được sắp xếp, sau đó phần
tử đó sẽ được đưa vào nửa đã được sắp xếp.
_ Ví dụ mẫu:
    Ta xét dãy số [4,1,2,3,5]
    Phần đã được sắp xếp: [] - Phần chưa được sắp xếp: [4,1,2,3,5]
    Ta tiến hành duyệt từng phần từ trong phần chưa được sắp xếp:
        + Lần duyệt thứ nhất:
            Tìm phần tử nhỏ nhất trong [4,1,2,3,5]: 1
            Hoán đổi 1 với phần tử đầu tiên 4: [1,4,2,3,5]
            Phần đã được sắp xếp: [1] - Phần chưa được sắp xếp: [4,2,3,5]
        + Lần duyệt thứ hai:
            Tìm phần tử nhỏ nhất trong [4,2,3,5]: 2
            Hoán đổi 2 với phần tử đầu tiên 4: [2,4,3,5]
            Phần đã được sắp xếp: [1,2] - Phần chưa được sắp xếp: [4,3,5]
        .....
        Tiếp tục thực hiện tương tự cho đến khi mảng đã được sắp xếp hoàn toàn theo thứ tự tăng dần: [1,2,3,4,5]
*/

#include <bits/stdc++.h>
using namespace std;

// Hàm thực hiện sắp xếp với đầu vào là mảng cần sắp xếp, vị trí bắt đầu và kết thúc của mảng
int selectionSort(int a[N],int left,int right){
    // Duyệt qua lần lượt các phần tử chưa được sắp xếp
    for(int i=left;i<right;++i){
        int minInd=i;
        // Tiến hành tìm kiếm phần tử nhỏ nhất trong phần chưa được sắp xếp
        for(int j=i+1;j<=right;++j){
            if(a[j]<a[minInd]){
                minInd=j;
            }
        }
        // Hoán với vị trí phần tử nhỏ nhất và phần tử đầu tiên trong mảng chưa được sắp xếp
        swap(a[i],a[minInd]);
    }
}

// Chương trình chính
int main(){
    // Khởi tạo và nhập số lượng phần tử của dãy số
    cout<<"Nhap so luong phan tu: ";
    int n;
    cin>>n;
    // Khởi tạo mảng và lưu các giá trị phần tử trong dãy số
    int a[n+1]={};
    for(int i=1;i<=n;++i){
        cout<<"Nhap phan tu thu "<<i<<": ";
        cin>>a[i];
    }
    // Hiển thị ra màn hình dãy số trước khi được sắp xếp
    cout<<"Day so ban dau"<<endl;
    for(int i=1;i<=n;++i){
        cout<<a[i]<<' ';
    }
    // Gọi hàm sắp xếp dãy số
    insertionSort(a,1,n);
    // Hiển thị ra màn hình kết quả sau khi đã sắp xếp
    cout<<"\n=========================================="<<endl;
    cout<<"Day so sau khi duoc sap xep"<<endl;
    for(int i=1;i<=n;++i){
        cout<<a[i]<<' ';
    }
    return 0;
}
