#include <iostream>
using namespace std;

// 1. KHAI BÁO 3 MẢNG QUẢN LÝ CÂY
int gia_tri[100005]; // Lưu giá trị số
int trai[100005];    // Lưu vị trí con trái
int phai[100005];    // Lưu vị trí con phải
int dem = 0;         // Đếm số lượng nút đã tạo

// 2. HÀM THÊM SỐ VÀO CÂY
int them(int goc, int x) {
    // Nếu chỗ này chưa có ai -> Tạo nút mới
    if (goc == 0) {
        dem++;
        gia_tri[dem] = x;
        trai[dem] = 0; // Mới tạo thì chưa có con
        phai[dem] = 0;
        return dem;    // Trả về vị trí nút mới
    }

    // Nếu nhỏ hơn -> Về đội bên Trái
    if (x < gia_tri[goc]) {
        trai[goc] = them(trai[goc], x);
    }
    // Nếu lớn hơn -> Về đội bên Phải
    else if (x > gia_tri[goc]) {
        phai[goc] = them(phai[goc], x);
    }
    
    return goc;
}

// 3. HÀM TÌM NÚT TRÁI NHẤT (Nhỏ nhất)
// Dùng để tìm người thế mạng khi xóa nút có 2 con
int tim_nho_nhat(int goc) {
    int hien_tai = goc;
    // Cứ rẽ trái mãi đến khi hết đường
    while (trai[hien_tai] != 0) {
        hien_tai = trai[hien_tai];
    }
    return hien_tai;
}

// 4. HÀM XÓA (Quan trọng nhất)
int xoa(int goc, int k) {
    if (goc == 0) return 0; // Không tìm thấy để xóa

    if (k < gia_tri[goc]) {
        trai[goc] = xoa(trai[goc], k); // Tìm xóa bên trái
    } 
    else if (k > gia_tri[goc]) {
        phai[goc] = xoa(phai[goc], k); // Tìm xóa bên phải
    } 
    else {
        // ĐÃ TÌM THẤY NÚT CẦN XÓA!
        
        // TH1: Khuyết con trái -> Con phải lên thay
        if (trai[goc] == 0) return phai[goc];
        
        // TH2: Khuyết con phải -> Con trái lên thay
        if (phai[goc] == 0) return trai[goc];

        // TH3: Có đủ 2 con (Khó nhất)
        // Đề bài: "Chọn nút trái nhất bên phải để thay thế"
        int the_mang = tim_nho_nhat(phai[goc]);
        
        // Lấy giá trị của người thế mạng đắp vào chỗ cần xóa
        gia_tri[goc] = gia_tri[the_mang];
        
        // Sau đó đi xóa cái xác cũ của người thế mạng ở bên phải đi
        phai[goc] = xoa(phai[goc], gia_tri[the_mang]);
    }
    return goc;
}

// 5. DUYỆT TIỀN THỨ TỰ (Gốc - Trái - Phải)
void tien_tu(int goc) {
    if (goc == 0) return;
    cout << gia_tri[goc] << " ";
    tien_tu(trai[goc]);
    tien_tu(phai[goc]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k;
    if (cin >> n >> k) {
        int goc = 0; // Ban đầu cây rỗng
        int so;
        
        // Nhập và xây dựng cây
        for (int i = 0; i < n; i++) {
            cin >> so;
            goc = them(goc, so);
        }

        // Xóa số k
        goc = xoa(goc, k);

        // In kết quả
        tien_tu(goc);
    }
    return 0;
}