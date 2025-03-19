/*
====Thuật toán sắp xếp chèn====
_ Ý tưởng chính:
    Thuật toán sắp xếp chèn (Insertion Sort) lấy ý tưởng sắp xếp các phần tử trong dãy số tựa như việc sắp xếp các lá bài trên tay.
    Ta chia phần tử trong mảng thành 2 phần: phần đã được sắp xếp (nửa trái, ban đầu chỉ chứa phần tử đầu tiên) và phần chưa được sắp xếp (nửa còn lại).
    Ta tiến hành duyệt các phần tử trong nửa chưa được sắp xếp và cố gắng đưa nó về đúng vị trí trong nửa đã được sắp xếp.
_ Ví dụ mẫu:
    Ta xét dãy số [4,1,2,3,5]
    Phần đã được sắp xếp: [4] - Phần chưa được sắp xếp: [1,2,3,5]
    Ta tiến hành duyệt từng phần từ trong phần chưa được sắp xếp:
        + Lần duyệt thứ nhất:
            Phan_tu=1
            So sánh với từng giá trị trong mảng đã được sắp xếp: (4>1)
            Dịch chuyển 4 sang phải: [,4]
            Chèn 1 vào khoảng trống: [1,4]
            Phần đã được sắp xếp: [1,4] - Phần chưa được sắp xếp: [2,3,5]
        + Lần duyệt thứ hai:
            Phan_tu=2
            So sánh với từng giá trị trong mảng được sắp xếp: (2>1), (2<4)
            Dịch chuyển 4 sang phải: [1,,4]
            Chèn 2 vào khoảng trống: [1,2,4]
            Phần đã được sắp xếp: [1,2,4] - Phần chưa được sắp xếp: [3,5]
        .....
        Tiếp tục thực hiện tương tự cho đến khi mảng đã được sắp xếp hoàn toàn theo thứ tự tăng dần: [1,2,3,4,5]
*/

#include <bits/stdc++.h>
using namespace std;

// Hàm thực hiện sắp xếp với đầu vào là mảng cần sắp xếp, vị trí bắt đầu và kết thúc của mảng
void insertionSort(int a[],int left,int right){
    // Duyệt qua lần lượt các phần tử chưa được sắp xếp
    for(int i=left+1;i<=right;++i){
        // Đối với mỗi phần tử chưa được sắp xếp, tiến hành đưa nó về vị trí đúng trong phần đã được sắp xếp
        int val=a[i];
        int j=i-1;
        // Dịch chuyển các phần tử lớn hơn phần tử đang xét sang phải
        while(a[j]>val&&j>=0){
            a[j+1]=a[j];
            --j;
        }
        // Chèn phần tử đang xét vào đúng vị trí
        a[j+1]=val;
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
