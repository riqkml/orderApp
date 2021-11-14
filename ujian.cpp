#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

class Order
{
private:
    struct MenuList
    {
        int no;
        string name;
        long price;
    };
    typedef struct OrderMenu
    {
        int orderNo;
        string name;
        string alamat;
        string menuName;
        int qty;
        long totalPrice;
        string dateOrder;
    } orderedMenu;
    vector<MenuList> menuData{{1, "nasi goreng rendang", 12000}, {2, "sate madura", 15000}, {3, "ayam pop", 10000}, {4, "dendeng betokok", 20000}, {5, "mie bakso", 15000}};

public:
    vector<OrderMenu> orderData;
    void inputingOrder()
    {
        int noOrder = 1, qty, multipleOrder, inputMenu;
        string name, alamat;
        long price;
        orderedMenu order;
        time_t now = time(0);
        char *dateTime = ctime(&now);
        cout << "Input Customer Name: ";
        cin >> name;
        cout << "Input Customer Address: ";
        cin >> alamat;
        system("CLS");
        cout << "No."
             << "        Name          "
             << "    Price     " << endl;
        for (int i = 0; i < menuData.size(); i++)
        {
            cout << menuData[i].no << "        " + menuData[i].name + "          " << menuData[i].price << endl;
        }
        cout << "How many menu types your customer order? ";
        cin >> multipleOrder;
        for (int i = 0; i < multipleOrder; i++)
        {
            cout << "Input Menu " << noOrder << ":";
            cin >> inputMenu;
            cout << "Enter quantity :";
            cin >> qty;
            price = qty * menuData[inputMenu - 1].price;
            order.orderNo = noOrder;
            order.name = name;
            order.alamat = alamat;
            order.menuName = menuData[inputMenu - 1].name;
            order.qty = qty;
            order.totalPrice = price;
            order.dateOrder = dateTime;
            orderData.push_back(order);
            noOrder++;
        }
    }
};

class Report
{
private:
    Order order;
    typedef struct ReportOrder
    {
        long totalRevenue;
        int totalMenuOrder;
        int totalCustomer;
    } reportOrder;
    reportOrder report;
    void countTotalRevenue()
    {
        for (int i = 0; i < order.orderData.size(); i++)
        {
            report.totalRevenue += order.orderData[i].totalPrice;
        }
    }
    void countTotalCustomer()
    {
        int counter = 0;
        for (int i = 0; i < order.orderData.size(); i++)
        {
            if (order.orderData[i].name == order.orderData[i + 1].name)
            {
                counter++;
            }
        }
        report.totalCustomer = counter;
    }
    void countTotalMenuOrder()
    {
        for (int i = 0; i < order.orderData.size(); i++)
        {
            report.totalMenuOrder += order.orderData[i].qty;
        }
    }

public:
    Report(Order order)
    {
        this->order = order;
        countTotalRevenue();
        countTotalCustomer();
        countTotalMenuOrder();
    };
    void getReportData()
    {
        cout << "Weekly Report Order" << endl;
        cout << "Total Menu Order:" << report.totalMenuOrder << endl;
        cout << "Total Customer:" << report.totalCustomer << endl;
        cout << "Total Revenue:" << report.totalRevenue << endl;
    }
};

int main()
{
    int options;
    bool repeat = true;
    char c;
    Order order;
    while (repeat)
    {
        cout << "Choice these options: " << endl;
        cout << "1. Input Order" << endl;
        cout << "2. See Report" << endl;
        cout << "3. Exit" << endl;
        cout << "Input menu: ";
        cin >> options;
        if (options == 1)
        {
            order.inputingOrder();
            cout << "Back to main menu? (y/n) : ";
            cin >> c;
            if (c == 'n' || c == 'N')
            {
                repeat = false;
            }
        }
        if (options == 2)
        {
            Report report = Report(order);
            report.getReportData();
            cout << "Back to main menu? (y/n) : ";
            cin >> c;
            if (c == 'n' || c == 'N')
            {
                repeat = false;
            }
        }
        if (options == 3)
            exit(0);
    }
    return 0;
}
