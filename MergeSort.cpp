/*
====Thuật toán sắp xếp trộn====
_ Ý tưởng chính:
    Thuật toán sắp xếp trộn (Merge Sort) dựa trên tư tưởng chia để trị (Divide and Conquer)
    Với việc chia các phần tử trong mảng cha thành hai nửa (left and right) cho đến khi mảng chỉ còn 1 phần tử hoặc rỗng và tiến hành gộp các mảng con lại
theo thứ tự cần sắp xếp (nhỏ nhất -> lớn nhất hoặc ngược lại)
_ Ví dụ mẫu:
    Ta xét dãy số [4,2,3,5,1]
    Chia mảng cha thành hai nửa:
        + Trái: [4,2]
        + Phải: [3,5,1]
        Tiếp tục gọi đệ quy chia mảng con:
        [4,2]
        Chia mảng cha thành hai nửa:
            + Trái: [4]
            + Phải: [2]
        Trộn hai mảng theo thứ tự sắp xếp tăng dần:
        [2,4]
        Tiếp tục gọi đệ quy chia mảng con:
        [3,5,1]
        Chia mảng cha thành hai nửa:
            + Trái: [3]
            + Phải: [5,1]
            Tiếp tục gọi đệ quy chia mảng con:
            [5,1]
            Chia mảng cha thành hai nửa:
                + Trái: [5]
                + Phải: [1]
            Trộn hai mảng theo thứ tự sắp xếp tăng dần:
            [1,5]
        Trộn hai mảng theo thứ tự sắp xếp tăng dần:
        [1,3,5]
    Trộn hai mảng theo thứ tự sắp xếp tăng dần:
    [1,2,3,4,5]
*/

#include <bits/stdc++.h>
using namespace std;

// Hàm trộn phần tử của mảng con
void mergeArr(int a[],int left,int mid,int right){
    // Khởi tạo số lượng phần tử cho mảng con bên trái và mảng con bên phải
    int len_left=(mid-left+1);
    int len_right=(right-mid);
    // Sử dụng hai mảng tạm thời để lưu giá trị của từng mảng con
    int arr_left[len_left],arr_right[len_right];
    for(int i=0;i<len_left;++i){
        arr_left[i]=a[left+i];
    }
    for(int i=0;i<len_right;++i){
        arr_right[i]=a[mid+i+1];
    }
    // Tiến hành trộn hai mảng con theo thứ tự cần sắp xếp với hai con trỏ i, j lần lượt đại diện cho hai mảng trái, phải
    int i=0, j=0, d=left-1;
    while(i<len_left&&j<len_right){
        // So sánh hai phần tử của hai mảng, phần tử nhỏ hơn được đưa vào trước
        if(arr_left[i]<=arr_right[j]){
            a[++d]=arr_left[i];
            ++i;
        }
        else{
            a[++d]=arr_right[j];
            ++j;
        }
    }
    // Trường hợp mảng phải rỗng
    while(i<len_left){
        a[++d]=arr_left[i];
        ++i;
    }
    // Trường hợp mảng trái rỗng
    while(j<len_right){
        a[++d]=arr_right[j];
        ++j;
    }
}

// Hàm đệ quy chia mảng cha thành mảng con
void mergeSort(int a[],int left,int right){
    // Kiểm tra nếu số lượng phần tử bằng 1 hoặc rỗng thì không cần tiếp tục chia mảng cha
    if(left>=right) return;
    // Nếu số lượng phần tử lớn hơn 1, tiến hàng đệ quy để chia mảng cha
    int mid=(left+right)/2;
    mergeSort(a,left,mid);
    mergeSort(a,mid+1,right);
    // Sau khi đệ quy tiến hành trộn hai mảng con
    mergeArr(a,left,mid,right);
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

