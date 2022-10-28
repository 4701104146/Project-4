#pragma once
#include "Order.h"
#include "Account.h"


enum class eColor;
void GoTo(SHORT posX, SHORT posY);
void SetColor(eColor highlight_color, eColor text_color);

namespace filePath {
    // File admin phải tự tạo từ trước bởi cá nhân và điền thông tin vào.
    const string g_FileAdmin = "D:\\admin.txt";

    // File hàng hóa tương tự file admin.
    // Thông tin trong file phải điền theo thứ tự
    /*
            (Mã hàng)~(Tên Hàng)~(Nơi sản xuất)~(Mau sắc)~(Giá cả)~(NgayNhapKho)~(Số lượng)
    */

    const string g_FileHangHoa = "D:\\HangHoa.txt";

    // File đơn hàng sẽ được tự tạo bởi chương trình.
    const string g_FileDonHang = "D:\\DonHang.txt";
}

class Program
{
    // key_press nhận nút điều khiển từ chương trình.
    char _cKeyPress = 0;
    int stt = 1;
    // mảng các tài khoản admin, đơn hàng, hàng hóa,
    vector<Account> szAdmin;
    vector<Item> szItems;
    queue<Order> szOrders;
   

public:
    // hàm lấy tài khoản và hàng hóa.
    void loadAdmins();
    void loadItems();
    //_____________________________

    void run();
    void menu();

    // menu
    void display();
    void search();
    void order();
    void manage();

    // quanLy//
    void menuManage();
    void loadingOrder();
    void manageItem();


    // quan ly hang hoa//
    void addItem();
    void removeItem();
    void updateItem();

    //______________________



    // ham bo tro
    bool orderSuccess(Order& o);
    bool login();

    // update Item có mã (code)
    void updateItem(const string& code, int product);
    bool foundItem(const string& code);


    void writeToFile(Order& o, const string& path, bool state);
    void uploadFile(const string& path);

    // hàm kiểm tra xem số sản phẩm (products) truyền vô có lớn hơn số sản phẩm tối đa của sản phẩm có mã là (code) không
    bool greaterMaxProducts(const string& code, int products);
};

