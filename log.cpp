#include "log.h"
#include "sales.h"

using namespace std;

void Log::log(int price, string productName[], vector<pair<int,int>> v) {
    string str;
    time_t curr_time;
    struct tm *curr_tm;

    string str_;
    fstream openFile;

    openFile.open("sales.txt");
    getline(openFile, str_);
    openFile.close();

    curr_time = time(NULL);
    curr_tm = localtime(&curr_time);

    str += "\n(";
    str += to_string(curr_tm -> tm_year + 1900);
    str += "-";
    if(curr_tm -> tm_mon + 1 < 10) str += "0";
    str += to_string(curr_tm -> tm_mon + 1);
    str += "-";
    if(curr_tm -> tm_mday < 10) str += "0";
    str += to_string(curr_tm -> tm_mday);
    str += "T";
    if(curr_tm -> tm_hour < 10) str += "0";
    str += to_string(curr_tm -> tm_hour);
    str += ":";
    if(curr_tm -> tm_min < 10) str += "0";
    str += to_string(curr_tm -> tm_min);
    str += ":";
    if(curr_tm -> tm_sec < 10) str += "0";
    str += to_string(curr_tm -> tm_sec);
    str += ")\n";
    int a = v.size();
    for(int i=0; i<a; i++) {
        str += productName[v[i].first - 1];
        str += " ";
        str += to_string(v[i].second);
        str += "개\n";
    }
    str += "\n";
    str += "결재 금액 ";
    str += to_string(price);
    str += "원\n";
    str += "누적 ";
    str += str_;
    str += "원";
    str += "\n\n---------------------------------\n";

    ofstream log("log.txt", ios::app);
    log << str;
}

void Log::log2(int price, string product) {
    string str;
    time_t curr_time;
    struct tm *curr_tm;

    string str_;
    fstream openFile;

    openFile.open("sales.txt");
    getline(openFile, str_);
    openFile.close();

    curr_time = time(NULL);
    curr_tm = localtime(&curr_time);

    str += "\n(";
    str += to_string(curr_tm -> tm_year + 1900);
    str += "-";
    if(curr_tm -> tm_mon + 1 < 10) str += "0";
    str += to_string(curr_tm -> tm_mon + 1);
    str += "-";
    if(curr_tm -> tm_mday < 10) str += "0";
    str += to_string(curr_tm -> tm_mday);
    str += "T";
    if(curr_tm -> tm_hour < 10) str += "0";
    str += to_string(curr_tm -> tm_hour);
    str += ":";
    if(curr_tm -> tm_min < 10) str += "0";
    str += to_string(curr_tm -> tm_min);
    str += ":";
    if(curr_tm -> tm_sec < 10) str += "0";
    str += to_string(curr_tm -> tm_sec);
    str += ")\n";
    str += product;
    str += "\n";
    str += "결재 금액 ";
    str += to_string(price);
    str += "원\n";
    str += "누적 ";
    str += str_;
    str += "원";
    str += "\n\n---------------------------------\n";

    ofstream log("log.txt", ios::app);
    log << str;
}